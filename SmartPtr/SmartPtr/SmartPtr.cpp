// SmartPtr.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <memory>
#include <iostream>

int main()
{
#if 0 // auto_ptr
	//��ʼ������1
	std::auto_ptr<int> ap1(new int(8));
	//��ʼ������2
	std::auto_ptr<int> ap2;
	ap2.reset(new int(8));
	/* 
	 * ���ϴ����У�����ָ����� ap1 �� ap2 ������һ���ڶ��Ϸ���� int ����
	 * ���������ڴ������ ap1 �� ap2 �ͷ�ʱ�õ��ͷţ�
	 * ���� auto_ptr �Ļ����÷���
	 */

	//���� auto_ptr �Ŀ�������
	std::auto_ptr<int> ap3(new int(8));
	std::auto_ptr<int> ap4(ap3);
	if (ap3.get() != NULL)
		std::cout << "ap3 is not empty." << std::endl;
	else
		std::cout << "ap3 is empty." << std::endl;

	if (ap4.get() != NULL)
		std::cout << "ap4 is not empty." << std::endl;
	else
		std::cout << "ap4 is empty." << std::endl;

	//���Ը�ֵ����
	std::auto_ptr<int> ap5(new int(8));
	std::auto_ptr<int> ap6;
	ap6 = ap5;
	if (ap5.get() != NULL)
		std::cout << "ap5 is not empty." << std::endl;
	else
		std::cout << "ap5 is empty." << std::endl;

	if (ap6.get() != NULL)
		std::cout << "ap6 is not empty." << std::endl;
	else
		std::cout << "ap6 is empty." << std::endl;

#elif 0//unique_ptr
	//��ʼ����ʽ1
	std::unique_ptr<int> up1(new int(123));
	//��ʼ����ʽ2
	std::unique_ptr<int> up2;
	up2.reset(new int(123));
	//��ʼ����ʽ3
	std::unique_ptr<int> up3 = std::make_unique<int>(123);

	std::unique_ptr<int> up4(std::make_unique<int>(123));
	//�������д������ᱨ��Ϊ�˽��auto_ptr�������졢��ֵ���������
	//std::unique_ptr<int> up5(up4);
	//std::unique_ptr<int> up5 = up3;
#elif 0//shared_ptr
	//��ʼ����ʽ1
	std::shared_ptr<int> sp1(new int(123));

	//��ʼ����ʽ2
	std::shared_ptr<int> sp2;
	sp2.reset(new int(123));

	//��ʼ����ʽ3
	std::shared_ptr<int> sp3;
	sp3 = std::make_shared<int>(123);
#elif 1//weak_ptr
	//����һ��std::shared_ptr����
	std::shared_ptr<int> sp1(new int(123));
	std::cout << __LINE__ << " sp1 use count:" << sp1.use_count() << std::endl;

	//ͨ�����캯���õ�һ��std::weak_ptr����
	std::weak_ptr<int> sp2(sp1);
	std::cout << __LINE__ << " sp1 use count:" << sp1.use_count() << std::endl;
	std::cout << __LINE__ << " sp2 use count:" << sp2.use_count() << std::endl;

	//ͨ����ֵ������õ�һ��std::weak_ptr����
	std::weak_ptr<int> sp3 = sp1;
	std::cout << __LINE__ << " sp1 use count:" << sp1.use_count() << std::endl;
	std::cout << __LINE__ << " sp3 use count:" << sp3.use_count() << std::endl;

	//ͨ��һ��std::weak_ptr����õ���һ��std::weak_ptr����
	std::weak_ptr<int> sp4 = sp2;
	std::cout << __LINE__ << " sp1 use count:" << sp1.use_count() << std::endl;
	std::cout << __LINE__ << " sp2 use count:" << sp2.use_count() << std::endl;
	std::cout << __LINE__ << " sp4 use count:" << sp4.use_count() << std::endl;

#endif
	
    return 0;
}

