#pragma once
#include "discard.h"
#include "expedition.h"

namespace rover::lost_cities {
struct player_state {
	player_state(discard_area& discard)
		: m_discard(discard) {}

	discard_area& m_discard;
	expedition_area m_expeditions;
};

struct game_state {
	template <class action_t>
	void execute(action_t&& action) {

	}
};
}  // namespace rover::lost_cities