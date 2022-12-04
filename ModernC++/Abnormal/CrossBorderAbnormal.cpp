#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    try {
        vec.at(10);//Խ���ʱ����׳��쳣
        //vec[10];//������룬���ַ��ʷ�ʽ�����׳��쳣������ֱ�ӱ���
    }
    catch (const std::out_of_range& exception) {
        std::cout << "exception occers, exception is : " << exception.what() << std::endl;
    }
    catch (...) {//�����������͵��쳣
        std::cout << "exception occers, exception is : unknown exception." << std::endl;
    }

    return 0;
}