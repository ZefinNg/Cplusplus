//#include <iostream>
//#include <vector>
//#include <functional>
//#include "vld.h"
//
////[1]
//template<typename T>
//void test(const T& parm)
//{
//    std::cout << "void test(const T& parm)" << std::endl;
//}
////![1]
//
////[2]、[3]两个函数是对[1]的特化处理
////[2]
//template<typename T>
//void test(const T* parm)
//{
//    std::cout << "void test(T* parm)" << std::endl;
//}
////![2]
//
////[3]
//void test(double parm)
//{
//    std::cout << "void test(double parm)" << std::endl;
//}
////![3]
//
//int main(int argc, char *argv[])
//{
//    int i = 100;
//    test(i);//[1]
//
//    int j = 200;
//    test(&j);//[2]
//
//    test(2.2);//[3]
//
//    return 0;
//}