#include <iostream>
#include <algorithm>
#include <vector>
#include "vld.h"

int main()
{
    //[1]std::adjacent_find：指定范围内查找 2 个连续相等的元素
    std::vector<int> vec1 = {1, 2, 3, 3, 5, 6};

    auto iter1 = std::adjacent_find(vec1.begin(), vec1.end());

    if (iter1 == vec1.end()) {
        std::cout << "Container don't have adjacent element." << std::endl;
    }
    else {
        std::cout << "The element have been found:" << *iter1 << std::endl;
        std::cout << "The distance between begin and element : " << std::distance(vec1.begin(), iter1) << std::endl;
    }

    //[2]
    //重载匹配的逻辑，连续两个元素大于等于2，故找到的是元素2
    auto iter2 = std::adjacent_find(vec1.begin(), vec1.end(), [](int elem1, int elem2) {
        return (elem1 >= 2 && elem2 >= 2);
    });

    if (iter2 == vec1.end()) {
        std::cout << "Container don't have adjacent element that >= 2." << std::endl;
    }
    else {
        std::cout << "The element have been found(>=2):" << *iter2 << std::endl;
        std::cout << "The distance between begin and element : " << std::distance(vec1.begin(), iter1) << std::endl;
    }
    //![2]
    //![1]

    std::cout << "-----------------------------------------------" << std::endl;

    //[3]
    std::vector<int> vec2 = {2, 3, 5, 1, 6, 9, 8};
    std::sort(vec2.begin(), vec2.end());//查找之前必须先排序，注意这里是默认排序
    bool isFind5 = std::binary_search(vec2.begin(), vec2.end(), 5);
    std::cout << "Element 5 was found: " << isFind5 << std::endl;

    //[4]
    //注意：这里必须同样重载排序的函数，否则查找会失败；
    std::sort(vec2.begin(), vec2.end(), [](int elem1, int elem2) {
        return elem1 > elem2;
    });
    //![4]

    //查找比6大的元素：elem1表示vec2的每个元素，elem2表示元素6。这里想要正常查找，区域[4]的代码必不可少，而且重载的方法必须一致
    bool isFind6 = std::binary_search(vec2.begin(), vec2.end(), 6, [](int elem1, int elem2) {
        return elem1 > elem2;
    });

    std::cout << "Element 6 was found: " << isFind6 << std::endl;
    //![3]



    return 0;
}
