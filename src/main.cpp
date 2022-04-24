#include "main.h"

void custom_access_log(const std::string &url) {
    std::cout << "ACCESSING: " << url << std::endl;
}

int main() {
    natsConnection *conn = NULL;
    natsStatistics *stats = NULL;
    natsStatus s;

    s = natsConnection_ConnectTo(&conn, "nats://user:secret@localhost:4222");

    if (s == NATS_OK) {
        s = natsStatistics_Create(&stats);
    }

    httpserver::webserver ws =
        httpserver::create_webserver(8083).log_access(custom_access_log);

    upload_avatar uploadAvatar(conn);

    ws.register_resource("/api/v1.0/upload/{user_id}", &uploadAvatar);

    ws.start(true);
    natsStatistics_Destroy(stats);
    natsConnection_Destroy(conn);

    nats_Close();

    return 0;
}
