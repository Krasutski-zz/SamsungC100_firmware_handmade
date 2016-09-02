arm-elf-as.exe -mthumb-interwork -k -EL -W -mcpu=arm7tdmi -o a.obj test_build.asm
arm-elf-ld.exe a.obj --entry=0x400000  -Ttext 0x400000
arm-elf-objcopy.exe -O binary a.out a.bin
bin2mot.exe a.bin file.s /2 /O0x400000 /h
del a.out
del a.obj


loader.exe /f file.s /1
del file.s
pause