#pragma once
#include "expedition.h"
#include "hand.h"

namespace rover::lost_cities {
using player_id = int64_t;

struct player_state {
	player_state(const player_id& id)
		: m_id(id) {}

	player_id m_id;
	hand m_hand;
	expedition_area m_expeditions;
};

}  // namespace rover::lost_cities