#include "../src/games/lost_cities/game_state.h"
#include "gtest/gtest.h"
#include "rover/framework.h"

using namespace rover::lost_cities;

TEST(game_state, player) {
	game_state state(0, 1);
	auto player_1 = state.player(0);
	EXPECT_TRUE(player_1.has_value());
	EXPECT_EQ(player_1.value()->m_id, 0);
	auto player_2 = state.player(1);
	EXPECT_TRUE(player_2.has_value());
	EXPECT_EQ(player_2.value()->m_id, 1);
	auto invalid_player = state.player(99);
	EXPECT_FALSE(invalid_player.has_value());
}