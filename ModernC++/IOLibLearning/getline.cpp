//#include <iostream>
//#include <string>
//
//int main(int argc, char *argv[])
//{
//#if 0
//    std::string str;
//    while (std::getline(std::cin, str), !std::cin.eof()) {
//        if (std::cin.bad()) {
//            throw std::runtime_error("cin is corrupted.");
//        }
//
//        std::cout << "str:" << str << std::endl;
//    }
//#else
//    char c;
//    while (std::cin.get(c), !std::cin.eof()) {
//        if (std::cin.bad()) {
//            throw std::runtime_error("cin is corrupted.");
//        }
//
//        std::cout << "c:" << c << std::endl;
//    }
//#endif
//
//    return 0;
//}