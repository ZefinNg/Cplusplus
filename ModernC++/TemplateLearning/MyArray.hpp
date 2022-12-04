#pragma once
#include <initializer_list>

//[2]
#include <type_traits>//引入std::is_pointer<XXX>::value，用于判断T是否为指针
//模板特化
template<typename T>
struct get_type {
    using type = T;
};

template<typename T>
struct get_type<T*> {
    using type = T;
};
//![2]

template<typename T>
class MyArray
{
    //指定两种类型的别名为iterator、const_iterator
    using iterator = T *;
    using const_iterator = const T*;

public:
    MyArray(size_t count);
    MyArray(const std::initializer_list<T>& list);
    MyArray(std::initializer_list<T>&& list);

    ~MyArray();
    iterator begin()const;
    const_iterator cbegin() const;

    T& operator[] (unsigned index) const;

private:
    T* m_data;
    int m_count;
};

template<typename T>
MyArray<T>::MyArray(size_t count)
{
    if (count != 0) {
        m_data = new T[count]();
        m_count = count;
    }
    else {
        m_data = nullptr;
        m_count = count;
    }
}

template<typename T>
MyArray<T>::MyArray(const std::initializer_list<T>& list)
{
#if 0
    //[1]
    if (list.size() != 0) {
        unsigned count = 0;
        m_data = new T[list.size()]();
        for (const auto element : list) {
            //当T为指针类型时，比如int *，会造成浅拷贝，即同一个内存地址被两个指针变量操作
            //正确的做法应该对T进行判断，是否为指针。看上面区域[2]与下面[3]的实现(萃取技术)
            m_data[count++] = element;
        }
    }
    else
        m_data = nullptr;
    //![1]
#else
    //[3]
    if (list.size() != 0) {
        unsigned count = 0;
        m_data = new T[list.size()]();
        m_count = list.size();

        if (std::is_pointer<T>::value) {
            for (auto element : list) {
                //typename声明type是一种类型，这里要重新new内存空间
                m_data[count++] = new typename get_type<T>::type(*element);
            }
        }
        else {
            for (const auto element : list) {
                //不是指针，直接拷贝值即可
                m_data[count++] = element;
            }
        }
    }
    else {
        m_data = nullptr;
        m_count = 0;
    }
    //![3]
#endif
}

template<typename T>
MyArray<T>::MyArray(std::initializer_list<T>&& list)
{
    if (list.size() != 0) {
        unsigned count = 0;
        m_data = new T[list.size()]();

        for (const auto element : list) {
            //右值引用，内存权限转移，直接拷贝即可
            m_data[count++] = element;
        }
    }
    else
        m_data = nullptr;
}

template<typename T>
MyArray<T>::~MyArray()
{
    if (m_data != nullptr) {

        for (int i = 0; i < m_count; i++) {
            //判断T是否为指针，如果是的话，要挨个delete
            if (std::is_pointer<T>::value) {
                delete m_data[i];
                m_data[i] = nullptr;
            }
        }

        delete[] m_data;
        m_data = nullptr;
    }
}

//这里的iterator需要重新声明，否则无法辨别
//typename 关键字，就是告诉编译器，所修饰的名称为类型名，而不是变量名
//这样在编译阶段，编译器才可以正确判断并通过编译
template<typename T>
typename MyArray<T>::iterator MyArray<T>::begin() const
{
    return m_data;
}

template<typename T>
typename MyArray<T>::const_iterator MyArray<T>::cbegin() const
{
    return m_data;
}

template<typename T>
T& MyArray<T>::operator[](unsigned index) const
{
    return m_data[index];
}