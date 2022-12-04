//#include <iostream>
//#include <thread>
//#include <mutex>
//
//unsigned g_num = 0;
////定义一个互斥锁
//std::mutex myMutex;
//
//#if 0
//void thread1() {
//    for (int i = 0; i < 1000000; i++) {
//        myMutex.lock();//加锁会导致性能下降，但这也是无奈之举。因为如果逻辑有错误，性能再高也没有意义
//        //应该尽可能少地对逻辑代码加锁
//        ++g_num;
//        myMutex.unlock();
//    }
//}
//
//void thread2() {
//    for (int i = 0; i < 1000000; i++) {
//        myMutex.lock();//如果thread1已经加了锁，这里就会阻塞等到thread1解锁，才会继续执行
//        ++g_num;
//        myMutex.unlock();
//    }
//}
//#else
//void thread1() {
//    for (int i = 0; i < 1000000; i++) {
//        {
//            //离开作用域，lg会被销毁，自动解锁；如果范围无限，同样会引起死锁问题
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