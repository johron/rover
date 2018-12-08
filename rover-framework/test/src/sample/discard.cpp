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

TEST(discard_pile, add) {
	discard_pile blue_discard(color::blue);
	EXPECT_EQ(blue_discard.size(), 0);
	blue_discard.add(card(color::blue, 3));
	EXPECT_EQ(blue_discard.size(), 1);
}

TEST(discard_pile, top) {
	discard_pile blue_discard(color::blue);
	blue_discard.add(card(color::blue, 2));
	EXPECT_EQ(blue_discard.top(), card(color::blue, 2));
	discard_pile empty_discard(color::green);
	EXPECT_DEATH([[maybe_unused]] auto unused = empty_discard.top(), "discard::top, called on empty discard");
}

TEST(discard_pile, draw_card) {
	discard_pile blue_discard(color::blue);
	blue_discard.add(card(color::blue, 2));
	const auto top_card = blue_discard.draw();
	EXPECT_EQ(top_card, card(color::blue, 2));
	EXPECT_TRUE(blue_discard.empty());
	EXPECT_DEATH([[maybe_unused]] auto unused = blue_discard.draw(), "discard::draw, called on empty discard");
}

TEST(discard_area, add) {
	discard_area discard;
	discard.add(card(color::blue, 0));
	discard.add(card(color::green, 0));
	discard.add(card(color::red, 0));
	discard.add(card(color::yellow, 0));
	discard.add(card(color::white, 0));
}

TEST(discard_area, size) {
	discard_area discard;
	discard.add(card(color::blue, 0));
	discard.add(card(color::green, 0));
	discard.add(card(color::red, 0));
	discard.add(card(color::yellow, 0));
	discard.add(card(color::white, 0));

	EXPECT_EQ(discard.size(color::blue), 1);
	EXPECT_EQ(discard.size(color::green), 1);
	EXPECT_EQ(discard.size(color::red), 1);
	EXPECT_EQ(discard.size(color::yellow), 1);
	EXPECT_EQ(discard.size(color::white), 1);
}

TEST(discard_area, empty) {
	discard_area discard;
	discard.add(card(color::blue, 0));
	discard.add(card(color::green, 0));
	discard.add(card(color::yellow, 0));
	discard.add(card(color::white, 0));

	EXPECT_FALSE(discard.empty(color::blue));
	EXPECT_FALSE(discard.empty(color::green));
	EXPECT_TRUE(discard.empty(color::red));
	EXPECT_FALSE(discard.empty(color::yellow));
	EXPECT_FALSE(discard.empty(color::white));
}