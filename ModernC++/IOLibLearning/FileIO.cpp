//#include <iostream>
//#include <fstream>
//#include <string>
//#include "vld.h"
//
////实现：读取一个文件内容
////必须熟记
//
//int main(int argc, char *argv[])
//{
//    std::string fileName;
//    std::string fileContent;
//
//    while (std::cin >> fileName, !std::cin.eof()) {
//        if (std::cin.bad()) {
//            throw std::runtime_error("cin is corrupted.");
//        }
//
//        std::ifstream ifs(fileName);
//        if (ifs.is_open()) {
//            while (std::getline(ifs, fileContent)) {
//                std::cout << fileContent << std::endl;
//            }
//
//            if (ifs.bad()) {
//                throw std::runtime_error("ifs is corrupted.");
//            }
//
//            ifs.close();//打开成功必须关闭
//        }
//        else {
//            ifs.clear();//清空状态位
//            ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            std::cout << "file is not exist, please try again." << std::endl;
//            continue;
//        }
//    }
//
//    std::cout << "Process completed." << std::endl;
//
//    return 0;
//}