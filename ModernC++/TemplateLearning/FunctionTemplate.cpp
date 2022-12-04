//#include <iostream>
//#include <vector>
//#include <functional>
//#include "vld.h"
//
//namespace mystd {
//    template<typename iter_type, typename func_type>
//    void for_each(iter_type first, iter_type last, func_type func) {
//        for (auto iter = first; iter != last; ++iter) {
//            func(*iter);
//        }
//    }
//
//    //[1]Ĭ��ģ�����
//    //Ĭ��ģ���������ͨ������Ĭ�ϲ���һ����һ��һ����������Ĭ�ϲ�������֮��Ĳ�����������Ĭ�ϲ���
//    using func = std::function<void(int&)>;
//
//    //�����func_type ʹ����Ĭ��ģ�����Ϊ func��
//    template<typename iter_type, typename func_type = func>
//    void forEach(iter_type first, iter_type last, func_type func = [](int& element) {//����ʵ����Ĭ��ģ�����func���߼�
//        ++element;
//    }) {
//
//        for (auto iter = first; iter != last; ++iter) {
//            func(*iter);
//        }
//    }
//    //![1]
//
//#if 0
//    template<typename T>
//    class MyVector {
//    public:
//        template<typename T2>//����������һ��T2���ͣ��Ǹ����output�����õ�
//        void output(const T2& elem);
//    };
//
//    //���ⶨ�壬Ҳ��Ҫ�Ȱ�T������
//    template<typename T>
//    template<typename T2>
//    void MyVector<T>::output(const T2& elem) {
//        std::cout << elem << std::endl;
//    }
//#else//��ģ��ʹ��Ĭ��ģ��������� allocator_type Ĭ��ָ��Ϊ std::allocator<T>
//    template<typename T, typename allocator_type = std::allocator<T>>
//    class MyVector {
//    public:
//        template<typename T2>
//        void output(const T2& elem);
//    };
//
//    template<typename T, typename allocator_type>
//    template<typename T2>
//    void MyVector<T, allocator_type>::output(const T2& elem) {
//        std::cout << elem << std::endl;
//    }
//#endif
//}
//
//int main(int argc, char *argv[])
//{
//    std::vector<int> vec{ 1, 2, 3, 4, 5 };
//#if 1
//    //�����for_eachû����д���ͣ����������Զ��Ʋ�Ĺ���
//    mystd::for_each(vec.begin(), vec.end(), [](int& element) {//����ͬʱ������Lambda���÷�
//#else
//    //�ֶ���ȫģ������ͽ��е���
//    mystd::for_each<std::vector<int>::iterator, void(*)(int&)>(vec.begin(), vec.end(), [](int& element) {//����ͬʱ������Lambda���÷�
//#endif
//        ++element;//����������ֵ�Լ�
//    });
//
//    //Ĭ��ģ�庯���ĵ���
//    mystd::forEach(vec.begin(), vec.end());
//
//    for (auto elem : vec) {
//        std::cout << elem << std::endl;
//    }
//
//    mystd::MyVector<int> myVector;
//    myVector.output(20);
//
//    return 0;
//}