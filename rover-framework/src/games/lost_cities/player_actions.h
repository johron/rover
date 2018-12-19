#pragma once
#include "action_detail.h"

namespace rover::lost_cities {
namespace action {
template <class primary_t, class fallback_t>
struct fallback_action {
	fallback_action(primary_t&& primary, fallback_t&& fallback)
		: m_primary(std::move(primary))
		, m_fallback(std::move(fallback)) {}

	template <class state>
	bool apply(state& game_state) {
		return m_primary.apply(game_state) ? true : m_fallback.apply(game_state);
	}

	primary_t m_primary;
	fallback_t m_fallback;
};

struct play_to_expedition : public fallback_action<detail::hand_to_expedition, detail::hand_to_discard_random> {
	play_to_expedition(const player_id& id, const card& card)
		: fallback_action(detail::hand_to_expedition(id, card), detail::hand_to_discard_random(id)) {}
};

struct play_to_discard : public fallback_action<detail::hand_to_discard, detail::hand_to_discard_random> {
	play_to_discard(const player_id& id, const card& card)
		: fallback_action(detail::hand_to_discard(id, card), detail::hand_to_discard_random(id)) {}
};

struct draw_from_discard : public fallback_action<detail::discard_to_hand, detail::deck_to_hand> {
	draw_from_discard(const player_id& id, const color_t& color)
		: fallback_action(detail::discard_to_hand(id, color), detail::deck_to_hand(id)) {}
};

using draw_from_deck = detail::deck_to_hand;
}  // namespace action

using play_card_action = std::variant<action::play_to_expedition, action::play_to_discard>;
using draw_card_action = std::variant<action::draw_from_discard, action::draw_from_deck>;
}  // namespace rover::lost_cities