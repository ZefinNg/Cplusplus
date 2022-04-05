// SmartPtr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <memory>
#include <iostream>

int main()
{
#if 0 // auto_ptr
	//初始化方法1
	std::auto_ptr<int> ap1(new int(8));
	//初始化方法2
	std::auto_ptr<int> ap2;
	ap2.reset(new int(8));
	/* 
	 * 以上代码中，智能指针对象 ap1 和 ap2 均持有一个在堆上分配的 int 对象；
	 * 并且两块内存可以在 ap1 和 ap2 释放时得到释放；
	 * 这是 auto_ptr 的基本用法。
	 */

	//测试 auto_ptr 的拷贝构造
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

	//测试赋值构造
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
	//初始化方式1
	std::unique_ptr<int> up1(new int(123));
	//初始化方式2
	std::unique_ptr<int> up2;
	up2.reset(new int(123));
	//初始化方式3
	std::unique_ptr<int> up3 = std::make_unique<int>(123);

	std::unique_ptr<int> up4(std::make_unique<int>(123));
	//下面两行代码编译会报错，为了解决auto_ptr拷贝构造、赋值构造的问题
	//std::unique_ptr<int> up5(up4);
	//std::unique_ptr<int> up5 = up3;
#elif 0//shared_ptr
	//初始化方式1
	std::shared_ptr<int> sp1(new int(123));

	//初始化方式2
	std::shared_ptr<int> sp2;
	sp2.reset(new int(123));

	//初始化方式3
	std::shared_ptr<int> sp3;
	sp3 = std::make_shared<int>(123);
#elif 1//weak_ptr
	//创建一个std::shared_ptr对象
	std::shared_ptr<int> sp1(new int(123));
	std::cout << __LINE__ << " sp1 use count:" << sp1.use_count() << std::endl;

	//通过构造函数得到一个std::weak_ptr对象
	std::weak_ptr<int> sp2(sp1);
	std::cout << __LINE__ << " sp1 use count:" << sp1.use_count() << std::endl;
	std::cout << __LINE__ << " sp2 use count:" << sp2.use_count() << std::endl;

	//通过赋值运算符得到一个std::weak_ptr对象
	std::weak_ptr<int> sp3 = sp1;
	std::cout << __LINE__ << " sp1 use count:" << sp1.use_count() << std::endl;
	std::cout << __LINE__ << " sp3 use count:" << sp3.use_count() << std::endl;

	//通过一个std::weak_ptr对象得到另一个std::weak_ptr对象
	std::weak_ptr<int> sp4 = sp2;
	std::cout << __LINE__ << " sp1 use count:" << sp1.use_count() << std::endl;
	std::cout << __LINE__ << " sp2 use count:" << sp2.use_count() << std::endl;
	std::cout << __LINE__ << " sp4 use count:" << sp4.use_count() << std::endl;

#endif
	
    return 0;
}

