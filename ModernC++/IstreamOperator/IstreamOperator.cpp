#include <iostream>
#include <string>

class Person
{
    friend std::istream& operator >> (std::istream& in, Person& person);
public:
    int getAge() {
        return m_age;
    }

    std::string getName() {
        return m_name;
    }

    bool operator > (const Person& person) {
        return m_age > person.m_age;
    }

private:
    int m_age;
    std::string m_name;
};

std::istream& operator >> (std::istream& in, Person& person)
{
    in >> person.m_age >> person.m_name;
    return in;
}

int main()
{
    Person p;
    std::cin >> p;
    std::cout << p.getAge() << p.getName() << std::endl;

    Person p2;
    std::cin >> p2;

    std::cout << (p > p2) << std::endl;
}
