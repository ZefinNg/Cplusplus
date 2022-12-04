#include <iostream>
#include <thread>
#include <mutex>

unsigned g_num = 0;
std::mutex myMutex1;
std::mutex myMutex2;

void thread1() {
    for (int i = 0; i < 1000000; i++) {
        std::lock_guard<std::mutex> lg1(myMutex1);
        //...其他逻辑
        std::lock_guard<std::mutex> lg2(myMutex2);
        ++g_num;
    }
}

//上下myMutex1、myMutex2的上锁解锁顺序不同
//会导致thread1中myMutex1上锁后，等待myMutex2解锁；
//而thread2中myMutex2上锁后，等待myMutex1解锁；
//由此两个线程互相锁住对方需要的锁，造成了死锁
//解决的方法就是，将上锁解锁顺序统一（lg1与lg2顺序不影响）

void thread2() {
    for (int i = 0; i < 1000000; i++) {
#if 0
        std::lock_guard<std::mutex> lg2(myMutex2);
        //...其他逻辑
        std::lock_guard<std::mutex> lg1(myMutex1);
#endif
        std::lock_guard<std::mutex> lg1(myMutex1);
        //...其他逻辑
        std::lock_guard<std::mutex> lg2(myMutex2);
        ++g_num;
    }
}

void thread3() {
    for (int i = 0; i < 1000000; i++) {
        std::lock(myMutex1, myMutex2);
        //使用 std::adopt_lock 使lg1只有解锁功能，没有上锁功能
        //假如代码执行到某个地方抛出异常，此时要中途退出，那么lg1就会自动解锁，而且运行
        //到lg1的时候，也不会上锁，所以可以避免解锁
        std::lock_guard<std::mutex> lg1(myMutex1, std::adopt_lock);
        //...其他逻辑
        std::lock_guard<std::mutex> lg2(myMutex2, std::adopt_lock);
        ++g_num;
    }
}

void thread4() {
    for (int i = 0; i < 1000000; i++) {
        std::lock(myMutex1, myMutex2);
        std::lock_guard<std::mutex> lg1(myMutex1, std::adopt_lock);
        //...其他逻辑
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