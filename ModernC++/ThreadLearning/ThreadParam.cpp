//#include <iostream>
//#include <thread>
//#include <windows.h>
//
//#if 0
//void test(int i, const int &refI, int *pi) {
//    std::cout << "子线程：" << std::endl;
//    std::cout << "i = " << i << std::endl;
//    std::cout << "refI = " << refI << std::endl;
//    std::cout << "&refI = " << &refI << std::endl;
//    std::cout << "*pi = " << *pi << std::endl;
//    std::cout << "pi = " << pi << std::endl;
//}
//
//int main(int argc, char *argv[])
//{
//    int i = 100;
//    std::cout << "主线程：" << std::endl;
//    std::cout << "i = " << i << std::endl;
//    std::cout << "&i = " << &i << std::endl;
//    std::thread myThread(test, i, i, &i);
//#if 0
//    myThread.join();
//#else
//    myThread.detach();
//#endif
//    return 0;
//}
//#else
//class Test {
//public:
//    Test(int i) : m_i(i) {
//        std::cout << "线程ID:" << std::this_thread::get_id() << std::endl;
//    }
//
//    Test(const Test& test) {
//        std::cout << "Test(const Test& test)" << std::endl;
//    }
//
//    int m_i;
//};
//
////这里是Test类，应该传递引用；如果使用值传递，会调用两个拷贝构造函数
//void test(Test& test) {
//    std::cout << "子线程:" << std::this_thread::get_id() << std::endl;
//    test.m_i = 100;
//}
//
//int main(int argc, char *argv[])
//{
//    std::cout << "主线程:" << std::this_thread::get_id() << std::endl;
//
//    int i = 10;
//#if 0//隐式转换
//    std::thread myThread(test, i);
//    myThread.detach();
//#else//引用传递后，在子线程修改值
//    Test t(10);
//    std::cout << "t.m_i:" << t.m_i << std::endl;
//    std::thread myTread(test, std::ref(t));
//    myTread.join();
//    //线程结束后，m_i被修改成了100
//    std::cout << "t.m_i:" << t.m_i << std::endl;
//#endif
//
//    return 0;
//}
//#endif