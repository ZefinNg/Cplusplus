#include <sstream>
#include <iostream>
#include "vld.h"

int main(int argc, char *argv[])
{
    std::string str("Hello world");
    std::istringstream istrStream(str);
    //得到的是值而不是引用
    std::cout << "istrStream.str(): " << istrStream.str() << std::endl;
    //存储新的字符串
    istrStream.str("Hello");
    std::cout << "istrStream.str(): " << istrStream.str() << std::endl;

    //string 转 int
    std::string strNum("1200");
    std::stringstream strStream(strNum);

    int i = 0;
    strStream >> i;
    if (strStream.bad()) {
        throw std::runtime_error("strStream is corrupted.");
    }
    else if (strStream.fail()) {
        strStream.clear();
        strStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "String format is error." << std::endl;
    }
    else {
        std::cout << "i = " << i << std::endl;
    }

    //int 转 string
    int numI = 100;
    std::stringstream numStrStream;
    numStrStream << numI << std::endl;//std::endl 刷新流

    if (numStrStream.bad()) {
        throw std::runtime_error("numStrStream is corrupted.");
    }
    else {
        std::cout << "numStrStream: " << numStrStream.str() << std::endl;
    }

    //切分字符串
    std::string srcString("Hello world hello world\nhihihi");
    std::string destString;
    std::stringstream srcStream(srcString);

    while (srcStream >> destString) {//读到空格或者\n会终止
        std::cout << destString << std::endl;//根据空格分割成多个字符串
    }

    if (srcStream.bad()) {
        throw std::runtime_error("srcStream is corrupted.");
    }

    return 0;
}