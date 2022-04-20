#include "App.h"

#include <httpserver.hpp>
#include <iostream>

using namespace httpserver;

void custom_access_log(const std::string &url) {
    std::cout << "ACCESSING: " << url << std::endl;
}

int main(int argc, char **argv) {
    webserver ws = create_webserver(8083).log_access(custom_access_log);

    upload_avatar uploadAvatar;
    ws.register_resource("/api/v1.0/upload/{user_id}", &uploadAvatar);
    ws.start(true);

    return 0;
}
