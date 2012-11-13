rm *.elf32
xenon-objcopy -O elf32-powerpc --adjust-vma 0x80000000 ~/Desktop/exult/exult ~/Desktop/exult/exult.elf32
xenon-strip exult.elf32
cp -f *.elf32 /srv/tftp
