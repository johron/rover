#include "gtest/gtest.h"
#include "../src/games/lost_cities/game_state.h"

using namespace rover::lost_cities;

TEST(game_state, player_access) {
	game_state state(0, 1);
	EXPECT_TRUE(state.has_player(0));
	EXPECT_TRUE(state.has_player(1));
	EXPECT_FALSE(state.has_player(2));
	const auto& player_1 = state.player(0);
	EXPECT_EQ(player_1.id(), 0);
	const auto& player_2 = state.player(1);
	EXPECT_EQ(player_2.id(), 1);
}

TEST(game_state, player_access_const) {
	const game_state state(0, 1);
	EXPECT_TRUE(state.has_player(0));
	EXPECT_TRUE(state.has_player(1));
	EXPECT_FALSE(state.has_player(2));
	const auto& player_1 = state.player(0);
	EXPECT_EQ(player_1.id(), 0);
	const auto& player_2 = state.player(1);
	EXPECT_EQ(player_2.id(), 1);
}