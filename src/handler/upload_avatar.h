#include <httpserver.hpp>
#include <opencv2/core.hpp>
#include <future>
#include <nats/nats.h>

#include "../pb/user.pb.h"
#include "../util/uuid_v4.h"
#include "response.h"
#include "image_processing.h"
#include "publish.h"

#ifndef UPLOAD_AVATAR_H
#define UPLOAD_AVATAR_H

class upload_avatar : public httpserver::http_resource {
    public:
        upload_avatar(natsConnection *c) {
            conn = c;
        }

        const std::shared_ptr<httpserver::http_response> render_POST(const httpserver::http_request& request);

    private:
        natsConnection *conn;
};

#endif
