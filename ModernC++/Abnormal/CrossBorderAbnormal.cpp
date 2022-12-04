#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    try {
        vec.at(10);//越界的时候会抛出异常
        //vec[10];//错误代码，这种访问方式不会抛出异常，程序直接报错
    }
    catch (const std::out_of_range& exception) {
        std::cout << "exception occers, exception is : " << exception.what() << std::endl;
    }
    catch (...) {//捕获其他类型的异常
        std::cout << "exception occers, exception is : unknown exception." << std::endl;
    }

    return 0;
}