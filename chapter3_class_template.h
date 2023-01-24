#ifndef TEMPLATES_LEARNING_CHAPTER3_CLASS_TEMPLATE_H
#define TEMPLATES_LEARNING_CHAPTER3_CLASS_TEMPLATE_H

#include <vector>
#include<iostream>

using std::cout;
using std::endl;
//类模板声明
//声明和定义写在一起当然可以，许多库也是这么做的！
template<typename T>
class Stack
{
public:
    //此处使用的是类名，因此不需要Stack<T>
    Stack();
    void push(const T& elem);
    void pop();
    T top() const;

private:
    std::vector<T> elems_;
};

//类模板定义
template<typename T>
//此处第一个需要使用的是类型，因此要Stack<T>，而第二个使用的是函数名
Stack<T>::Stack() {
    cout << "call construct function" << endl;
}

template<typename T>
void Stack<T>::push(const T& elem){
    elems_.push_back(elem);
    cout << "call push()" << endl;
    cout << "T's type = " << typeid(T).name() << endl;
}

template<typename T>
void Stack<T>::pop(){
    elems_.pop_back();
    cout << "call pop()" << endl;
    cout << "T's type = " << typeid(T).name() << endl;
}

template<typename T>
T Stack<T>::top() const
{
    return elems_.back();
    cout << "call top()" << endl;
    cout << "T's type = " << typeid(T).name() << endl;
}

#endif //TEMPLATES_LEARNING_CHAPTER3_CLASS_TEMPLATE_H
