///////////////////////////////////////////////////////////////////////////////////////
//类模板特化（对某个具体类型的模板参数做特化）
//类模板局部特化（对部分情况的模板参数做特化，有很高的灵活性）
//缺省模板参数,类似于函数缺省值
//tips：
//特化后任何没有实现的原模板方法将不存在，意味着如果特化想删除某个方法，可以这么做
//局部特化有时候好像一种重载（一种更明确的模板但是又不是具体类型的那种），它具有非常高的灵活性，但在思维出现逻辑漏洞时可能会出现二义性的错误
///////////////////////////////////////////////////////////////////////////////////////
#include "chapter3_template_specialization.h"

template<typename T1,typename T2 = double>
class TestPartSpecialization{
public:
    void set(const T1& value1, const T2& value2){
        cout << "call general TestPartSpecialization" << endl;
        cout << "T2's type = " << typeid(T2).name() << endl;
        value1_ = value1;
        value2_ = value2;
    }
    void get(T1& value1, T2& value2){
        value1 = value1_;
        value2 = value2_;
    }

private:
    T1 value1_;
    T2 value2_;
};

//偏特化T1和T2为相同类型
template <typename T>
class TestPartSpecialization<T,T>{
public:
    void set(const T& value1, const T& value2){
        cout << "TestPartSpecialization<T,T>" << endl;
        value1_ = value1;
        value2_ = value2;
    }
    void get(T& value1, T& value2){
        value1 = value1_;
        value2 = value2_;
    }

private:
    T value1_;
    T value2_;
};

//偏特化为指针类型
template<typename T1,typename T2>
class TestPartSpecialization<T1*,T2*>{
public:
    void set(T1* value1, T2* value2){
        cout << "TestPartSpecialization<T1*,T2*>" << endl;
        value1_ = value1;
        value2_ = value2;
    }
    void get(T1*& value1, T2*& value2){
        value1 = value1_;
        value2 = value2_;
    }

private:
    T1* value1_;
    T2* value2_;
};


int main() {
    Stack<int> stack_int_;
    Stack<string> stack_str_;
    stack_int_.push(3.14);
    stack_str_.push("asd");
    //stack_str_.top();//因为没有实现，Stack<std::string>中没有这个方法了
    stack_str_.pop();

    //偏特化示例
    int a = 1;
    double b = 2;
    TestPartSpecialization<int> c1;
    c1.set(3,4);
    TestPartSpecialization<double,double> c2;
    c2.set(3,4);
    TestPartSpecialization<int*,double*> c3;
    c3.set(&a,&b);
    //这里出现了二义性，<T,T> 和 <T1*,T2*>两个都是偏特化，同等匹配了
    //TestPartSpecialization<double*,double*> c4;
}
