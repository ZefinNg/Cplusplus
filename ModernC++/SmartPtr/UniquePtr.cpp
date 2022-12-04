#include <iostream>
#include <memory>
#include "vld.h"

//unique_ptr�ĳ�ʼ����shared_ptr����

void myFunc(std::unique_ptr<int> uniquePtr)
{
    std::shared_ptr<int> sharedptr(std::move(uniquePtr));
    std::cout << __FUNCTION__ << "*sharedptr = " << *sharedptr << std::endl;
}

int main(int argc, char *argv[])
{
    //[1]�����ķ�ʽ
    std::unique_ptr<int> uniqueA(new int(100));
    //һ������Ƽ�ʹ��std::make_unique��������
    std::unique_ptr<int> uniqueB = std::make_unique<int>(200);
    //![1]

    //[2]unique_ptr��ֹ���ƹ��캯����Ҳ��ֹ��ֵ����������ء������ռ��������塣
    //std::unique_ptr<int> unqueA1(uniqueA);//�������
    //std::unique_ptr<int> uniqueB1 = uniqueB;//�������
    //![2]

    //[3]unqiue_ptr�����ƶ����죬�ƶ���ֵ��
    //�ƶ��������֮ǰ�Ķ����Ѿ�ʧȥ�����壬�ƶ�������Ȼ��Ӱ���ռ������
    std::unique_ptr<int> uniqueC = std::move(uniqueA);//�ƶ���uniqueA�ͷ����ˣ���ʱ��uniqueC��ռ��������ͻ
    uniqueB = std::move(uniqueC);//uniqueB�Լ�ԭ�е��ڴ汻�ͷţ�uniqueCҲ���ͷţ�uniqueC��ռ���ڴ�ת����uniqueB
    std::cout << *uniqueB << std::endl;
    //![3]

    //[4]reset()������
    //��������������£��ͷ�����ָ��Ķ��󣬲�������ָ���ÿ�
    std::unique_ptr<int> uniqueD = std::make_unique<int>(300);
    uniqueD.reset();

    //������������£��ͷ�����ָ��Ķ��󣬲�������ָ��ָ���µĶ���
    std::unique_ptr<int> uniqueE = std::make_unique<int>(400);
    uniqueE.reset(new int(500));//ֱ��ָ��һ���µĶ��ڴ�
    //![4]

    //[5]unique_ptr����תΪshared_ptr����unique_ptr�Ķ���Ϊһ����ֵʱ���Ϳ��Խ��ö���ת��Ϊshared_ptr�Ķ���
    //���ʹ�õĲ����࣬��Ҫ����ռʽָ��ת��Ϊ����ʽָ�볣������Ϊ��ǰ���ʧ��
    //ע�⣺shared_ptr�����޷�ת��Ϊunique_ptr����
    std::unique_ptr<int> uniqueF = std::make_unique<int>(200);
    myFunc(std::move(uniqueF));
    //![5]

    return 0;
}