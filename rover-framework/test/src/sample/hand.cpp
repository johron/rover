#include "gtest/gtest.h"
#include "rover/framework.h"
#include "../src/games/lost_cities/hand.h"

using namespace rover::lost_cities;

TEST(hand, add_card) {
	hand player_hand;
	EXPECT_TRUE(player_hand.empty());
	EXPECT_EQ(player_hand.size(), 0);
	player_hand.add_card(card(color::blue, 2));
	EXPECT_FALSE(player_hand.empty());
	player_hand.add_card(card(color::green, 4));
	EXPECT_EQ(player_hand.size(), 2);
}
