# Define Macros here
MAKE = make
MAKECLEAN = make clean
SUBDIR2 = ./ch2/

subsystem:
	cd ${SUBDIR2} && ${MAKE}

clean:
	-rm -f *.exe
	cd ${SUBDIR2} && ${MAKECLEAN}
