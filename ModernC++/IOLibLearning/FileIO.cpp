//#include <iostream>
//#include <fstream>
//#include <string>
//#include "vld.h"
//
////ʵ�֣���ȡһ���ļ�����
////�������
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
//            ifs.close();//�򿪳ɹ�����ر�
//        }
//        else {
//            ifs.clear();//���״̬λ
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