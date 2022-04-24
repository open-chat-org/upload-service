#include "publish.h"

void publish::publish_avatar(std::string user_id, std::string file_request) {
    image_processing image_processing;
    cv::Mat image = image_processing.multipartFileToMat(file_request);

    UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
    UUIDv4::UUID uuid = uuidGenerator.getUUID();

    std::string file_name = uuid.str() + "-" + user_id + ".webp";

    grpc_user grpc_user(grpc::CreateChannel(
        "localhost:8081", grpc::InsecureChannelCredentials()));
    bool status = grpc_user.update_avatar(user_id, file_name);

    if (status) {
        cv::imwrite("vendor/" + file_name, image);

        const char *payload = file_name.c_str();
        int dataLen = (int)strlen(payload);
        natsConnection_Publish(conn, publish_avatar_subj, (const void *)payload,
                               dataLen);
    }
}
