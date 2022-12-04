#include <iostream>

class Person {
public:
    static void sayHello() {
        std::cout << "Say hello." << std::endl;
    }
    Person() = delete;
private:
    int m_age;
};

int main()
{
    Person::sayHello();
    std::cout << "Hello World!\n";
}
