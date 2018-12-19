#include <rover/framework>
#include "../src/server/server.h"

int main(/*int argc, char** argv*/) {
	rover::server server;
	server.start();
	return 0;
}