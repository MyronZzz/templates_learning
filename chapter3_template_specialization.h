#ifndef TEMPLATES_LEARNING_CHAPTER3_TEMPLATE_SPECIALIZATION_H
#define TEMPLATES_LEARNING_CHAPTER3_TEMPLATE_SPECIALIZATION_H

#include "chapter3_class_template.h"
#include <string>

using std::string;

//类模板特化，特化一个string类型的Stack（--！，没任何意义，just an example）
//声明与实现在一起
template<>
class Stack<string> {
public:
    Stack() {
        cout << "call string specialization construct function" << endl;
    }

    void push(const string &elem) {
        cout << "call string specialization push()" << endl;
    }

    void pop() {
        cout << "call string specialization pop()" << endl;
    }

    //假如没有实现top（）方法
    /*string top() const {
        cout << "call string specialization top()" << endl;
        return elems_.back();
    }*/

private:
    std::vector<string> elems_;
};

#endif //TEMPLATES_LEARNING_CHAPTER3_TEMPLATE_SPECIALIZATION_H
