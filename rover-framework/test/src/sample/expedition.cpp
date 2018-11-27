#include "gtest/gtest.h"
#include "rover/framework.h"

using namespace rover::lost_cities;

TEST(expedition, color) {
	expedition expedition(color::blue);
	EXPECT_EQ(expedition.color(), color::blue);
	EXPECT_NE(expedition.color(), color::green);
}

TEST(expedition, size) {
	expedition expedition(color::blue);
	EXPECT_EQ(expedition.size(), 0);
}

TEST(expedition, empty) {
	expedition expedition(color::blue);
	EXPECT_TRUE(expedition.empty());
	expedition.add_card(card(color::blue, 0));
	EXPECT_FALSE(expedition.empty());
}

TEST(expedition, add_card) {
	expedition expedition(color::blue);
	expedition.add_card(card(color::blue, 2));
	expedition.add_card(card(color::blue, 3));
	EXPECT_EQ(expedition.size(), 2);
}

TEST(expedition, can_add) {
	expedition expedition(color::blue);
	EXPECT_TRUE(expedition.can_add(card(color::blue, 0)));
	EXPECT_FALSE(expedition.can_add(card(color::green, 0)));

	expedition.add_card(card(color::blue, 2));
	EXPECT_FALSE(expedition.can_add(card(color::blue, 0)));
	EXPECT_TRUE(expedition.can_add(card(color::blue, 3)));
}

TEST(expedition, score_empty) {
	expedition expedition(color::blue);
	EXPECT_EQ(expedition.score(), 0);
}

TEST(expedition, score_minimum) {
	expedition expedition(color::blue);
	expedition.add_card(card(color::blue, 0));
	expedition.add_card(card(color::blue, 0));
	expedition.add_card(card(color::blue, 0));
	EXPECT_EQ(expedition.score(), -80);
}

TEST(expedition, score_maximum) {
	expedition expedition(color::blue);
	expedition.add_card(card(color::blue, 0));
	expedition.add_card(card(color::blue, 0));
	expedition.add_card(card(color::blue, 0));
	expedition.add_card(card(color::blue, 2));
	expedition.add_card(card(color::blue, 3));
	expedition.add_card(card(color::blue, 4));
	expedition.add_card(card(color::blue, 5));
	expedition.add_card(card(color::blue, 6));
	expedition.add_card(card(color::blue, 7));
	expedition.add_card(card(color::blue, 8));
	expedition.add_card(card(color::blue, 9));
	expedition.add_card(card(color::blue, 10));
	EXPECT_EQ(expedition.score(), 156);
}