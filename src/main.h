#include <httpserver.hpp>
#include <iostream>
#include <nats/nats.h>
#include <nats/status.h>

#include "handler/upload_avatar.h"

#ifndef MAIN_H
#define MAIN_H

void custom_access_log(const std::string &url);

#endif
