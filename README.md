<<<<<<< HEAD
# Uthreads
实现用户级别的uthread库，,使用C语言编写，充分利用了Linux提供的系统调用，可以创建、管理和同步线程。通过此项目的练习，加深对操作系统知识的理解，学习了多线程调试的方法
=======
# uthread

uthreads  介绍
uthreads 是一个用户级线程库，与 pthreads 接口大致类似。这个线程库的功能包括线程的创建，线程可以是 joined 或 detached，一个简单基于优先级的调度器，互斥锁和条件变量。你需要写 uthreads 代码的主要部分，但我已经把这个线程库的骨架部分写好了，你只需要写uthread的关键部分。

软件架构说明
编译生成一个动态链接库和一个测试程序


编译完整的线程库以及测试程序：
make
查看需要实现的函数或代码：
make nyi
编译测试程序，使用项目中给定的链接库（主要用于查看正确的运行结果）：
gcc test.c -luthread -o test
不使用链接库方式，将所有代码编译为一个可执行文件（这并不是提交代码的正确方式，仅用于方便调试）：
gcc *.c -o test

>>>>>>> 3209956 (Initialize and upload old files that are already finished)
