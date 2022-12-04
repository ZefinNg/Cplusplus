//#include <iostream>
//#include "vld.h"
//
////shared_ptr存在一个问题：循环引用
//
//class A;
//class B;
//
//class A {
//public:
//    A() {
//        std::cout << "A 构造函数。" << std::endl;
//    }
//
//    ~A() {
//        std::cout << "A 析构函数。" << std::endl;
//    }
//
//    std::shared_ptr<B> m_sharedB;
//};
//
//class B {
//public:
//    B() {
//        std::cout << "B 构造函数。" << std::endl;
//    }
//
//    ~B() {
//        std::cout << "B 析构函数。" << std::endl;
//    }
//
//    std::shared_ptr<A> m_sharedA;
//};
//
//int main(int argc, char *argv[])
//{
//    //[1]
//    //运行后可以发现vld检测出内存泄漏，A、B的析构函数均没有正常调用；
//    std::shared_ptr<A> sharedA = std::make_shared<A>();
//    std::shared_ptr<B> sharedB = std::make_shared<B>();
//
//    //sharedA、sharedB的成员互相指向了对方，此时各自堆内存的引用计数为2；
//    sharedA->m_sharedB = sharedB;
//    sharedB->m_sharedA = sharedA;
//    
//    //main函数运行结束，栈进行销毁时，sharedA被销毁，A的引用计数-1，此时A的堆内存引用计数依然为1，因为sharedB的成员还指向着A；
//    //因此A的析构函数并不会被执行，因为此时确实还有B的成员指向着它（引用计数为0时，就会调用析构，但此时引用计数为1）。
//    //sharedB的情况也如此，类似于死锁。
//    //因此整个函数运行结束后，类A、类B的析构函数都没有被调用，导致出现了内存泄漏。
//    //![1]
//
//    //[2]规避方法一：
//    //如果没有出现互相指向，仅是一方的成员指向了另一方，那么也可以正常释放
//    //即把行43或行44而者之一注释掉（注意，栈的释放顺序是反的，先释放sharedB，再释放sharedA）
//    //![2]
//
//    //[3]规避方法二：
//    //如果在退出时，sharedB自己销毁了成员的指向，那么就不会出现互相指向导致“死锁”的问题
//    sharedB->m_sharedA.reset();
//    //![3]
//
//    //[4]规避方法三：其中一个类使用weak_ptr指针
//    //![4]
//
//    return 0;
//}