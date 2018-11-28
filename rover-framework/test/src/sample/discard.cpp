#include "gtest/gtest.h"
#include "rover/framework.h"

using namespace rover::lost_cities;

TEST(discard, empty) {
	const discard empty_discard(color::blue);
	EXPECT_TRUE(empty_discard.empty());
}

TEST(discard, can_add) {
	const discard blue_discard(color::blue);
	EXPECT_FALSE(blue_discard.can_add(card(color::green, 2)));
	EXPECT_TRUE(blue_discard.can_add(card(color::blue, 2)));
}

TEST(discard, add_card) {
	discard blue_discard(color::blue);
	EXPECT_EQ(blue_discard.size(), 0);
	blue_discard.add_card(card(color::blue, 3));
	EXPECT_EQ(blue_discard.size(), 1);
}

TEST(discard, top) {
	discard blue_discard(color::blue);
	blue_discard.add_card(card(color::blue, 2));
	EXPECT_EQ(blue_discard.top(), card(color::blue, 2));
}