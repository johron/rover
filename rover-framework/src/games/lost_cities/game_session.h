#pragma once
#include "actions.h"
#include "deck.h"
#include "discard.h"
#include "player_controller.h"
#include "game_state.h"
#include "utils.h"

namespace rover::lost_cities {
namespace game_config {
constexpr auto starting_hand_size = 8;
}

struct game_session {
	game_session(std::unique_ptr<player_controller> player_1,
				 std::unique_ptr<player_controller> player_2,
				 unsigned int seed = util::time_based_seed())
		: m_player_1(std::move(player_1))
		, m_player_2(std::move(player_2))
		, m_state(m_player_1->m_id, m_player_2->m_id, make_deck(seed)) {}

	void run() {
		player_controller* active_player = m_player_1.get();
		player_controller* passive_player = m_player_2.get();

		for (auto i = 0; i < game_config::starting_hand_size; ++i) {
			m_state.execute(action::draw_from_deck(active_player->m_id));
			m_state.execute(action::draw_from_deck(passive_player->m_id));
		}

		while (!m_state.game_over()) {
			m_state.execute(active_player->play_action());
			m_state.execute(active_player->draw_action());
			std::swap(active_player, passive_player);
		}

		// report winner;
	}

private:
	std::unique_ptr<player_controller> m_player_1;
	std::unique_ptr<player_controller> m_player_2;
	game_state m_state;
};
}  // namespace rover::lost_cities