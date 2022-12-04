#include <iostream>
//[1]
#include <functional>
using func_type = std::function<void(int)>;
//[1]

using pf_type = void(*)(int);//函数指针

void myFunc(pf_type pf, int i)
{
    pf(i);
}

void newFunc(func_type fc, int i) 
{
    fc(i);
}

int main()
{
    int i = 10;
    int j = 100;

    //Lambda的最简形式是[]{}(); 完整形式是[]() ->ret{};
    //[]代表捕获列表：表示lambda表达式可以访问【前文】的哪些变量。
    //[]空的表示不捕获任何变量；
    //[=]表示按值捕获所有变量；
    //[&]表示按照引用捕获所有变量；
    //[=,&i]表示变量i用引用传递，除i的其他所有变量用值传递；
    //[&,i]表示变量i用值传递，除i的其他所有变量用引用传递；
    //[i]表示i以值传递的形式被单独捕获，其他变量不能被捕获；
    //[&i]表示i以引用的形式被单独捕获，其他变量不能被捕获；
    [=](int parameter) {//这里的括号指函数的参数，即形参
        std::cout << "Hello world." << std::endl;
        std::cout << "i 的值：" << i << std::endl;
        std::cout << "j 的值：" << j << std::endl;
        std::cout << "parameter 的值：" << parameter << std::endl;
    }(300);//这里的括号即是传参的值

    //->ret的ret指的是返回值的类型；
    //[]() ->int{//如果函数没有返回值，但是在定义的时候明确了它的返回值，编译时会报错
    //{}内写的就是函数体
    []() ->void {//“->void ”明确了返回值为void，不写也可以
        std::cout << "这个一个完整型的lambda函数。" << std::endl;
    }();

    //Lambda较常用的方法
    myFunc([](int i) {
        std::cout << "这是Lambda比较常用的做法" << std::endl;
        std::cout << "此时i 的值为：" << i << std::endl;
    }, 200);

    //当一个Lambda表示作为函数对象的时候，它的捕获列表必须为空，不为空的话会报错
    //int i1 = 300;
    //myFunc([i1](int i) {
    //    std::cout << "这是Lambda函数带捕获变量的做法" << std::endl;
    //    std::cout << "此时i1 的值为：" << i << std::endl;
    //}, 200);

    //为了解决上面的问题，可以使用C++11的一个做法
    int i1 = 300;
    newFunc([i1](int i) {
        std::cout << "这是Lambda函数带捕获变量的做法" << std::endl;
        std::cout << "此时i1 的值为：" << i << std::endl;
    }, 200);
}

