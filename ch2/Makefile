# Define Macros here
CC = gcc
CFLAGS = -Wall -g

showBytes.exe: show-bytes.c
	${CC} ${CFLAGS} $? -o $@

isLittleEndian.exe: is-little-endian.c
	${CC} ${CFLAGS} $? -o $@

clean:
	-rm -f -r core core* *.o *exe exe* *dSYM
