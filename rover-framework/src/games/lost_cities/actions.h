#pragma once
#include "utils.h"
#include "cards.h"
#include "player_state.h"

namespace rover::lost_cities {
struct game_state;
namespace action {
namespace details {
struct hand_to_expedition {
	hand_to_expedition(const player_id& id, const card& card);
	[[nodiscard]] bool apply(game_state & state);
	player_id m_id;
	card m_card;
};

struct hand_to_discard {
	hand_to_discard(const player_id& id, const card& card);
	[[nodiscard]] bool apply(game_state& state);

	player_id m_id;
	card m_card;
};

struct hand_to_discard_random {
	hand_to_discard_random(const player_id& id, uint32_t seed = util::time_based_seed());
	[[nodiscard]] bool apply(game_state& state);

	player_id m_id;
	uint32_t m_seed;
};

struct deck_to_hand {
	deck_to_hand(const player_id& id);
	[[nodiscard]] bool apply(game_state& state);

	player_id m_id;
};

struct discard_to_hand {
	discard_to_hand(const player_id& id, color_t color);
	bool apply(game_state& state);

	player_id m_id;
	color_t m_color;
};
}  // namespace details

using player_action = std::variant<details::hand_to_expedition,
								   details::hand_to_discard,
								   details::hand_to_discard_random,
								   details::deck_to_hand,
								   details::discard_to_hand>;
struct runner {
	runner(game_state& state)
		: m_state(state) {}

	template <typename action_t>
	bool operator()(action_t& action) {
		return action.apply(m_state);
	}

	game_state& m_state;
};

struct fallback_action {
	fallback_action(player_action&& primary, player_action&& fallback)
		: m_primary(std::move(primary))
		, m_fallback(std::move(fallback)) {}

	bool apply(game_state& state) {
		return std::visit(runner{state}, m_primary) ? true : std::visit(runner{state}, m_fallback);
	}

	player_action m_primary;
	player_action m_fallback;
};


struct play_to_expedition : public fallback_action {
	play_to_expedition(const player_id& id, const card& card)
		: fallback_action(details::hand_to_expedition(id, card), details::hand_to_discard_random(id)) {}
};

struct play_to_discard : public fallback_action {
	play_to_discard(const player_id& id, const card& card)
		: fallback_action(details::hand_to_discard(id, card), details::hand_to_discard_random(id)) {}
};

struct draw_from_discard : public fallback_action {
	draw_from_discard(const player_id& id, const color_t& color)
		: fallback_action(details::discard_to_hand(id, color), details::deck_to_hand(id)) {}
};

using draw_from_deck = details::deck_to_hand;
}  // namespace action

using play_card_action = std::variant<action::play_to_expedition, action::play_to_discard>;
using draw_card_action = std::variant<action::draw_from_discard, action::draw_from_deck>;
}  // namespace rover::lost_cities