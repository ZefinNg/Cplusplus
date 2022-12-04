//#include <iostream>
//#include <vector>
//#include <functional>
//#include "vld.h"
//
//namespace mystd {
//    template<typename iter_type, typename func_type>
//    void for_each(iter_type first, iter_type last, func_type func) {
//        for (auto iter = first; iter != last; ++iter) {
//            func(*iter);
//        }
//    }
//
//    //[1]默认模板参数
//    //默认模板参数和普通函数的默认参数一样，一旦一个参数有了默认参数，它之后的参数都必须有默认参数
//    using func = std::function<void(int&)>;
//
//    //这里的func_type 使用了默认模板参数为 func。
//    template<typename iter_type, typename func_type = func>
//    void forEach(iter_type first, iter_type last, func_type func = [](int& element) {//这里实现了默认模板参数func的逻辑
//        ++element;
//    }) {
//
//        for (auto iter = first; iter != last; ++iter) {
//            func(*iter);
//        }
//    }
//    //![1]
//
//#if 0
//    template<typename T>
//    class MyVector {
//    public:
//        template<typename T2>//这里新增了一个T2类型，是给这个output函数用的
//        void output(const T2& elem);
//    };
//
//    //类外定义，也需要先把T补充上
//    template<typename T>
//    template<typename T2>
//    void MyVector<T>::output(const T2& elem) {
//        std::cout << elem << std::endl;
//    }
//#else//类模板使用默认模板参数，将 allocator_type 默认指定为 std::allocator<T>
//    template<typename T, typename allocator_type = std::allocator<T>>
//    class MyVector {
//    public:
//        template<typename T2>
//        void output(const T2& elem);
//    };
//
//    template<typename T, typename allocator_type>
//    template<typename T2>
//    void MyVector<T, allocator_type>::output(const T2& elem) {
//        std::cout << elem << std::endl;
//    }
//#endif
//}
//
//int main(int argc, char *argv[])
//{
//    std::vector<int> vec{ 1, 2, 3, 4, 5 };
//#if 1
//    //这里的for_each没有填写类型，是利用其自动推测的功能
//    mystd::for_each(vec.begin(), vec.end(), [](int& element) {//这里同时体现了Lambda的用法
//#else
//    //手动补全模板的类型进行调用
//    mystd::for_each<std::vector<int>::iterator, void(*)(int&)>(vec.begin(), vec.end(), [](int& element) {//这里同时体现了Lambda的用法
//#endif
//        ++element;//将传进来的值自加
//    });
//
//    //默认模板函数的调用
//    mystd::forEach(vec.begin(), vec.end());
//
//    for (auto elem : vec) {
//        std::cout << elem << std::endl;
//    }
//
//    mystd::MyVector<int> myVector;
//    myVector.output(20);
//
//    return 0;
//}