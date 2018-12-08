#include <rover/framework>
#include "../src/games/lost_cities/default_controller.h"

using namespace rover::lost_cities;

int main(/*int argc, char** argv*/) {
	game_session session(std::make_unique<default_controller>(0), std::make_unique<default_controller>(1), make_deck());

	session.run();

	return 0;
}