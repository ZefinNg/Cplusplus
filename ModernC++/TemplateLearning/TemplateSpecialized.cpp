#include <iostream>
#include <vector>
#include <functional>
#include "vld.h"

//全特化：指定所有类型
//半特化：指定部分类型

template<typename T1, typename T2>
class Test
{
public:
    Test() {
        std::cout << "Common template." << std::endl;
    }
};

template<typename T1, typename T2>
class Test<T1*, T2*>
{
public:
    Test() {
        std::cout << "Point semi-special." << std::endl;
    }
};

template<typename T2>
class Test<int, T2>
{
public:
    Test() {
        std::cout << "int semi-special." << std::endl;
    }
};

template<>
class Test<int, int>
{
public:
    Test() {
        std::cout << "int, int semi-special." << std::endl;
    }
};

int main(int argc, char *argv[])
{
    Test<int*, int*> test1;
    Test<int, double> test2;
    Test<int, int> test3;
    Test<int*, int> test4;

    return 0;
}