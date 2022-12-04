//#include <iostream>
//#include <string>
//
//int divide(int divisor, int dividend) {
//    if (dividend == 0) {
//        throw std::string("dividend is zero.");//这里是抛出string类型的异常
//        //throw "dividend is zero.";//这样写，抛出的异常类型是char *;
//    }
//    
//    return divisor / dividend;
//}
//
//void checkInputNum(const std::string &str, int &num) {
//    std::cout << str << std::endl;
//
//    while (std::cin >> num, !std::cin.eof()) {
//        if (std::cin.bad())
//            throw std::runtime_error("cin is corrupted.");
//
//        if (std::cin.fail()) {
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            std::cout << "number format error, please input again." << std::endl;
//            continue;
//        }
//        break;
//    }
//}
//
//int main(int argc, char *argv[])
//{
//    int divisor = 0;
//    int dividend = 0;
//
//    checkInputNum("please input divisor:", divisor);
//    checkInputNum("please input dividend:", dividend);
//
//    try {
//        std::cout << "Result : " << divide(divisor, dividend) << std::endl;
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
//
