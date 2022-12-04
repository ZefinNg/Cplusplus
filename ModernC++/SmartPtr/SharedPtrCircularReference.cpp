//#include <iostream>
//#include "vld.h"
//
////shared_ptr����һ�����⣺ѭ������
//
//class A;
//class B;
//
//class A {
//public:
//    A() {
//        std::cout << "A ���캯����" << std::endl;
//    }
//
//    ~A() {
//        std::cout << "A ����������" << std::endl;
//    }
//
//    std::shared_ptr<B> m_sharedB;
//};
//
//class B {
//public:
//    B() {
//        std::cout << "B ���캯����" << std::endl;
//    }
//
//    ~B() {
//        std::cout << "B ����������" << std::endl;
//    }
//
//    std::shared_ptr<A> m_sharedA;
//};
//
//int main(int argc, char *argv[])
//{
//    //[1]
//    //���к���Է���vld�����ڴ�й©��A��B������������û���������ã�
//    std::shared_ptr<A> sharedA = std::make_shared<A>();
//    std::shared_ptr<B> sharedB = std::make_shared<B>();
//
//    //sharedA��sharedB�ĳ�Ա����ָ���˶Է�����ʱ���Զ��ڴ�����ü���Ϊ2��
//    sharedA->m_sharedB = sharedB;
//    sharedB->m_sharedA = sharedA;
//    
//    //main�������н�����ջ��������ʱ��sharedA�����٣�A�����ü���-1����ʱA�Ķ��ڴ����ü�����ȻΪ1����ΪsharedB�ĳ�Ա��ָ����A��
//    //���A���������������ᱻִ�У���Ϊ��ʱȷʵ����B�ĳ�Աָ�����������ü���Ϊ0ʱ���ͻ��������������ʱ���ü���Ϊ1����
//    //sharedB�����Ҳ��ˣ�������������
//    //��������������н�������A����B������������û�б����ã����³������ڴ�й©��
//    //![1]
//
//    //[2]��ܷ���һ��
//    //���û�г��ֻ���ָ�򣬽���һ���ĳ�Աָ������һ������ôҲ���������ͷ�
//    //������43����44����֮һע�͵���ע�⣬ջ���ͷ�˳���Ƿ��ģ����ͷ�sharedB�����ͷ�sharedA��
//    //![2]
//
//    //[3]��ܷ�������
//    //������˳�ʱ��sharedB�Լ������˳�Ա��ָ����ô�Ͳ�����ֻ���ָ���¡�������������
//    sharedB->m_sharedA.reset();
//    //![3]
//
//    //[4]��ܷ�����������һ����ʹ��weak_ptrָ��
//    //![4]
//
//    return 0;
//}