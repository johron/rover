#pragma once
#include "player_state.h"
#include "player_actions.h"

namespace rover::lost_cities {
using player_id = int64_t;
struct game_state_view;

struct player_controller {
	explicit player_controller(const player_id& id)
		: m_id(id) {}
	virtual ~player_controller() = default;

	[[nodiscard]] const player_id& id() const { return m_id; }
	[[nodiscard]] virtual play_card_action play_action(const game_state_view& /*state_view*/) = 0;
	[[nodiscard]] virtual draw_card_action draw_action(const game_state_view& /*state_view*/) = 0;

private:
	player_id m_id;
};

}  // namespace rover::lost_cities