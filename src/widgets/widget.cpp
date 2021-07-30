#include "widgets/widget.hpp"

namespace Widgets {

    Widget::Widget()
        : _can_refresh(true)
    {

    }

    void Widget::set_refresh_policy(bool can_refresh_p)
    {
        _can_refresh = can_refresh_p;
    }

    bool Widget::can_refresh() const
    {
        return _can_refresh;
    }

}
