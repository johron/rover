#include "gtest/gtest.h"
#include "rover/framework.h"

using namespace rover::lost_cities;

TEST(discard_pile, empty) {
	const discard_pile empty_discard(color::blue);
	EXPECT_TRUE(empty_discard.empty());
}

TEST(discard_pile, can_add) {
	const discard_pile blue_discard(color::blue);
	EXPECT_FALSE(blue_discard.can_add(card(color::green, 2)));
	EXPECT_TRUE(blue_discard.can_add(card(color::blue, 2)));
}

TEST(discard_pile, add_card) {
	discard_pile blue_discard(color::blue);
	EXPECT_EQ(blue_discard.size(), 0);
	blue_discard.add_card(card(color::blue, 3));
	EXPECT_EQ(blue_discard.size(), 1);
}

TEST(discard_pile, top) {
	discard_pile blue_discard(color::blue);
	blue_discard.add_card(card(color::blue, 2));
	EXPECT_EQ(blue_discard.top(), card(color::blue, 2));
}

TEST(discard_area, add_card) {
	discard_area area;
	area.add_card(card(color::blue, 0));
	area.add_card(card(color::green, 0));
	area.add_card(card(color::red, 0));
	area.add_card(card(color::yellow, 0));
	area.add_card(card(color::white, 0));
}

TEST(discard_area, size) {
	discard_area area;
	area.add_card(card(color::blue, 0));
	area.add_card(card(color::green, 0));
	area.add_card(card(color::red, 0));
	area.add_card(card(color::yellow, 0));
	area.add_card(card(color::white, 0));

	EXPECT_EQ(area.size(color::blue), 1);
	EXPECT_EQ(area.size(color::green), 1);
	EXPECT_EQ(area.size(color::red), 1);
	EXPECT_EQ(area.size(color::yellow), 1);
	EXPECT_EQ(area.size(color::white), 1);
}

TEST(discard_area, empty) {
	discard_area area;
	area.add_card(card(color::blue, 0));
	area.add_card(card(color::green, 0));
	area.add_card(card(color::yellow, 0));
	area.add_card(card(color::white, 0));

	EXPECT_FALSE(area.empty(color::blue));
	EXPECT_FALSE(area.empty(color::green));
	EXPECT_TRUE(area.empty(color::red));
	EXPECT_FALSE(area.empty(color::yellow));
	EXPECT_FALSE(area.empty(color::white));
}