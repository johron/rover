#pragma once
#include "cards.h"
#include "player_state.h"
#include "utils.h"

namespace rover::lost_cities {
struct game_state;
}  // namespace rover::lost_cities

namespace rover::lost_cities::action::detail {
struct hand_to_expedition {
	hand_to_expedition(const player_id& id, const card& card);
	[[nodiscard]] bool apply(game_state& state);
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
}  // namespace rover::lost_cities::action::details
