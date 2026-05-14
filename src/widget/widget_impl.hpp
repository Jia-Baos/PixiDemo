#pragma once
#include <string>
#include <iostream>

class Widget::Impl
{
public:
    Impl() = default;
    explicit Impl(std::string t) : text(std::move(t)) {}

    void draw() const {
        std::cout << "draw   : " << text << std::endl;
    }
    void setText(std::string t) { text = std::move(t); }

private:
    std::string text{"hello"};
};