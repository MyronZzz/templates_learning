///////////////////////////////////////////////////////////////////////////////////////
//关键字typename的使用
//使用 this-> 和 Base<T>
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


int main()
{
    A<Value> a;
    a.GetValue1();
    Derived<int> bbb;
    bbb.print2();
    Derived2<int> bbb2;
    bbb2.print2();
}