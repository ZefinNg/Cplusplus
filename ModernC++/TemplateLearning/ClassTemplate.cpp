#include <iostream>
#include <vector>
#include "vld.h"
#include "MyArray.hpp"

int main_1(int argc, char *argv[])
{
    //vector使用右值进行初始化
    std::vector<int> v1{ 1, 2, 3, 4, 5 };

    //vector也可以使用std::initializer_liat初始化
    std::initializer_list<int> iList = {1, 2, 3, 4, 5};
    std::vector<int> v2(iList);

    //MyVector必须有相应的实现，才可以利用std::initializer_list初始化
    //MyArray<int> myArray{1, 2, 3, 4, 5};

    //[1]这里验证MyArray.hpp的对应代码
    int i1 = 10, i2 = 20, i3 = 30, i4 = 40;
    //注意这里存放的是 int*，将这种情况传给MyArray，会出现浅拷贝的情况(MyArray.hpp中区域[1]的代码)
    std::initializer_list<int*> ptrList{&i1, &i2, &i3, &i4};
    MyArray<int*> myArray(ptrList);

    for (int i = 0; i < ptrList.size(); i++) {
        std::cout << *myArray[i] << std::endl;
    }
    //![1]

    return 0;
}