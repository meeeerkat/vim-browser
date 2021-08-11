#ifndef __HELPERS_HTTPREQUEST_H__
#define __HELPERS_HTTPREQUEST_H__

#include <string>

namespace Helpers {

    struct HttpRequest {
        // Only 2 types yet
        enum Type { GET, POST };

        std::string url;
        Type type = GET;
        std::string fields = "";
    };

}

#endif
