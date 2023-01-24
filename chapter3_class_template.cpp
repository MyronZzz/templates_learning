///////////////////////////////////////////////////////////////////////////////////////
//类模板基础语法
//Class<T>和Class在使用时的区别
///////////////////////////////////////////////////////////////////////////////////////
#include "chapter3_class_template.h"

int main()
{
    Stack<double> stack_;
    stack_.push(32);
    stack_.push(33);
    stack_.push(34);
    cout << "top element is :" << stack_.top() << endl;
    stack_.pop();
    cout << "top element is :" << stack_.top() << endl;
    stack_.pop();
    cout << "top element is :" << stack_.top() << endl;

}