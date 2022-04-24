#include "grpc_user.h"

bool grpc_user::update_avatar(std::string user_id, std::string file_name) {
    pb::Avatar request;
    request.set_avatar(file_name);
    request.set_id(std::stoi(user_id));

    pb::Empty empty;

    grpc::ClientContext context;
    grpc::CompletionQueue cq;
    grpc::Status status;

    std::unique_ptr<grpc::ClientAsyncResponseReader<pb::Empty>> rpc(
        stub_->PrepareAsyncUpdateAvatar(&context, request, &cq));

    rpc->StartCall();

    rpc->Finish(&empty, &status, (void *)1);
    void *got_tag;
    bool ok = false;

    GPR_ASSERT(cq.Next(&got_tag, &ok));
    GPR_ASSERT(got_tag == (void *)1);
    GPR_ASSERT(ok);

    if (status.ok()) {
        return true;
    } else {
        return false;
    }
}
