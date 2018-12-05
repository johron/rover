#pragma once
#include "actions.h"
#include "deck.h"
#include "discard.h"
#include "player_state.h"

namespace rover::lost_cities {
struct game_state {
	game_state(const player_id& player_1, const player_id& player_2, deck initial_deck = deck{})
		: m_deck{std::move(initial_deck)}
		, m_player_1(player_1)
		, m_player_2(player_2) {
		assert(player_1 != player_2 && "player id's needs to be different");
	}

	game_state(game_state&& copy) = delete;

	[[nodiscard]] std::optional<player_state*> player(const player_id& id) { 
		if (id == m_player_1.m_id) {
			return &m_player_1;
		} else if (id == m_player_2.m_id) {
			return &m_player_2;
		} else {
			assert("no player matching id");
			return std::optional<player_state*>();
		}
	}

	[[nodiscard]] bool game_over() const {
		return m_deck.empty();
	}

	void execute(play_card_action&& action) {
		[[maybe_unused]] const bool result = std::visit(action::runner{*this}, action);
		assert(result && "game_state::execute, failed to apply action");
	}

	void execute(draw_card_action&& action) {
		[[maybe_unused]] const bool result = std::visit(action::runner{*this}, action);
		assert(result && "game_state::execute, failed to apply action");
	}

	deck m_deck;
	discard_area m_discard;
	player_state m_player_1;
	player_state m_player_2;
};
}  // namespace rover::lost_cities