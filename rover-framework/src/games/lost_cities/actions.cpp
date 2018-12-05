#include "actions.h"
#include "game_state.h"

namespace rover::lost_cities::action::details {
hand_to_expedition::hand_to_expedition(const player_id& id, const card& card)
	: m_id(id)
	, m_card(card) {}

bool hand_to_expedition::apply(game_state& state) {
	auto player = state.player(m_id);
	if (!player.has_value()) {
		return false;
	}

	auto& hand = (*player)->m_hand;
	if (!hand.contains(m_card)) {
		return false;
	}

	auto& expedition = (*player)->m_expeditions;
	if (!expedition.can_add(m_card)) {
		return false;
	}

	hand.remove_card(m_card);
	expedition.add_card(std::move(m_card));
	return true;
}

hand_to_discard::hand_to_discard(const player_id& id, const card& card)
	: m_id(id)
	, m_card(card) {}

bool hand_to_discard::apply(game_state& state) {
	auto player = state.player(m_id);
	if (!player.has_value()) {
		return false;
	}

	auto& hand = (*player)->m_hand;
	if (!hand.contains(m_card)) {
		return false;
	}

	auto& discard = state.m_discard;
	hand.remove_card(m_card);
	discard.add_card(std::move(m_card));
	return true;
}

hand_to_discard_random::hand_to_discard_random(const player_id& id, uint32_t seed)
	: m_id(id)
	, m_seed(seed) {}

bool hand_to_discard_random::apply(game_state& state) {
	auto player = state.player(m_id);
	if (!player.has_value()) {
		return false;
	}

	auto& hand = (*player)->m_hand;
	if (hand.empty()) {
		return false;
	}

	auto card = hand.random_card(m_seed);
	hand.remove_card(card);
	auto& discard = state.m_discard;
	discard.add_card(std::move(card));
	return true;
}

deck_to_hand::deck_to_hand(const player_id& id)
	: m_id(id) {}

bool deck_to_hand::apply(game_state& state) {
	if (state.m_deck.empty()) {
		return false;
	}

	auto player = state.player(m_id);
	if (!player.has_value()) {
		return false;
	}

	(*player)->m_hand.add_card(state.m_deck.draw());
	return true;
}

discard_to_hand::discard_to_hand(const player_id& id, color_t color)
	: m_id(id)
	, m_color(color) {}

bool discard_to_hand::apply(game_state& state) {
	auto& discard = state.m_discard;
	if (discard.empty(m_color)) {
		return false;
	}

	auto player = state.player(m_id);
	if (!player.has_value()) {
		return false;
	}

	(*player)->m_hand.add_card(discard.draw(m_color));
	return true;
}
}  // namespace rover::lost_cities::action::details
