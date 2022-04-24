#include <iostream>
#include <opencv2/core.hpp>
#include <nats/nats.h>

#include "response.h"
#include "image_processing.h"
#include "grpc_user.h"
#include "../util/uuid_v4.h"

#ifndef PUBLISH_H
#define PUBLISH_H

class publish {
    public:
        publish(natsConnection *c) {
            conn = c;
        }

        void publish_avatar(std::string user_id, std::string file_request);

    private:
        natsConnection *conn;
        const char  *publish_avatar_subj   = "foo";
};

#endif
