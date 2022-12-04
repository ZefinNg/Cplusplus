//#include <iostream>
//#include <string>
//#include <vector>
//
//int main(int argc, char *argv[])
//{
//    std::vector<std::shared_ptr<int>> sharedVec;
//    try {
//        //死循环申请内存，模拟new的时候出现异常
//        while (1) {
//#if 0//普通指针
//            int *pi = new int[10000000]();
//#else//智能指针
//            std::unique_ptr<int> uniqueI(new int[10000000]());
//            //假设这里设计失误，因此要将其转为shared_ptr
//            sharedVec.push_back(std::move(uniqueI));
//#endif
//        }
//    }
//    catch (const std::bad_alloc& exception) {
//        std::cout << "exception occers, exception is : " << exception.what() << std::endl;
//    }
//    catch (...) {//捕获其他类型的异常
//        std::cout << "exception occers, exception is : unknown exception." << std::endl;
//    }
//
//    return 0;
//}