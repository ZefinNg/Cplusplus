//#include <iostream>
//#include <string>
//#include <vector>
//
//int main(int argc, char *argv[])
//{
//    std::vector<std::shared_ptr<int>> sharedVec;
//    try {
//        //��ѭ�������ڴ棬ģ��new��ʱ������쳣
//        while (1) {
//#if 0//��ָͨ��
//            int *pi = new int[10000000]();
//#else//����ָ��
//            std::unique_ptr<int> uniqueI(new int[10000000]());
//            //�����������ʧ�����Ҫ����תΪshared_ptr
//            sharedVec.push_back(std::move(uniqueI));
//#endif
//        }
//    }
//    catch (const std::bad_alloc& exception) {
//        std::cout << "exception occers, exception is : " << exception.what() << std::endl;
//    }
//    catch (...) {//�����������͵��쳣
//        std::cout << "exception occers, exception is : unknown exception." << std::endl;
//    }
//
//    return 0;
//}