#include "upload_avatar.h"

const std::shared_ptr<httpserver::http_response>
upload_avatar::render_POST(const httpserver::http_request &request) {
    response response;

    std::string user_id = request.get_arg("user_id");
    if (user_id.empty()) {
        return std::shared_ptr<httpserver::string_response>(
            response.failure_response());
    }

    std::string file_request = request.get_arg("file");
    if (file_request.empty()) {
        return std::shared_ptr<httpserver::string_response>(
            response.failure_response());
    }

    auto publish_ptr = std::make_unique<publish>(conn);
    auto result = std::async(
        std::launch::async,
        [&publish_ptr](std::string user_id, std::string file_request) {
            return publish_ptr->publish_avatar(user_id, file_request);
        },
        user_id, file_request);

    return std::shared_ptr<httpserver::http_response>(
        response.successful_response());
}
