#include <httpserver.hpp>
#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "pb/user.pb.h"
#include "uuid_v4.h"

using namespace httpserver;

#ifndef UPLOADAVATAR_H
#define UPLOADAVATAR_H

class upload_avatar : public http_resource {
    public:
        const std::shared_ptr<http_response> render_POST(const http_request& request) {
            std::string user_id = request.get_arg("user_id");
            if (user_id.empty()) {
                return std::shared_ptr<string_response>(
                    new string_response("{\"code\": 400, \"message\": \"FAILURE\"}",
                        400,
                        "application/json"
                    )
                );
            }

            std::string file_request = request.get_arg("file");
            std::vector<char> vectordata(file_request.begin(), file_request.end());

            cv::Mat data_mat(vectordata,true);
            cv::Mat image(cv::imdecode(data_mat,1));

            UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
            UUIDv4::UUID uuid = uuidGenerator.getUUID();

            std::string file_name = uuid.str() + "-" + user_id + ".webp";

            cv::imwrite("vendor/" + file_name, image);

            return std::shared_ptr<http_response>(
                new string_response("{\"code\": 200, \"message\": \"SUCCESSFUL\", \"data\": \"" + file_name + "\"}",
                    200,
                    "application/json"
                )
            );
        }
};

#endif // !UPLOADAVATAR_H
