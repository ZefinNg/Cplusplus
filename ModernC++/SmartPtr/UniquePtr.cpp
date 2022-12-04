#include <iostream>
#include <memory>
#include "vld.h"

//unique_ptr的初始化与shared_ptr类似

void myFunc(std::unique_ptr<int> uniquePtr)
{
    std::shared_ptr<int> sharedptr(std::move(uniquePtr));
    std::cout << __FUNCTION__ << "*sharedptr = " << *sharedptr << std::endl;
}

int main(int argc, char *argv[])
{
    //[1]创建的方式
    std::unique_ptr<int> uniqueA(new int(100));
    //一般更加推荐使用std::make_unique函数创建
    std::unique_ptr<int> uniqueB = std::make_unique<int>(200);
    //![1]

    //[2]unique_ptr禁止复制构造函数，也禁止赋值运算符的重载。否则独占便毫无意义。
    //std::unique_ptr<int> unqueA1(uniqueA);//错误代码
    //std::unique_ptr<int> uniqueB1 = uniqueB;//错误代码
    //![2]

    //[3]unqiue_ptr允许移动构造，移动赋值。
    //移动语义代表之前的对象已经失去了意义，移动操作自然不影响独占的特性
    std::unique_ptr<int> uniqueC = std::move(uniqueA);//移动后，uniqueA就废弃了，此时被uniqueC独占，并不冲突
    uniqueB = std::move(uniqueC);//uniqueB自己原有的内存被释放，uniqueC也被释放，uniqueC所占的内存转给了uniqueB
    std::cout << *uniqueB << std::endl;
    //![3]

    //[4]reset()函数：
    //不带参数的情况下：释放智能指针的对象，并将智能指针置空
    std::unique_ptr<int> uniqueD = std::make_unique<int>(300);
    uniqueD.reset();

    //带参数的情况下：释放智能指针的对象，并将智能指针指向新的对象
    std::unique_ptr<int> uniqueE = std::make_unique<int>(400);
    uniqueE.reset(new int(500));//直接指向一个新的堆内存
    //![4]

    //[5]unique_ptr对象转为shared_ptr对象：unique_ptr的对象为一个右值时，就可以将该对象转化为shared_ptr的对象
    //这个使用的并不多，需要将独占式指针转化为共享式指针常常是因为先前设计失误
    //注意：shared_ptr对象无法转化为unique_ptr对象
    std::unique_ptr<int> uniqueF = std::make_unique<int>(200);
    myFunc(std::move(uniqueF));
    //![5]

    return 0;
}