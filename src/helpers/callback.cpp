#include "helpers/callback.hpp"

namespace Helpers {

    Callback::Callback(void (*func) (void*), void *args)
        :func(func), args(args)
    {

    }
    void Callback::exec() const
    {
        func(args);
    }

}
