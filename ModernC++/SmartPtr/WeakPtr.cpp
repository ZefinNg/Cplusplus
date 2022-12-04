//#include <iostream>
//#include "vld.h"
//
////shared_ptr��ʵ�������������Ǵ���ѭ�����õ�ȱ�ݣ�
////weak_ptr�ĳ��־���Ϊ�˽����һ����
//
////weak_ptr�Ķ�����Ҫ�󶨵�shared_ptr�����ϣ�����ԭ����weak_ptr����ı�shared_ptr��������ü�����
////ֻҪshared_ptr��������ü���Ϊ0���ͻ��ͷ��ڴ棬weak_ptr�Ķ��󲻻�Ӱ���ͷ��ڴ�Ĺ��̡�
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
//    //���shared_ptrѭ�����õ����⣬��A��B����֮һ�ĳ�Ա���͸ĳ�weak_ptr
//    std::weak_ptr<B> m_weakB;
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
//    //weak_ptr���󲢲���Ӱ��shared_ptr��������ü���
//    std::shared_ptr<int> sharedI = std::make_shared<int>(100);
//    std::cout << "sharedI �����ü�����" << sharedI.use_count() << std::endl;
//
//    std::weak_ptr<int> weakI(sharedI);
//    std::cout << "����weakָ���sharedI �����ü�����" << sharedI.use_count() << std::endl;
//    //![1]
//
//    //[2]
//    //����A�ĳ�Ա�޸�Ϊweak_ptr���ͺ󣬴�ʱ�㲻���ٳ���ѭ�����õ�����
//    std::shared_ptr<A> sharedA = std::make_shared<A>();
//    std::shared_ptr<B> sharedB = std::make_shared<B>();
//
//    sharedA->m_weakB = sharedB;
//    sharedB->m_sharedA = sharedA;
//    //![2]
//
//    return 0;
//}