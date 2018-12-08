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
	expedition.add(card(color::blue, 0));
	EXPECT_FALSE(expedition.empty());
}

TEST(expedition, add) {
	expedition expedition(color::blue);
	expedition.add(card(color::blue, 2));
	expedition.add(card(color::blue, 3));
	EXPECT_EQ(expedition.size(), 2);
}

TEST(expedition, can_add) {
	expedition expedition(color::blue);
	EXPECT_TRUE(expedition.can_add(card(color::blue, 0)));
	EXPECT_FALSE(expedition.can_add(card(color::green, 0)));

	expedition.add(card(color::blue, 2));
	EXPECT_FALSE(expedition.can_add(card(color::blue, 0)));
	EXPECT_TRUE(expedition.can_add(card(color::blue, 3)));
}

TEST(expedition, score_empty) {
	expedition expedition(color::blue);
	EXPECT_EQ(expedition.score(), 0);
}

TEST(expedition, score_minimum) {
	expedition expedition(color::blue);
	expedition.add(card(color::blue, 0));
	expedition.add(card(color::blue, 0));
	expedition.add(card(color::blue, 0));
	EXPECT_EQ(expedition.score(), -80);
}

TEST(expedition, score_maximum) {
	expedition expedition(color::blue);
	expedition.add(card(color::blue, 0));
	expedition.add(card(color::blue, 0));
	expedition.add(card(color::blue, 0));
	expedition.add(card(color::blue, 2));
	expedition.add(card(color::blue, 3));
	expedition.add(card(color::blue, 4));
	expedition.add(card(color::blue, 5));
	expedition.add(card(color::blue, 6));
	expedition.add(card(color::blue, 7));
	expedition.add(card(color::blue, 8));
	expedition.add(card(color::blue, 9));
	expedition.add(card(color::blue, 10));
	EXPECT_EQ(expedition.score(), 156);
}

TEST(expedition_area, score_total) {
	expedition_area area;
	area.add(card(color::blue, 0));
	area.add(card(color::blue, 0));
	area.add(card(color::blue, 0));
	area.add(card(color::blue, 2));
	area.add(card(color::blue, 3));
	area.add(card(color::blue, 4));
	area.add(card(color::blue, 5));
	area.add(card(color::blue, 6));
	area.add(card(color::blue, 7));
	area.add(card(color::blue, 8));
	area.add(card(color::blue, 9));
	area.add(card(color::blue, 10));

	area.add(card(color::green, 0));
	area.add(card(color::green, 0));
	area.add(card(color::green, 0));

	area.add(card(color::red, 5));
	EXPECT_EQ(area.total_score(), 156 - 80 - 15);
}