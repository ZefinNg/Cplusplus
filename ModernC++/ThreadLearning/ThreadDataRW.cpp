//#include <iostream>
//#include <thread>
//
//unsigned g_num = 0;
//
//void thread1() {
//    for (int i = 0; i < 1000000; i++)
//        ++g_num;
//}
//
//void thread2() {
//    for (int i = 0; i < 1000000; i++)
//        ++g_num;
//}
//
//int main(int argc, char *argv[])
//{
//    //�����߳�������˳���ǡ����ҵġ�
//    std::thread myThread1(thread1);
//    std::thread myThread2(thread2);
//
//    myThread1.join();
//    myThread2.join();
//
//    //��ӡ�ᷢ��g_num�ܴ�����޷��ﵽ2000000
//    std::cout << "g_num:" << g_num << std::endl;
//    return 0;
//}