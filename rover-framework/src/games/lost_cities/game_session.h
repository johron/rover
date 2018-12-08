#pragma once
#include "action_detail.h"
#include "deck.h"
#include "discard.h"
#include "player_controller.h"
#include "game_state.h"
#include "utils.h"

namespace rover::lost_cities {
namespace game_config {
constexpr size_t starting_hand_size = 8;
}

struct game_result {
	using player_result = std::pair<player_id, int>;
	std::array<player_result, 2> m_scores;
};

struct game_session {
	game_session(std::unique_ptr<player_controller> player_1,
				 std::unique_ptr<player_controller> player_2,
				 deck&& deck)
		: m_player_1(std::move(player_1))
		, m_player_2(std::move(player_2))
		, m_state(m_player_1->id(), m_player_2->id(), std::move(deck)) {}

	void run() {
		player_controller* active_player = m_player_1.get();
		player_controller* passive_player = m_player_2.get();

		for (size_t i = 0; i < game_config::starting_hand_size; ++i) {
			m_state.execute(action::draw_from_deck(active_player->id()));
			m_state.execute(action::draw_from_deck(passive_player->id()));
		}

		while (!m_state.game_over()) {
			const game_state_view game_state(m_state, active_player->id(), passive_player->id());
			m_state.execute(active_player->play_action(game_state));
			m_state.execute(active_player->draw_action(game_state));
			std::swap(active_player, passive_player);
		}
	}

	game_result result() const { 
		const auto player_1_score = m_state.player(m_player_1->id()).expedition().total_score();
		const auto player_2_score = m_state.player(m_player_2->id()).expedition().total_score();
		return {std::make_pair(m_player_1->id(), player_1_score),
				std::make_pair(m_player_2->id(), player_2_score)};
	}

private:
	std::unique_ptr<player_controller> m_player_1;
	std::unique_ptr<player_controller> m_player_2;
	game_state m_state;
};
}  // namespace rover::lost_cities