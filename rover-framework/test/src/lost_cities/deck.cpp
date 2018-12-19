#include "gtest/gtest.h"
#include "../src/games/lost_cities/deck.h"

using namespace rover::lost_cities;

TEST(deck, empty) {
	deck empty_deck{};
	EXPECT_EQ(empty_deck.size(), 0);
	EXPECT_TRUE(empty_deck.empty());
}

TEST(deck, make_deck) {
	const auto deck = make_deck();
	EXPECT_EQ(deck.size(), 60);
}

TEST(deck, peek) {
	auto one_card_deck = deck{card(color::green, 2)};
	EXPECT_EQ(one_card_deck.peek(), card(color::green, 2));

	auto empty_deck = deck{};
	EXPECT_DEATH([[maybe_unused]] const auto& unused = empty_deck.peek(), "peeking on empty deck");
}

TEST(deck, shuffle) {
	auto deck = make_deck();
	const auto top_card = deck.peek();
	deck.shuffle(0);
	EXPECT_NE(top_card, deck.peek());
}

TEST(deck, draw) {
	auto deck = make_deck();
	const size_t initial_size = deck.size();
	for (size_t i = 1; i <= initial_size; ++i) {
		const auto top_card = deck.peek();
		const auto drawn_card = deck.draw();
		EXPECT_EQ(deck.size(), initial_size - i);
		EXPECT_EQ(drawn_card, top_card);
	}

	EXPECT_TRUE(deck.empty());
	EXPECT_DEATH([[maybe_unused]] const auto unused = deck.draw(), "drawing card from empty deck");
}