#include <iostream>
#include <thread>
#include <mutex>

unsigned g_num = 0;
std::mutex myMutex1;
std::mutex myMutex2;

void thread1() {
    for (int i = 0; i < 1000000; i++) {
        std::lock_guard<std::mutex> lg1(myMutex1);
        //...�����߼�
        std::lock_guard<std::mutex> lg2(myMutex2);
        ++g_num;
    }
}

//����myMutex1��myMutex2����������˳��ͬ
//�ᵼ��thread1��myMutex1�����󣬵ȴ�myMutex2������
//��thread2��myMutex2�����󣬵ȴ�myMutex1������
//�ɴ������̻߳�����ס�Է���Ҫ���������������
//����ķ������ǣ�����������˳��ͳһ��lg1��lg2˳��Ӱ�죩

void thread2() {
    for (int i = 0; i < 1000000; i++) {
#if 0
        std::lock_guard<std::mutex> lg2(myMutex2);
        //...�����߼�
        std::lock_guard<std::mutex> lg1(myMutex1);
#endif
        std::lock_guard<std::mutex> lg1(myMutex1);
        //...�����߼�
        std::lock_guard<std::mutex> lg2(myMutex2);
        ++g_num;
    }
}

void thread3() {
    for (int i = 0; i < 1000000; i++) {
        std::lock(myMutex1, myMutex2);
        //ʹ�� std::adopt_lock ʹlg1ֻ�н������ܣ�û����������
        //�������ִ�е�ĳ���ط��׳��쳣����ʱҪ��;�˳�����ôlg1�ͻ��Զ���������������
        //��lg1��ʱ��Ҳ�������������Կ��Ա������
        std::lock_guard<std::mutex> lg1(myMutex1, std::adopt_lock);
        //...�����߼�
        std::lock_guard<std::mutex> lg2(myMutex2, std::adopt_lock);
        ++g_num;
    }
}

void thread4() {
    for (int i = 0; i < 1000000; i++) {
        std::lock(myMutex1, myMutex2);
        std::lock_guard<std::mutex> lg1(myMutex1, std::adopt_lock);
        //...�����߼�
        std::lock_guard<std::mutex> lg2(myMutex2, std::adopt_lock);
        ++g_num;
    }
}

int main(int argc, char *argv[])
{
    std::thread myThread1(thread1);
    std::thread myThread2(thread2);

    myThread1.join();
    myThread2.join();

    std::cout << "g_num:" << g_num << std::endl;

    std::thread myThread3(thread3);
    std::thread myThread4(thread4);

    myThread3.join();
    myThread4.join();

    std::cout << "g_num:" << g_num << std::endl;
    return 0;
}