#include <sstream>
#include <iostream>
#include "vld.h"

int main(int argc, char *argv[])
{
    std::string str("Hello world");
    std::istringstream istrStream(str);
    //�õ�����ֵ����������
    std::cout << "istrStream.str(): " << istrStream.str() << std::endl;
    //�洢�µ��ַ���
    istrStream.str("Hello");
    std::cout << "istrStream.str(): " << istrStream.str() << std::endl;

    //string ת int
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

    //int ת string
    int numI = 100;
    std::stringstream numStrStream;
    numStrStream << numI << std::endl;//std::endl ˢ����

    if (numStrStream.bad()) {
        throw std::runtime_error("numStrStream is corrupted.");
    }
    else {
        std::cout << "numStrStream: " << numStrStream.str() << std::endl;
    }

    //�з��ַ���
    std::string srcString("Hello world hello world\nhihihi");
    std::string destString;
    std::stringstream srcStream(srcString);

    while (srcStream >> destString) {//�����ո����\n����ֹ
        std::cout << destString << std::endl;//���ݿո�ָ�ɶ���ַ���
    }

    if (srcStream.bad()) {
        throw std::runtime_error("srcStream is corrupted.");
    }

    return 0;
}