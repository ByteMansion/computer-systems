# 程序被其他程序翻译成不同的格式
hello程序的生命周期是从一个高级C语言程序开始的，因为这种形式能够被人读懂。然而，为了在系统上运行hello.c程序，
每条C语句都必须被其他程序转化为一系列的低级机器语言指令。然后这些指令按照一种称为可执行目标程序的格式打好包,
并以二进制磁盘文件的形式存放起来。目标程序也称为可执行目标文件。

在Unix系统上，从源文件到目标文件的转化是由编译器驱动程序完成的：
- unix> gcc -o hello hello.c

在这里，GCC编译器驱动程序读取源程序文件hello.c，并把它翻译成一个可执行目标文件hello。这个翻译的过程可分为四个阶段完成，如图所示。
执行这四个阶段
