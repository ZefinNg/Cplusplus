//#include <iostream>
//#include "vld.h"
//#include <memory>//智能指针头文件
//
////重点：智能指针与裸指针不要混用！！！
//
//void myFunc(std::shared_ptr<int> sharePtr)
//{
//    std::cout << __FUNCTION__ << " *sharePtr = " << *sharePtr << std::endl;
//}
//
//int main()
//{
//    //[0]
//    //智能指针的原理：
//    //智能指针其实就是对一个普通指针的封装；
//    //当有一个对象使用这块内存时，智能指针内部的引用计数+1；
//    //这些对象创建在栈上，当对象被销毁时，直到引用计数归0；
//    //则会释放这块内存，因此可以自动管理而无需开发人员手动释放
//    //![0]
//    
//    //[1]
//    //这是创建智能指针的一种方式
//    //但是一般不推荐使用new进行初始化，C++标准专门提供了
//    //创建shared_ptr的函数“make_ptr”，该函数经过优化，效率更高
//    std::shared_ptr<int> sharedI(new int(100));
//
//    std::shared_ptr<int> sharedJ = std::make_shared<int>(100);
//    //![1]
//
//    std::cout << "-----------------------------------------" << std::endl;
//
//    //[2]
//    //这是利用裸指针初始化智能指针，也是一种方式，但不推荐，非常容易造成内存泄漏
//    int *pi = new int(100);
//    std::shared_ptr<int> sharedK(pi);
//
//    //如果在这里delete了pi，那么就会造成重复释放的问题
//    //delete pi;//错误代码
//    //![2]
//
//    //[4]智能指针引用计数
//    //[3]
//    //可以使用拷贝构造函数初始化智能指针
//    std::shared_ptr<int> sharedM = std::make_shared<int>(1000);
//    std::cout << "sharedM 当前的引用数量：" << sharedM.use_count() << std::endl;
//    std::shared_ptr<int> sharedN(sharedM);
//    std::cout << "sharedN 当前的引用数量：" << sharedN.use_count() << std::endl;
//    sharedM.reset();//reset了sharedM的话，则整块内存完全释放，sharedN也不能使用；如果只是reset了sharedN的话，sharedM依然存在
//    std::cout << "reset后，sharedM 当前的引用数量：" << sharedM.use_count() << std::endl;
//    //![3]
//    //![4]
//
//    std::cout << "-----------------------------------------" << std::endl;
//
//    //[5]
//    //shared_ptr早已对各种操作进行了重载
//    //可以将它当做普通指针一样使用
//    std::cout << "*shareI = " << *sharedI << std::endl;
//    //![5]
//
//    std::cout << "-----------------------------------------" << std::endl;
//
//    //[6]智能指针常用的函数 unique()：判断指针是否独占
//    std::cout << "shareI 是否独占：" << sharedI.unique() << std::endl;
//    std::cout << "shareJ 是否独占：" << sharedJ.unique() << std::endl;
//
//    std::shared_ptr<int> sharedI2(sharedI);
//
//    std::cout << "std::shared_ptr<int> sharedI2(sharedI);后" << std::endl;
//    std::cout << "shareI 是否独占：" << sharedI.unique() << std::endl;
//    std::cout << "sharedI2 是否独占:" << sharedI2.unique() << std::endl;
//
//    sharedI2.reset();
//
//    std::cout << "sharedI2 reset后" << std::endl;
//    std::cout << "shareI 是否独占：" << sharedI.unique() << std::endl;
//    std::cout << "sharedI2 是否独占:" << sharedI2.unique() << std::endl;
//    //![6]
//
//    std::cout << "-----------------------------------------" << std::endl;
//
//    //[7]智能指针常用的函数 reset()：有参数时，可以改变对象指向的内存；没有参数时，将该对象置空，即指向nullptr；
//    std::shared_ptr<int> sharedA = std::make_shared<int>(200);
//
//    std::cout << "*sharedA = " << *sharedA << std::endl;
//
//    sharedA.reset(new int(150));//sharedA已经是智能指针了，所以reset直接指向新的内存地址即可。如果要指向其他智能指针的内存，直接赋值即可
//
//    std::cout << "reset后 *sharedA = " << *sharedA << std::endl;
//
//    sharedA = sharedI;
//
//    std::cout << "sharedA = sharedI后 *sharedA = " << *sharedA << std::endl;
//    //reset()最常用的还是用于将对象置空
//    //![7]
//
//    std::cout << "-----------------------------------------" << std::endl;
//
//    //[8]智能指针常用的函数 get()：获取智能指针的原始指针（即裸指针）。
//    //**强烈不推荐使用！！！实在没办法需要调用裸指针时才可以使用，但不应该手动delete它！**
//    //delete sharedI.get();//错误代码：这里delete会导致重复释放
//    //![8]
//
//    //[9]智能指针常用的函数 swap()：交换两个智能指针所指向的内存，比较常用
//    std::shared_ptr<int> sharedB1 = std::make_shared<int>(150);
//    std::shared_ptr<int> sharedB2 = std::make_shared<int>(20);
//
//    std::cout << "*sharedB1 = " << *sharedB1 << std::endl;
//    std::cout << "*sharedB2 = " << *sharedB2 << std::endl;
//    
//    sharedB1.swap(sharedB2);
//
//    std::cout << "sharedB1.swap(sharedB2)后：" << std::endl;
//    std::cout << "*sharedB1 = " << *sharedB1 << std::endl;
//    std::cout << "*sharedB2 = " << *sharedB2 << std::endl;
//
//    //也可以用std命名空间提供是swap()函数，比较少用
//    std::swap(sharedB1, sharedB2);
//
//    std::cout << "std::swap(sharedB1, sharedB2)后：" << std::endl;
//    std::cout << "*sharedB1 = " << *sharedB1 << std::endl;
//    std::cout << "*sharedB2 = " << *sharedB2 << std::endl;
//    //![9]
//
//    std::cout << "-----------------------------------------" << std::endl;
//
//    //[10]使用智能指针创建数组
//    std::shared_ptr<int> sharedArray(new int[100]());
//    //此时如果再想像普通指针那样使用，是不行的
//    //std::cout << sharedArray[10] << std::endl;//错误代码，除非使用下面的方法
//    std::cout << "sharedArray.get()[10] = " << sharedArray.get()[10] << std::endl;
//    //![10]
//
//    std::cout << "-----------------------------------------" << std::endl;
//
//    //[11]用智能指针作为参数传递时直接值传递就可以了
//    std::shared_ptr<int> sharedC = std::make_shared<int>(300);
//    myFunc(sharedC);
//    //![11]
//
//    std::cout << "-----------------------------------------" << std::endl;
//
//    //[12]智能指针的大小
//    //shared_ptr的大小为固定的8或16字节；
//    //也就是两倍指针的的大小，32位系统中指针大小为4个字节，64位系统中指针大小为8个字节，shared_ptr中含有2个指针
//    std::cout << "sizeof(sharedC) = " << sizeof(sharedC) << std::endl;
//    //![12]
//
//    return 0;
//}
