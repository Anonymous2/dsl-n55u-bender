cmd_kernel/time/built-in.o :=  /opt/buildroot-gcc342/bin/mipsel-linux-uclibc-ld  -m elf32ltsmip  -r -o kernel/time/built-in.o kernel/time/timekeeping.o kernel/time/ntp.o kernel/time/clocksource.o kernel/time/jiffies.o kernel/time/timer_list.o