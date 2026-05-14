#pragma once
#include <memory>

class Widget // 对外接口
{
public:
    Widget(); // 默认构造
    template <class... Args>
    explicit Widget(Args &&...args); // 任意参数构造

    ~Widget();              // 析构必须在 .cpp 里定义
    Widget(const Widget &); // 拷贝
    Widget &operator=(const Widget &);
    Widget(Widget &&) noexcept; // 移动
    Widget &operator=(Widget &&) noexcept;

    void draw() const; // 业务接口示例
    void setText(std::string text);

private:
    class Impl;                  // 前向声明
    std::unique_ptr<Impl> pImpl; // 唯一指针持有
};