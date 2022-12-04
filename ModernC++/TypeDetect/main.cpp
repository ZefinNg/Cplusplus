#include <iostream>
#include "boost/type_index.hpp"

using boost::typeindex::type_id_with_cvr;

int main(int argc, char *argv[])
{
    int i = 100;

    //1. ���ò��������ͣ�Ҫʹ��auto����һ�����ñ���������Ҫ�Լ�������÷���
    auto& m = i;//int &
    std::cout << "m�����ͣ�" << type_id_with_cvr<decltype(m)>().pretty_name() << std::endl;

    //2. �κ�ʹ�����õĵط�������ֱ���滻������ָ��Ķ������������ʵ���� auto n = i;��� n �����;��� int��
    auto n = m;//int
    std::cout << "n�����ͣ�" << type_id_with_cvr<decltype(n)>().pretty_name() << std::endl;

    //3. ʹ��autoʱ�����û�����÷��ţ������ֵ���͵�const���Σ�����������ָ������const�����͵ľ���ָ�롣
    //����ڶ���const�ᱻ����
    const int * const j = &i;
    auto p = j;//int const *
    std::cout << "p�����ͣ�" << type_id_with_cvr<decltype(p)>().pretty_name() << std::endl;
    const int i1 = 100;
    auto p1 = i1;//int���ͣ������const���ε���ֵ������˻ᱻauto����
    std::cout << "p1�����ͣ�" << type_id_with_cvr<decltype(p1)>().pretty_name() << std::endl;

    //4. auto�ؼ������ƶ�����ʱ������������÷��ţ���ôֵ���͵�const������ָ������const���ᱣ��
    auto &p3 = i1;//int const &
    std::cout << "p3�����ͣ�" << type_id_with_cvr<decltype(p3)>().pretty_name() << std::endl;

    return 0;
}