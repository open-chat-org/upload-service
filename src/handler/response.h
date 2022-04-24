#include <httpserver.hpp>

#ifndef RESPONSE_H
#define RESPONSE_H

class response {
    public:
        httpserver::string_response *failure_response();

        httpserver::string_response *successful_response();
};

#endif
