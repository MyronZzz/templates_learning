///////////////////////////////////////////////////////////////////////////////////////
//非类型模板参数(函数模板和类模板)
//tips：
//可用的非类型模板参数：
//1.常量int，如：99、const int a = 5 （注意常量的double不行）
//2.具有static storage duration的指针（现在看来只有常量的指针了）
///////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using std::cout;
using std::endl;

const double global_double = 5.5;
//int global_int = 10;//非常量空间
const int global_int = 10;
int global_int2 = 10;
int* global_ptr = &global_int2;

template<int*>
class A{
public:
    A(){
        cout << "construct A<int_ptr>" << endl;
    }
};

template<typename T, int VALUE>
//template<typename T,double VALUE>//double 不可以作为非类型模板参数
T fun(const T& val)
{
    return val + VALUE;
}

int main()
{
    const int aaa = 10;
    fun<double,global_int>(5);
    fun<double,aaa>(5);
    int asd = 10;
    //A<&asd> a1;
    //A<global_ptr> a3;
}