#include <iostream>

class Test 
{
public:
    Test() = default;

    Test(const Test& test) {
        std::cout << "拷贝构造函数" << std::endl;
        if (test.m_str != nullptr) {
            m_str = new char[strlen(test.m_str) + 1]();
            strcpy_s(m_str, strlen(test.m_str) + 1, test.m_str);
        }
        else {
            m_str = nullptr;
        }
    }

    Test(Test &&test) {
        std::cout << "移动构造函数" << std::endl;
        if (test.m_str != nullptr) {
            m_str = test.m_str;
            test.m_str = nullptr;//移动完以后原来的就不能再用了,因此形参不能用const
        }
        else {
            m_str = nullptr;
        }
    }

    Test& operator= (const Test& test) {
        std::cout << "赋值运算符函数" << std::endl;
        if (this == &test) {//如果是同个对象，则直接返回
            return *this;
        }

        if (m_str != nullptr) {
            delete[] m_str;
            m_str = nullptr;
        }

        if (test.m_str != nullptr) {
            m_str = new char[strlen(test.m_str) + 1]();
            strcpy_s(m_str, strlen(test.m_str) + 1, test.m_str);
        }
        else {
            m_str = nullptr;
        }
        return *this;//最后要返回*this
    }

    Test& operator= (Test&& test) {
        std::cout << "移动语义赋值运算符函数" << std::endl;
        if (this == &test) {//如果相同，则直接返回
            return *this;
        }

        if (m_str != nullptr) {
            delete[] m_str;
            m_str = nullptr;
        }

        if (test.m_str != nullptr) {
            m_str = test.m_str;
            test.m_str = nullptr;
        }
        else {
            m_str = nullptr;
        }
        return *this;//最后要返回*this
    }

private:
    char *m_str = nullptr;
};

Test makeTest()
{
    Test t;
    return t;
}

int main()
{
    Test t = makeTest();//移动构造函数
    Test t1 = t;//拷贝构造
    Test t2;
    t2 = std::move(t1);
    return 0;
}