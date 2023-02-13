///////////////////////////////////////////////////////////////////////////////////////
//关键字typename的使用
//使用 this-> 和 Base<T>
//成员模板函数
//模板的模板参数（或许...仅仅只是用于炫技？？？？）
//零初始化
//tips：
//需要注意派生自模板的模板类，注意调用的函数是否时期望的！！
//成员模板函数在重载 类型转换运算符 和 赋值运算符 时是非常好用的
///////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <deque>
#include <vector>

using std::cout;
using std::endl;
//关键字typename的使用
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
//使用 this-> 和 Base<T>
//若基类非模板，很容易找到基类中的print1（）
template<typename T>
class Base{
public:
    void print1(){
        cout << "this is Class Base" <<endl;
    }
};


template<typename T>
class Derived : public Base<T>{
public:
    void print1(){
        cout << "Derived::print1() called"<<endl;
    }
    void print2(){
        cout << "Base is " ;
        print1();
        cout << "Base is " ;
        this->print1();
        cout << "Base is ";
        Base<T>::print1();
        cout << "this is Class Derived" <<endl;
    }
};

class Base2{
public:
    void print1(){
        cout << "this is Class Base2" <<endl;
    }
};

template<typename T>
class Derived2 : public Base2{
public:
    void print2(){
        cout << "Base is " ;
        print1();
        cout << "this is Class Derived" <<endl;
    }
};

//成员模板函数
template<typename T>
class Number{
public:
    template<typename T2>
    void operator=(Number<T2>& other){
        cout << "call template operator =" <<endl;
    }
};

//模板的模板参数
template<typename T, template<typename UNUSE> class CONTAINER = std::vector>
class Stack{
public:
    void pop(){
        cout << "Stack::pop() called" << endl;
        container_.pop_back();
    }

private:
    CONTAINER<T> container_;
};

//零初始化

int main()
{
    A<Value> a;
    a.GetValue1();
    Derived<int> bbb;
    bbb.print2();
    Derived2<int> bbb2;
    bbb2.print2();
    Number<int> num_int1;
    Number<int> num_int2;
    Number<double> num_dbl;
    num_int1 = num_int2;
    num_int1 = num_dbl;
    Stack<int> stack1;
    stack1.pop();
    Stack<int, std::deque> stack2;
    stack2.pop();
}