///////////////////////////////////////////////////////////////////////////////////////
//关键字typename的使用
//使用this->
//tips：
///////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using std::cout;
using std::endl;

class Value{
public:
    struct Pair{
        double a;
        double b;
    };
    Pair pr_;
    static Pair pr_static_;
};

template<typename T>
class A{
public:
    //T::Pair GetValue1()   若没有typename ，产生一个问题，T::Pair到底是一个类型还是一个变量？
    typename T::Pair GetValue1(){
        return value_.pr_;
    }

private:
    T value_;

};


int main()
{
    A<Value> a;
    a.GetValue1();
}