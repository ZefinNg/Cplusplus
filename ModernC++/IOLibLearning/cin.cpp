//#include <iostream>
//#include "vld.h"
//
//int main()
//{
//    //[1]标准的cin代码，必须熟记
//    int i = 0;
//    //使用逗号运算符，cin到i后，再判断输入是否达到文件末尾eof
//    while (std::cin >> i, !std::cin.eof()) {
//        //系统级错误
//        if (std::cin.bad()) {
//            throw std::runtime_error("cin is corrupted.");
//        }
//
//        //格式错误(可恢复错误)
//        if (std::cin.fail()) {
//            std::cin.clear();//将流状态设置为正常：good()状态
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//对流进行检测直到检查到'\n'，将这段数据丢弃
//            std::cout << "data format error, please try again." << std::endl;
//            continue;
//        }
//        std::cout << i << std::endl;
//    }
//
//    std::cout << "process completed." << std::endl;
//    //![1]
//
//    return 0;
//}
