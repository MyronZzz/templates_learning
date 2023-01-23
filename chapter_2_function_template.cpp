//函数模板
//函数模板重载相关细节
//尽可能使用引用而不是值，实例化的时候并不知道这个T是个多大的对象
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

//**********T 和 const T**********//
//函数的实参中const T和T时一样的，已经是一个拷贝对象了，const没有意义了，同理返回值也一样，因此编译器报错
//FOR TEST ：取消注释掉此模板，编译时将报错：call of overloaded XXX is ambiguous
/*template<typename T>
inline const T max(const T a, const T b)
{
    cout << "call template const T&" << endl;
    return a < b ? b : a;
}

template<typename T>
inline T max(T a, T b)
{
    cout << "call template T&" << endl;
    return a < b ? b : a;
}*/

//**********T& 和 const T&**********//
//T&和const T&类型不一样可以同时存在，但是自动推导这里会有很多的情况：
//1.如果参数原本是const的 ，将使用 const T& 来实例化
//2.如果参数原本是非const的，将使用 T& 来实例化
//这样的小细节产生一些bug在所难免，如果确实需要这两种模板重载，千万不要暴露给调用者！
template<typename T>
inline const T& max(const T& a, const T& b)
{
    cout << "call template const T&" << endl;
    return a < b ? b : a;
}

template<typename T>
inline T& max(T& a, T& b)
{
    cout << "call template T&" << endl;
    return a < b ? b : a;
}




//**********T 和 T&**********//
//T与T&是不可以同时存在的
//FOR TEST ：取消注释掉此模板，编译时将报错：call of overloaded XXX is ambiguous
/*template<typename T>
inline T max(const T a, const T b)
{
    cout << "call template T" << endl;
    return *a < *b ? b : a;
}*/


//**********const T*& 和 const T&**********//
//T可以用于表达指针类型
//T与T*是可以都存在的，当实例化遇到指针类型是则使用T*模板
//FOR TEST ：注释掉此模板，main中将调用上面T&的模板来实例化(此时的T = const char*)
/*template<typename T>
inline const T*& max(const T*& a, const T*& b)
{
    cout << "call template const T*&" << endl;
    return *a < *b ? b : a;
}*/

int main()
{
    const char* str1 = "1string";
    const char* str2 = "2string";
    int num1 = 9;
    int num2 = 10;
    const int c_num1 = 9;
    const int c_num2 = 10;

    max(num1,num2);
    max(c_num1,c_num2);
    max<const int&>(num1,num2);


    max(str1,str2);
}