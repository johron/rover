#pragma once
#include "expedition.h"
#include "player_hand.h"

namespace rover::lost_cities {
using player_id = int64_t;

struct player_state {
	player_state(const player_id& id)
		: m_id(id) {}

	[[nodiscard]] const player_id& id() const {
		return m_id;
	}

	[[nodiscard]] const player_hand& hand() const {
		return m_hand;
	}

	[[nodiscard]] player_hand& hand() {
		return m_hand;
	}

	[[nodiscard]] const expedition_area& expedition() const {
		return m_expeditions;
	}

	[[nodiscard]] expedition_area& expedition() {
		return m_expeditions;
	}

private:
	player_id m_id;
	player_hand m_hand;
	expedition_area m_expeditions;
};
}  // namespace rover::lost_cities