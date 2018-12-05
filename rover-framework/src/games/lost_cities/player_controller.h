#pragma once
#include "player_state.h"
#include "actions.h"

namespace rover::lost_cities {
using player_id = int64_t;

struct player_controller {
	virtual ~player_controller() = default;

	player_id m_id;

	[[nodiscard]] virtual play_card_action play_action() = 0;
	[[nodiscard]] virtual draw_card_action draw_action() = 0;
};

}  // namespace rover::lost_cities