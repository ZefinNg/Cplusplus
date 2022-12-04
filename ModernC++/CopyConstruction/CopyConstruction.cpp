#include <iostream>
#include <string>

class Person{
public:
    Person(int age, std::string name) : m_age(age), m_name(name) {
    }

    Person(Person person) {
        m_age = person.m_age;
        m_name = person.m_name;
    }

    int m_age;
    std::string m_name;
};

void getPersonInfo(Person person)
{
    std::cout << person.m_age << std::endl;
    std::cout << person.m_name << std::endl;
}

int main()
{
    Person p1(10, "xiaoming");

    getPersonInfo(p1);
}
