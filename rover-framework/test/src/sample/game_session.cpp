#include "gtest/gtest.h"
#include "rover/framework.h"
#include "../src/games/lost_cities/default_controller.h"

using namespace rover::lost_cities;

TEST(game_session, run_session) {
	game_session session(std::make_unique<default_controller>(0), std::make_unique<default_controller>(1), test_deck());
	session.run();
	const auto result = session.result();
	EXPECT_EQ(result.m_scores[0].second, 14);
	EXPECT_EQ(result.m_scores[1].second, 18);
}