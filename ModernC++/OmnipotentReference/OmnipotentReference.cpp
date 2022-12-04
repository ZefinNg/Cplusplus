//#include <iostream>
//#include <boost/type_index.hpp>
//#include <vector>
//
//using boost::typeindex::type_id_with_cvr;
//
//template<typename T>
//void test(T&& elem) {//T&& 就是万能引用
//    std::cout << "Type of elem : " << type_id_with_cvr<decltype(elem)>().pretty_name() << std::endl;
//    std::cout << "Type of T : " << type_id_with_cvr<T>().pretty_name() << std::endl;
//}
//
//template<typename T>
//void test1(const T&& elem) {//加上了 const，就是一个普通的右值引用
//    std::cout << "Type of elem : " << type_id_with_cvr<decltype(elem)>().pretty_name() << std::endl;
//    std::cout << "Type of T : " << type_id_with_cvr<T>().pretty_name() << std::endl;
//}
//
//template<typename T>
//void test2(std::vector<T>&& elem) {//这样子也是一个普通的右值引用
//    std::cout << "Type of elem : " << type_id_with_cvr<decltype(elem)>().pretty_name() << std::endl;
//    std::cout << "Type of T : " << type_id_with_cvr<T>().pretty_name() << std::endl;
//}
//
//template<typename T>
//class MyVector
//{
//public:
//    static void push_back(T&& elem) {//这样子不是万能引用，T 影响的是MyVector的类型
//
//    }
//    
//    template<typename T2>
//    static void push_back(T2&& elem) {//万能引用，T2&& 的类型完全独立于MyVector类了，每调用一次 push_back 函数，都要推断 T2 的类型
//
//    }
//};
//
//int main(int argc, char *argv[])
//{
//    int i = 10;
//    test(i); //传入左值，则 elem 是左值，而 T 为 int &；
//    test(10);//传入右值，则 elem 是右值，而 T 为 int
//    std::cout << "----------------------------" << std::endl;
//
//    //test1(i);//错误代码，需要传入右值
//    test1(10);//10 是右值，所以可以传入
//    std::cout << "----------------------------" << std::endl;
//
//    std::vector<int> vec{1, 2, 3, 4, 5};
//    //test2<int>(vec);//错误代码，必须传入右值
//    test2<int>({ 1, 2, 3, 4, 5 });//传入右值即可调用
//    std::cout << "----------------------------" << std::endl;
//
//    int j = 100;
//    auto&& elem1 = j;//auto，传左值则是左值引用
//    //const auto&& elem1 = j;//错误代码，这里不是万能引用，不能讲右值绑定到左值
//    std::cout << "type of elem1 : " << type_id_with_cvr<decltype(elem1)>().pretty_name() << std::endl;
//    auto&& elem2 = std::move(j);//auto，传右值则是右值引用
//    std::cout << "type of elem2 : " << type_id_with_cvr<decltype(elem2)>().pretty_name() << std::endl;
//
//    return 0;
//}
//
