//#include <iostream>
//#include <string>
//#include <fstream>
//
//void outputFileContent(const std::string& fileName) {
//    std::ifstream ifs(fileName);
//    std::string fileLineContent;
//    if (ifs.is_open()) {
//        while (ifs >> fileLineContent)
//            std::cout << fileLineContent << std::endl;
//
//        if (ifs.bad()) {
//            throw std::runtime_error("ifs is corrupted.");
//        }
//        ifs.close();
//    }
//    else {
//        if (ifs.bad())
//            throw std::runtime_error("ifs is corrupted.");
//
//        if (ifs.fail())
//            throw std::string("file not exist.");
//    }
//}
//
//int main(int argc, char *argv[])
//{
//    std::string str;
//    std::cin >> str;
//
//    try {
//        outputFileContent(str);
//    }
//    catch (const std::string exception) {
//        std::cout << "exception occers, exception is : " << exception << std::endl;
//    }
//    catch (...) {//捕获其他类型的异常
//        std::cout << "exception occers, exception is : unknown exception." << std::endl;
//    }
//
//    return 0;
//}