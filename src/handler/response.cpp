#include "response.h"

httpserver::string_response *response::failure_response() {
    return new httpserver::string_response(
        "{\"code\": 400, \"message\": \"FAILURE\"}", 400, "application/json");
}

httpserver::string_response *response::successful_response() {
    return new httpserver::string_response(
        "{\"code\": 200, \"message\": \"SUCCESSFUL\"}", 200,
        "application/json");
}
