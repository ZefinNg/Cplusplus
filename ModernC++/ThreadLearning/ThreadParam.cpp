//#include <iostream>
//#include <thread>
//#include <windows.h>
//
//#if 0
//void test(int i, const int &refI, int *pi) {
//    std::cout << "���̣߳�" << std::endl;
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
//    std::cout << "���̣߳�" << std::endl;
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
//        std::cout << "�߳�ID:" << std::this_thread::get_id() << std::endl;
//    }
//
//    Test(const Test& test) {
//        std::cout << "Test(const Test& test)" << std::endl;
//    }
//
//    int m_i;
//};
//
////������Test�࣬Ӧ�ô������ã����ʹ��ֵ���ݣ�����������������캯��
//void test(Test& test) {
//    std::cout << "���߳�:" << std::this_thread::get_id() << std::endl;
//    test.m_i = 100;
//}
//
//int main(int argc, char *argv[])
//{
//    std::cout << "���߳�:" << std::this_thread::get_id() << std::endl;
//
//    int i = 10;
//#if 0//��ʽת��
//    std::thread myThread(test, i);
//    myThread.detach();
//#else//���ô��ݺ������߳��޸�ֵ
//    Test t(10);
//    std::cout << "t.m_i:" << t.m_i << std::endl;
//    std::thread myTread(test, std::ref(t));
//    myTread.join();
//    //�߳̽�����m_i���޸ĳ���100
//    std::cout << "t.m_i:" << t.m_i << std::endl;
//#endif
//
//    return 0;
//}
//#endif