#include <iostream>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/support/status.h>

#include "../pb/user.grpc.pb.h"
#include "../pb/user.pb.h"

#ifndef GRPC_USER_H
#define GRPC_USER_H

class grpc_user {
    public:
        explicit grpc_user(std::shared_ptr<grpc::Channel> channel) : stub_(pb::UserService::NewStub(channel)) {}
        bool update_avatar(std::string user_id, std::string file_name);

    private:
        std::unique_ptr<pb::UserService::Stub> stub_;
};

#endif
