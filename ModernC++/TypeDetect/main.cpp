#include <iostream>
#include "boost/type_index.hpp"

using boost::typeindex::type_id_with_cvr;

int main(int argc, char *argv[])
{
    int i = 100;

    //1. 引用不属于类型，要使用auto定义一个引用变量，必须要自己添加引用符号
    auto& m = i;//int &
    std::cout << "m的类型：" << type_id_with_cvr<decltype(m)>().pretty_name() << std::endl;

    //2. 任何使用引用的地方都可以直接替换成引用指向的对象。因此这里其实就是 auto n = i;因此 n 的类型就是 int。
    auto n = m;//int
    std::cout << "n的类型：" << type_id_with_cvr<decltype(n)>().pretty_name() << std::endl;

    //3. 使用auto时，如果没有引用符号，会忽略值类型的const修饰，而保留修饰指向对象的const，典型的就是指针。
    //这里第二个const会被忽略
    const int * const j = &i;
    auto p = j;//int const *
    std::cout << "p的类型：" << type_id_with_cvr<decltype(p)>().pretty_name() << std::endl;
    const int i1 = 100;
    auto p1 = i1;//int类型，这里的const修饰的是值本身，因此会被auto忽略
    std::cout << "p1的类型：" << type_id_with_cvr<decltype(p1)>().pretty_name() << std::endl;

    //4. auto关键字在推断类型时，如果有了引用符号，那么值类型的const和修饰指向对象的const都会保留
    auto &p3 = i1;//int const &
    std::cout << "p3的类型：" << type_id_with_cvr<decltype(p3)>().pretty_name() << std::endl;

    return 0;
}