//#include <iostream>
//#include <thread>
//#include <mutex>
//
//unsigned g_num = 0;
////����һ��������
//std::mutex myMutex;
//
//#if 0
//void thread1() {
//    for (int i = 0; i < 1000000; i++) {
//        myMutex.lock();//�����ᵼ�������½�������Ҳ������֮�١���Ϊ����߼��д��������ٸ�Ҳû������
//        //Ӧ�þ������ٵض��߼��������
//        ++g_num;
//        myMutex.unlock();
//    }
//}
//
//void thread2() {
//    for (int i = 0; i < 1000000; i++) {
//        myMutex.lock();//���thread1�Ѿ�������������ͻ������ȵ�thread1�������Ż����ִ��
//        ++g_num;
//        myMutex.unlock();
//    }
//}
//#else
//void thread1() {
//    for (int i = 0; i < 1000000; i++) {
//        {
//            //�뿪������lg�ᱻ���٣��Զ������������Χ���ޣ�ͬ����������������
//            std::lock_guard<std::mutex> lg(myMutex);
//            ++g_num;
//        }
//    }
//}
//
//void thread2() {
//    for (int i = 0; i < 1000000; i++) {
//        {
//            std::lock_guard<std::mutex> lg(myMutex);
//            ++g_num;
//        }
//    }
//}
//#endif
//
//int main(int argc, char *argv[])
//{
//    std::thread myThread1(thread1);
//    std::thread myThread2(thread2);
//
//    myThread1.join();
//    myThread2.join();
//
//    std::cout << "g_num:" << g_num << std::endl;
//    return 0;
//}