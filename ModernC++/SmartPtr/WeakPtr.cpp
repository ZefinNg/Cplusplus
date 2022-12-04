//#include <iostream>
//#include "vld.h"
//
////shared_ptr其实近乎完美，但是存在循环引用的缺陷；
////weak_ptr的出现就是为了解决这一问题
//
////weak_ptr的对象需要绑定到shared_ptr对象上，作用原理是weak_ptr不会改变shared_ptr对象的引用计数。
////只要shared_ptr对象的引用计数为0，就会释放内存，weak_ptr的对象不会影响释放内存的过程。
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
//    //解决shared_ptr循环引用的问题，将A或B二者之一的成员类型改成weak_ptr
//    std::weak_ptr<B> m_weakB;
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
//    //weak_ptr对象并不会影响shared_ptr对象的引用计数
//    std::shared_ptr<int> sharedI = std::make_shared<int>(100);
//    std::cout << "sharedI 的引用计数：" << sharedI.use_count() << std::endl;
//
//    std::weak_ptr<int> weakI(sharedI);
//    std::cout << "创建weak指针后，sharedI 的引用计数：" << sharedI.use_count() << std::endl;
//    //![1]
//
//    //[2]
//    //将类A的成员修改为weak_ptr类型后，此时便不会再出现循环引用的问题
//    std::shared_ptr<A> sharedA = std::make_shared<A>();
//    std::shared_ptr<B> sharedB = std::make_shared<B>();
//
//    sharedA->m_weakB = sharedB;
//    sharedB->m_sharedA = sharedA;
//    //![2]
//
//    return 0;
//}