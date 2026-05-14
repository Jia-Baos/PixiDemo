#include "widget.hpp"

int main()
{
    Widget w1;                 // 默认构造
    w1.setText(std::string("C++20 PImpl"));
    w1.draw();

    Widget w2(std::string("现代C++"));      // 任意参数构造
    w2.draw();

    Widget w3 = w2;            // 拷贝
    w3.draw();
}