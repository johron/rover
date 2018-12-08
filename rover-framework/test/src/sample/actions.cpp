#include "gtest/gtest.h"
#include "rover/framework.h"

using namespace rover::lost_cities;

TEST(actions, play_to_expedition_success) {
	constexpr auto player_1_id = 0;
	constexpr auto player_2_id = 1;
	game_state state(player_1_id, player_2_id);
	auto& player = state.player(player_1_id);
	player.hand().add(card(color::blue, 2));
	player.hand().add(card(color::blue, 3));
	EXPECT_EQ(player.hand().size(), 2);
	EXPECT_EQ(player.expedition().total_score(), 0);
	state.execute(action::play_to_expedition(player.id(), card(color::blue, 2)));
	EXPECT_EQ(player.hand().size(), 1);
	EXPECT_EQ(player.expedition().total_score(), -18);
	state.execute(action::play_to_expedition(player.id(), card(color::blue, 3)));
	EXPECT_EQ(player.hand().size(), 0);
	EXPECT_EQ(player.expedition().total_score(), -15);
}

TEST(actions, play_to_expedition_wrong_card) {
	constexpr auto player_1_id = 0;
	constexpr auto player_2_id = 1;
	game_state state(player_1_id, player_2_id);
	auto& player = state.player(player_1_id);
	player.hand().add(card(color::blue, 2));
	EXPECT_EQ(player.hand().size(), 1);
	EXPECT_EQ(player.expedition().total_score(), 0);
	// attempting to play a card that is not in the players player_hand should
	// result in the player_area discarding a random card
	state.execute(action::play_to_expedition(player.id(), card(color::green, 8)));
	EXPECT_EQ(player.hand().size(), 0);
	EXPECT_EQ(player.expedition().total_score(), 0);
	const auto& top_blue_discard = state.m_discard.top(color::blue);
	EXPECT_TRUE(top_blue_discard == card(color::blue, 2));
}

TEST(actions, play_to_expedition_wrong_player_id) {
	constexpr auto player_1_id = 0;
	constexpr auto player_2_id = 1;
	game_state state(player_1_id, player_2_id);
	auto& player = state.player(player_1_id);
	player.hand().add(card(color::blue, 2));
	// attempting to execute an action with incorrect player_area id will trigger an assert
	EXPECT_DEATH(state.execute(action::play_to_expedition(99, card(color::green, 8))), "game_state::execute, failed to apply action");
}

TEST(actions, play_to_expedition_ineligible_card) {
	constexpr auto player_1_id = 0;
	constexpr auto player_2_id = 1;
	game_state state(player_1_id, player_2_id);
	auto& player = state.player(player_1_id);
	player.hand().add(card(color::blue, 2));
	EXPECT_EQ(player.hand().size(), 1);
	EXPECT_EQ(state.m_discard.size(color::blue), 0);
	player.expedition().add(card(color::blue, 3));
	state.execute(action::play_to_expedition(player.id(), card(color::blue, 2)));
	// attempting to play a card, but it's ineligible due to a higher card 
	// already being the top card in that expedition should result in the player_area
	// discarding a random card
	EXPECT_EQ(player.hand().size(), 0);
	EXPECT_EQ(state.m_discard.size(color::blue), 1);
}

TEST(actions, discard_card_success) {
	constexpr auto player_1_id = 0;
	constexpr auto player_2_id = 1;
	game_state state(player_1_id, player_2_id);
	auto& player = state.player(player_1_id);
	player.hand().add(card(color::blue, 2));
	player.hand().add(card(color::blue, 3));
	EXPECT_EQ(player.hand().size(), 2);
	EXPECT_EQ(state.m_discard.size(color::blue), 0);
	state.execute(action::play_to_discard(player.id(), card(color::blue, 2)));
	EXPECT_EQ(player.hand().size(), 1);
	EXPECT_EQ(state.m_discard.size(color::blue), 1);
	EXPECT_EQ(state.m_discard.top(color::blue), card(color::blue, 2));
}

TEST(actions, discard_card_wrong_card) {
	constexpr auto player_1_id = 0;
	constexpr auto player_2_id = 1;
	game_state state(player_1_id, player_2_id);
	auto& player = state.player(player_1_id);
	player.hand().add(card(color::blue, 2));
	EXPECT_EQ(player.hand().size(), 1);
	EXPECT_EQ(state.m_discard.size(color::blue), 0);
	// attempting to play a card that is not in the players player_hand should
	// result in the player_area discarding a random card
	state.execute(action::play_to_discard(player.id(), card(color::green, 8)));
	EXPECT_EQ(player.hand().size(), 0);
	EXPECT_EQ(state.m_discard.size(color::blue), 1);
	EXPECT_EQ(state.m_discard.top(color::blue), card(color::blue, 2));
}

TEST(actions, discard_card_wrong_player_id) {
	constexpr auto player_1_id = 0;
	constexpr auto player_2_id = 1;
	game_state state(player_1_id, player_2_id);
	auto& player = state.player(player_1_id);
	player.hand().add(card(color::blue, 2));
	EXPECT_DEATH(state.execute(action::play_to_discard(99, card(color::blue, 2))), "game_state::execute, failed to apply action");
}

TEST(actions, draw_card_from_deck) {
	constexpr auto player_1_id = 0;
	constexpr auto player_2_id = 1;
	auto deck = {card(color::blue, 2)};
	game_state state(player_1_id, player_2_id, std::move(deck));
	auto& player = state.player(player_1_id);
	EXPECT_EQ(player.hand().size(), 0);
	state.execute(action::draw_from_deck(player.id()));
	EXPECT_EQ(player.hand().size(), 1);
	EXPECT_TRUE(player.hand().contains(card(color::blue, 2)));
}

TEST(actions, draw_card_from_discard_success) {
	constexpr auto player_1_id = 0;
	constexpr auto player_2_id = 1;
	game_state state(player_1_id, player_2_id);
	state.m_discard.add(card(color::blue, 2));
	auto& player = state.player(player_1_id);
	EXPECT_EQ(player.hand().size(), 0);
	EXPECT_EQ(state.m_discard.size(color::blue), 1);
	state.execute(action::draw_from_discard(player.id(), color::blue));
	EXPECT_EQ(player.hand().size(), 1);
	EXPECT_TRUE(player.hand().contains(card(color::blue, 2)));
	EXPECT_EQ(state.m_discard.size(color::blue), 0);
}

TEST(actions, draw_card_from_discard_failiure) {
	constexpr auto player_1_id = 0;
	constexpr auto player_2_id = 1;
	auto deck = {card(color::blue, 2)};
	game_state state(player_1_id, player_2_id, std::move(deck));
	auto& player = state.player(player_1_id);
	EXPECT_EQ(player.hand().size(), 0);
	EXPECT_EQ(state.m_discard.size(color::green), 0);
	// attempting to draw from a discard that is empty should
	// result in the player_area drawing form the deck instead
	state.execute(action::draw_from_discard(player.id(), color::green));
	EXPECT_EQ(player.hand().size(), 1);
	EXPECT_TRUE(player.hand().contains(card(color::blue, 2)));
}