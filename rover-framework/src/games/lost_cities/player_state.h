#pragma once
#include "discard.h"
#include "expedition.h"

namespace rover::lost_cities {
struct player_state {
	player_state(discard_area& discard)
		: m_discard(discard) {}

private:
	discard_area& m_discard;
	expedition_area m_expeditions;
};
}  // namespace rover::lost_cities