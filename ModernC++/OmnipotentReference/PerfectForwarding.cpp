#include <iostream>
#include "boost/type_index.hpp"

using boost::typeindex::type_id_with_cvr;

template<typename T>
void func4(T&& elem);

template<typename T>
void func1(T&& elem) {
    func4(elem);//转发参数elem
}

template<typename T>
void func2(T&& elem) {
    func4(std::move(elem));//手动将收到的elem，转为右值传递下去
}

template<typename T>
void func3(T&& elem) {
    func4(std::forward<T>(elem));//forward模板可以使参数推断出它原来的类型，如果elem是左值/右值，则可以推断出是左值/右值
}

template<typename T>
void func4(T&& elem) {
    std::cout << "Type of elem : " << type_id_with_cvr<decltype(elem)>().pretty_name() << std::endl;
    std::cout << "Type of T : " << type_id_with_cvr<T>().pretty_name() << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

int main(int argc, char *argv[])
{
    int i = 10;
    func1(i);//传入左值，到达func4的时候还是左值

    func1(std::move(i));//传入右值，到达func4的时候，变成了左值

    func2(i);//func2内部将参数转成了右值，因此到达func4的时候，依然是右值

    func2(std::move(i));

    func3(i);

    func3(std::move(i));

    return 0;
}