obj-m += cats.o #tells makefile this is a kernel module

install: #install function to make module
	make -C /lib/modules/`uname -r`/build M=`pwd`

init: #init function initializes the function
	make install && insmod cats.ko

clean: #clean function removes module
	rmmod cats.ko

flash: #flash function, which makes init and rmmod, then echos flashed
	make init && rmmod cats.ko
	echo flashed :\) 
