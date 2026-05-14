#include "widget.hpp"
#include "widget_impl.hpp"

//----- 构造 --------------------------------------------------
Widget::Widget() : pImpl(std::make_unique<Impl>()) {}
template <class... Args>
Widget::Widget(Args&&... args)
    : pImpl(std::make_unique<Impl>(std::forward<Args>(args)...)) {}

//----- 析构/移动/拷贝 ----------------------------------------
Widget::~Widget() = default;                       // 唯一指针自动释放
Widget::Widget(Widget&&) noexcept = default;
Widget& Widget::operator=(Widget&&) noexcept = default;
Widget::Widget(const Widget& rhs)
    : pImpl(std::make_unique<Impl>(*rhs.pImpl)) {} // 深拷贝
Widget& Widget::operator=(const Widget& rhs)
{
    *pImpl = *rhs.pImpl;   // copy-and-swap 也可
    return *this;
}

//----- 业务接口 ----------------------------------------------
void Widget::draw() const          { pImpl->draw(); }
void Widget::setText(std::string s){ pImpl->setText(std::move(s)); }

// 显式实例化常用模板，避免头文件里出现定义
template Widget::Widget(std::string&&);