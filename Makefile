# Define Macros here
MAKE = make
MAKECLEAN = make clean
SUBDIR2 = ./ch2/
SUBDIR3 = ./ch3/

subsystem2:
	cd ${SUBDIR2} && ${MAKE}

subsystem3:
	cd ${SUBDIR3} && ${MAKE}

clean:
	-rm -f *.exe
	cd ${SUBDIR2} && ${MAKECLEAN}
	cd ${SUBDIR3} && ${MAKECLEAN}
