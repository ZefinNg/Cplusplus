//#include <iostream>
//#include <thread>
//#include <windows.h>
//
//int main(int argc, char *argv[])
//{
//    std::thread myThread([]() {
//        for (int i = 0; i < 1000; i++) {
//            std::cout << "Hello world." << std::endl;
//            Sleep(500);
//        }
//    });
//
//#if 0
//    //等待子线程执行完毕
//    myThread.join();
//#else
//    //子线程完全分离
//    myThread.detach();
//
//    Sleep(10000);
//#endif
//
//    return 0;
//}