#include "gtest/gtest.h"
#include "rover/framework.h"

using namespace rover::lost_cities;

TEST(player_hand, add) {
	player_hand player_hand;
	EXPECT_TRUE(player_hand.empty());
	EXPECT_EQ(player_hand.size(), 0);
	player_hand.add(card(color::blue, 2));
	EXPECT_FALSE(player_hand.empty());
	player_hand.add(card(color::green, 4));
	EXPECT_EQ(player_hand.size(), 2);
}

TEST(player_hand, remove_card) {
	player_hand player_hand;
	player_hand.add(card(color::blue, 2));
	EXPECT_TRUE(player_hand.contains(card(color::blue, 2)));
	EXPECT_FALSE(player_hand.contains(card(color::blue, 3)));
	EXPECT_EQ(player_hand.size(), 1);
	player_hand.remove_card(card(color::blue, 2));
	EXPECT_FALSE(player_hand.contains(card(color::blue, 2)));
	EXPECT_EQ(player_hand.size(), 0);
}
