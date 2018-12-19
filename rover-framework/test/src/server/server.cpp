#include "gtest/gtest.h"
#include "../src/server/server.h"

TEST(server, run) {
	rover::server server;
	server.start();
}
