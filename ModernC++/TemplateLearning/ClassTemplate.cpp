#include <iostream>
#include <vector>
#include "vld.h"
#include "MyArray.hpp"

int main_1(int argc, char *argv[])
{
    //vectorʹ����ֵ���г�ʼ��
    std::vector<int> v1{ 1, 2, 3, 4, 5 };

    //vectorҲ����ʹ��std::initializer_liat��ʼ��
    std::initializer_list<int> iList = {1, 2, 3, 4, 5};
    std::vector<int> v2(iList);

    //MyVector��������Ӧ��ʵ�֣��ſ�������std::initializer_list��ʼ��
    //MyArray<int> myArray{1, 2, 3, 4, 5};

    //[1]������֤MyArray.hpp�Ķ�Ӧ����
    int i1 = 10, i2 = 20, i3 = 30, i4 = 40;
    //ע�������ŵ��� int*���������������MyArray�������ǳ���������(MyArray.hpp������[1]�Ĵ���)
    std::initializer_list<int*> ptrList{&i1, &i2, &i3, &i4};
    MyArray<int*> myArray(ptrList);

    for (int i = 0; i < ptrList.size(); i++) {
        std::cout << *myArray[i] << std::endl;
    }
    //![1]

    return 0;
}