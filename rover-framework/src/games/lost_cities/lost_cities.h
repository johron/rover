#pragma once

#include "cards.h"
#include "deck.h"
#include "discard.h"
#include "expedition.h"

namespace rover::lost_cities {
struct player_controller {};

static const auto starting_hand_size = 8;

struct game_session {
	game_session(std::unique_ptr<player_controller> player_1, std::unique_ptr<player_controller> player_2)
		: m_player_1(std::move(player_1))
		, m_player_2(std::move(player_2))
		, m_deck(make_deck()) {}

	void run() {
		player_controller* active_player = m_player_1.get();
		player_controller* passive_player = m_player_2.get();
		
		for (auto i = 0; i < starting_hand_size; ++i) {
			// draw initial hand
		}
		
		while (!m_deck.empty()) {
			//active_player->play_action();
			//active_player->draw_action();
			std::swap(active_player, passive_player);
		}

		// report winner;
	}

private:
	std::unique_ptr<player_controller> m_player_1;
	std::unique_ptr<player_controller> m_player_2;
	deck m_deck;
	discard_area m_discard;
	expedition_area m_player_1_area;
	expedition_area m_player_2_area;
};

}  // namespace rover::lost_cities
