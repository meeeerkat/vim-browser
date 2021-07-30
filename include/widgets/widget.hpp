#ifndef __WIDGETS_WIDGET_H__
#define __WIDGETS_WIDGET_H__

namespace Widgets {

    class Widget {

        public:
            Widget();
            void set_refresh_policy(bool can_refresh);
            bool can_refresh() const;

        private:
            bool _can_refresh;
    };

}

#endif
