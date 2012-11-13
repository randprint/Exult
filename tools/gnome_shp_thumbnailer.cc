/**
 **	gnome_shp_thumbnailer.cc - Create thumbnails for shp files in Nautilus.
 **
 **	Written: 2/14/2010 - Marzo, with lots of code borrowed from ipack and from
 ** the Gimp plugin.
 **/

/*
 *	Copyright (C) 2010	The Exult Team
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <libgnomeui/libgnomeui.h>
#include <iostream>
#include <cstdlib>
#include "Flex.h"
#include "utils.h"
#include "exceptions.h"
#include "vgafile.h"
#include "pngio.h"
#include "ibuf8.h"

using namespace std;

// From Gimp plug-in. We use this single palette because the thumbnailer
// is meant to run unattended.
// TODO: Maybe expand to RGBA and use translucent colors instead of the
// more "normal" cycling colors. This causes to some thumbnails to look
// better, but others to look worse; most shapes are unaffected.
// The values used for the OpenGL translucent pixels in shapeid.cc (also
// in the blends.dat files for BG and SI) could be used for this purpose.
static unsigned char shppal[768] = {
	0x00, 0x00, 0x00, 0xF8, 0xF0, 0xCC, 0xF4, 0xE4, 0xA4, 0xF0, 0xDC, 0x78, 
	0xEC, 0xD0, 0x50, 0xEC, 0xC8, 0x28, 0xD8, 0xAC, 0x20, 0xC4, 0x94, 0x18, 
	0xB0, 0x80, 0x10, 0x9C, 0x68, 0x0C, 0x88, 0x54, 0x08, 0x74, 0x44, 0x04, 
	0x60, 0x30, 0x00, 0x4C, 0x24, 0x00, 0x38, 0x14, 0x00, 0xF8, 0xFC, 0xFC, 
	0xFC, 0xD8, 0xD8, 0xFC, 0xB8, 0xB8, 0xFC, 0x98, 0x9C, 0xFC, 0x78, 0x80, 
	0xFC, 0x58, 0x64, 0xFC, 0x38, 0x4C, 0xFC, 0x1C, 0x34, 0xDC, 0x14, 0x28, 
	0xC0, 0x0C, 0x1C, 0xA4, 0x08, 0x14, 0x88, 0x04, 0x0C, 0x6C, 0x00, 0x04, 
	0x50, 0x00, 0x00, 0x34, 0x00, 0x00, 0x18, 0x00, 0x00, 0xFC, 0xEC, 0xD8, 
	0xFC, 0xDC, 0xB8, 0xFC, 0xCC, 0x98, 0xFC, 0xBC, 0x7C, 0xFC, 0xAC, 0x5C, 
	0xFC, 0x9C, 0x3C, 0xFC, 0x8C, 0x1C, 0xFC, 0x7C, 0x00, 0xE0, 0x6C, 0x00, 
	0xC0, 0x60, 0x00, 0xA4, 0x50, 0x00, 0x88, 0x44, 0x00, 0x6C, 0x34, 0x00, 
	0x50, 0x24, 0x00, 0x34, 0x18, 0x00, 0x18, 0x08, 0x00, 0xFC, 0xFC, 0xD8, 
	0xF4, 0xF4, 0x9C, 0xEC, 0xEC, 0x60, 0xE4, 0xE4, 0x2C, 0xDC, 0xDC, 0x00, 
	0xC0, 0xC0, 0x00, 0xA4, 0xA4, 0x00, 0x88, 0x88, 0x00, 0x6C, 0x6C, 0x00, 
	0x50, 0x50, 0x00, 0x34, 0x34, 0x00, 0x18, 0x18, 0x00, 0xD8, 0xFC, 0xD8, 
	0xB0, 0xFC, 0xAC, 0x8C, 0xFC, 0x80, 0x6C, 0xFC, 0x54, 0x50, 0xFC, 0x28, 
	0x38, 0xFC, 0x00, 0x28, 0xDC, 0x00, 0x1C, 0xC0, 0x00, 0x14, 0xA4, 0x00, 
	0x0C, 0x88, 0x00, 0x04, 0x6C, 0x00, 0x00, 0x50, 0x00, 0x00, 0x34, 0x00, 
	0x00, 0x18, 0x00, 0xD4, 0xD8, 0xFC, 0xB8, 0xB8, 0xFC, 0x98, 0x98, 0xFC, 
	0x7C, 0x7C, 0xFC, 0x5C, 0x5C, 0xFC, 0x3C, 0x3C, 0xFC, 0x00, 0x00, 0xFC, 
	0x00, 0x00, 0xE0, 0x00, 0x00, 0xC0, 0x00, 0x00, 0xA4, 0x00, 0x00, 0x88, 
	0x00, 0x00, 0x6C, 0x00, 0x00, 0x50, 0x00, 0x00, 0x34, 0x00, 0x00, 0x18, 
	0xE8, 0xC8, 0xE8, 0xD4, 0x98, 0xD4, 0xC4, 0x6C, 0xC4, 0xB0, 0x48, 0xB0, 
	0xA0, 0x28, 0xA0, 0x8C, 0x10, 0x8C, 0x7C, 0x00, 0x7C, 0x6C, 0x00, 0x6C, 
	0x60, 0x00, 0x60, 0x50, 0x00, 0x50, 0x44, 0x00, 0x44, 0x34, 0x00, 0x34, 
	0x24, 0x00, 0x24, 0x18, 0x00, 0x18, 0xF4, 0xE8, 0xE4, 0xEC, 0xDC, 0xD4, 
	0xE4, 0xCC, 0xC0, 0xE0, 0xC0, 0xB0, 0xD8, 0xB0, 0xA0, 0xD0, 0xA4, 0x90, 
	0xC8, 0x98, 0x80, 0xC4, 0x8C, 0x74, 0xAC, 0x7C, 0x64, 0x98, 0x6C, 0x58, 
	0x80, 0x5C, 0x4C, 0x6C, 0x4C, 0x3C, 0x54, 0x3C, 0x30, 0x3C, 0x2C, 0x24, 
	0x28, 0x1C, 0x14, 0x10, 0x0C, 0x08, 0xEC, 0xEC, 0xEC, 0xDC, 0xDC, 0xDC, 
	0xCC, 0xCC, 0xCC, 0xBC, 0xBC, 0xBC, 0xAC, 0xAC, 0xAC, 0x9C, 0x9C, 0x9C, 
	0x8C, 0x8C, 0x8C, 0x7C, 0x7C, 0x7C, 0x6C, 0x6C, 0x6C, 0x60, 0x60, 0x60, 
	0x50, 0x50, 0x50, 0x44, 0x44, 0x44, 0x34, 0x34, 0x34, 0x24, 0x24, 0x24, 
	0x18, 0x18, 0x18, 0x08, 0x08, 0x08, 0xE8, 0xE0, 0xD4, 0xD8, 0xC8, 0xB0, 
	0xC8, 0xB0, 0x90, 0xB8, 0x98, 0x70, 0xA8, 0x84, 0x58, 0x98, 0x70, 0x40, 
	0x88, 0x5C, 0x2C, 0x7C, 0x4C, 0x18, 0x6C, 0x3C, 0x0C, 0x5C, 0x34, 0x0C, 
	0x4C, 0x2C, 0x0C, 0x3C, 0x24, 0x0C, 0x2C, 0x1C, 0x08, 0x20, 0x14, 0x08, 
	0xEC, 0xE8, 0xE4, 0xDC, 0xD4, 0xD0, 0xCC, 0xC4, 0xBC, 0xBC, 0xB0, 0xAC, 
	0xAC, 0xA0, 0x98, 0x9C, 0x90, 0x88, 0x8C, 0x80, 0x78, 0x7C, 0x70, 0x68, 
	0x6C, 0x60, 0x5C, 0x60, 0x54, 0x50, 0x50, 0x48, 0x44, 0x44, 0x3C, 0x38, 
	0x34, 0x30, 0x2C, 0x24, 0x20, 0x20, 0x18, 0x14, 0x14, 0xE0, 0xE8, 0xD4, 
	0xC8, 0xD4, 0xB4, 0xB4, 0xC0, 0x98, 0x9C, 0xAC, 0x7C, 0x88, 0x98, 0x60, 
	0x70, 0x84, 0x4C, 0x5C, 0x70, 0x38, 0x4C, 0x5C, 0x28, 0x40, 0x50, 0x20, 
	0x38, 0x44, 0x1C, 0x30, 0x3C, 0x18, 0x28, 0x30, 0x14, 0x20, 0x24, 0x10, 
	0x18, 0x1C, 0x08, 0x0C, 0x10, 0x04, 0xEC, 0xD8, 0xCC, 0xDC, 0xB8, 0xA0, 
	0xCC, 0x98, 0x7C, 0xBC, 0x80, 0x5C, 0xAC, 0x64, 0x3C, 0x9C, 0x50, 0x24, 
	0x8C, 0x3C, 0x0C, 0x7C, 0x2C, 0x00, 0x6C, 0x24, 0x00, 0x60, 0x20, 0x00, 
	0x50, 0x1C, 0x00, 0x44, 0x14, 0x00, 0x34, 0x10, 0x00, 0x24, 0x0C, 0x00, 
	0xF0, 0xF0, 0xFC, 0xE4, 0xE4, 0xFC, 0xD8, 0xD8, 0xFC, 0xCC, 0xCC, 0xFC, 
	0xC0, 0xC0, 0xFC, 0xB4, 0xB4, 0xFC, 0xA8, 0xA8, 0xFC, 0x9C, 0x9C, 0xFC, 
	0x84, 0xD0, 0x00, 0x84, 0xB0, 0x00, 0x7C, 0x94, 0x00, 0x68, 0x78, 0x00, 
	0x50, 0x58, 0x00, 0x3C, 0x40, 0x00, 0x2C, 0x24, 0x00, 0x1C, 0x08, 0x00, 
	0x20, 0x00, 0x00, 0xEC, 0xD8, 0xC4, 0xDC, 0xC0, 0xB4, 0xCC, 0xB4, 0xA0, 
	0xBC, 0x9C, 0x94, 0xAC, 0x90, 0x80, 0x9C, 0x84, 0x74, 0x8C, 0x74, 0x64, 
	0x7C, 0x64, 0x58, 0x6C, 0x54, 0x4C, 0x60, 0x48, 0x44, 0x50, 0x40, 0x38, 
	0x44, 0x34, 0x2C, 0x34, 0x2C, 0x24, 0x24, 0x18, 0x18, 0x18, 0x10, 0x10, 
	0xFC, 0xF8, 0xFC, 0xAC, 0xD4, 0xF0, 0x70, 0xAC, 0xE4, 0x34, 0x8C, 0xD8, 
	0x00, 0x6C, 0xD0, 0x30, 0x8C, 0xD8, 0x6C, 0xB0, 0xE4, 0xB0, 0xD4, 0xF0, 
	0xFC, 0xFC, 0xF8, 0xFC, 0xEC, 0x40, 0xFC, 0xC0, 0x28, 0xFC, 0x8C, 0x10, 
	0xFC, 0x50, 0x00, 0xC8, 0x38, 0x00, 0x98, 0x28, 0x00, 0x68, 0x18, 0x00, 
	0x7C, 0xDC, 0x7C, 0x44, 0xB4, 0x44, 0x18, 0x90, 0x18, 0x00, 0x6C, 0x00, 
	0xF8, 0xB8, 0xFC, 0xFC, 0x64, 0xEC, 0xFC, 0x00, 0xB4, 0xCC, 0x00, 0x70, 
	0xFC, 0xFC, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFC, 0x00, 0xFC, 0x00, 0x00, 
	0xFC, 0xFC, 0xFC, 0x61, 0x61, 0x61, 0xC0, 0xC0, 0xC0, 0xFC, 0x00, 0xF1 };

// Finds the integer square root of a positive number of any type.
// This is utter overkill...
template <typename type>
type intSqrt (type remainder)
	{
	if (remainder < 0) // if type is unsigned this will be ignored = no runtime
		return 0; // negative number ERROR

	type place = (type)1 << (sizeof (type) * 8 - 2); // calculated by precompiler = same runtime as: place = 0x40000000
	while (place > remainder)
		place /= 4; // optimized by complier as place >>= 2

	type root = 0;
	while (place)
	{
		if (remainder >= root+place)
		{
			remainder -= root+place;
			root += place * 2;
		}
		root /= 2;
		place /= 4;
	}
	return root;
	}

const unsigned char transp = 255;	// Transparent pixel.

static unsigned char *Convert8to32
	(
	unsigned char *bits,
	size_t nsize,
	unsigned char *palette
	)
	{
	unsigned char *out = new unsigned char[nsize*4];
	for (size_t i = 0; i < nsize; i++)
		{
		size_t pix = bits[i];
		out[4 * i    ] = palette[3 * pix    ];
		out[4 * i + 1] = palette[3 * pix + 1];
		out[4 * i + 2] = palette[3 * pix + 2];
		out[4 * i + 3] = pix == transp ? 0 : 255;
		}
	return out;
	}

/*
 *	Single frame renderer.
 */
struct Render_frame
	{
	void operator()
		(
		Image_buffer8& img,
		Shape_frame *frame,
		int w, int h,
		int xo, int yo
		)
		{
		frame->paint(&img, xo + frame->get_xleft(), yo + frame->get_yabove());
		}
	};

/*
 *	Shape tile renderer.
 */
struct Render_tiles
	{
	void operator()
		(
		Image_buffer8& img,
		Shape *shape,
		int w, int h,
		int xo, int yo
		)
		{
		int nframes = shape->get_num_frames();
		int dim0_cnt = w/8;
		for (int f = 0; f < nframes; f++)
			{
			Shape_frame *frame = shape->get_frame(f);
			if (!frame)
				continue;	// We'll just leave empty ones blank.
			if (!frame->is_rle() || frame->get_width() != 8 ||
						frame->get_height() != 8)
				{
				cerr << "Can only tile 8x8 flat shapes, but shape doesn't qualify" << endl;
				exit(4);
				}
			int x = f%dim0_cnt, y = f/dim0_cnt;
			frame->paint(&img, xo + x*8 + frame->get_xleft(), 
							yo + y*8 + frame->get_yabove());
			}
		}
	};

/*
 *	Write out the desired data as a .png. Yes, this is overkill :-)
 */

template<typename Data, typename Render>
static void Write_thumbnail
	(
	char *filename,			// Base filename to write.
	Data *data,				// What to write.
	unsigned char *palette,	// 3*256 bytes.
	int w, int h,			// Width, height of rendered image.
	int size				// Desired thumbnail size
	)
	{
	assert(data != 0);
	cout << "Writing " << filename << endl;
	int w1 = w, h1 = h;
	if (w > size || h > size)
		// Make into a padded square of the largest dimension.
		w1 = h1 = w > h ? w : h;
	else
		{
		// Pad it to minimum size to avoid blurring.
		if (w < 16)
			w1 = 16;
		if (h < 16)
			h1 = 16;
		}
	Image_buffer8 img(w1, h1);	// Render into a buffer.
	img.fill8(transp);		// Fill with transparent pixel.
	Render r;
	r(img, data, w, h, (w1 - w)/2, (h1 - h)/2);
	unsigned char *bits = Convert8to32(img.get_bits(), w1 * h1, palette);
	if (w > size || h > size)
		{
		// Use GTHUMB scaler to reduce large image.
		// These few lines are all that create dependencies on gdk-pixbuf and
		// libgnomeui.
		GdkPixbuf *pixbuf = gdk_pixbuf_new_from_data(bits, GDK_COLORSPACE_RGB,
					true, 8, w1, h1, 4 * w1, NULL, NULL);
		GdkPixbuf *smallpixbuf = gnome_thumbnail_scale_down_pixbuf(pixbuf,
					size, size);
			// Write out to the .png.
		if (!Export_png32(filename, size, size, 4 * size, 0, 0,
					gdk_pixbuf_get_pixels(smallpixbuf)))
			throw file_write_exception(filename);
		g_object_unref(smallpixbuf);
		g_object_unref(pixbuf);
		}
		// Write out to the .png.
	else if (!Export_png32(filename, w1, h1, 4 * w1, 0, 0, bits))
		throw file_write_exception(filename);
	delete [] bits;
	}

int main(int argc, char *argv[])
	{
	if (argc < 5)
		{
		cerr << "Usage: gnome-shp-thumbnailer -s size inputfile outputfile" << endl;
		return 1;
		}
	gtk_init(&argc, &argv);
	int  size = atoi(argv[2]);
	char *inputfile	= argv[3];
	char *outputfile = argv[4];
	Shape_file shape(inputfile);	// May throw an exception.
	int nframes = shape.get_num_frames();
	if (nframes == 0)
		{
		cerr << "Shape is empty!" << endl;
		return 2;
		}
	Shape_frame *frame0 = shape.get_frame(0);
	if (!frame0)
		{
		cerr << "Null first frame!" << endl;
		return 3;
		}
	if (frame0->is_rle())
		{
		for (int i = 0; i < nframes; i++)
			{
			Shape_frame *frame = shape.get_frame(i);
			if (!frame || frame->is_empty())
				continue;
			Write_thumbnail<Shape_frame, Render_frame>(outputfile, frame, shppal,
						frame->get_width(), frame->get_height(), size);
			break;
			}
		}
	else
		{
		int dim0 = intSqrt(nframes);
		if (dim0*dim0 < nframes)
			dim0 += 1;
		int dim1 = (nframes + dim0 - 1)/dim0;
		Write_thumbnail<Shape, Render_tiles>(outputfile, &shape, shppal,
					dim0*8, dim1*8, size);
		}
	return 0;
	}

