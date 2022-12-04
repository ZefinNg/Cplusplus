#include <iostream>
#include "boost/type_index.hpp"

using boost::typeindex::type_id_with_cvr;

template<typename T>
void func4(T&& elem);

template<typename T>
void func1(T&& elem) {
    func4(elem);//ת������elem
}

template<typename T>
void func2(T&& elem) {
    func4(std::move(elem));//�ֶ����յ���elem��תΪ��ֵ������ȥ
}

template<typename T>
void func3(T&& elem) {
    func4(std::forward<T>(elem));//forwardģ�����ʹ�����ƶϳ���ԭ�������ͣ����elem����ֵ/��ֵ��������ƶϳ�����ֵ/��ֵ
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
    func1(i);//������ֵ������func4��ʱ������ֵ

    func1(std::move(i));//������ֵ������func4��ʱ�򣬱������ֵ

    func2(i);//func2�ڲ�������ת������ֵ����˵���func4��ʱ����Ȼ����ֵ

    func2(std::move(i));

    func3(i);

    func3(std::move(i));

    return 0;
}