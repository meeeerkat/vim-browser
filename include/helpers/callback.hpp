#ifndef __HELPERS_CALLBACK_H__
#define __HELPERS_CALLBACK_H__

namespace Helpers {
    // Deleting the args should be done in func()
    class Callback {
        public:
            Callback(void (*func) (void*), void *args);
            void exec() const;

        private:
            void (*func) (void*);
            void *args;
    };
}

#endif
