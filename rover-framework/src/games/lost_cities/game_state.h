#pragma once
#include "deck.h"
#include "discard.h"
#include "player_state.h"
#include "player_actions.h"

namespace rover::lost_cities {
struct action_runner {
	action_runner(game_state& state)
		: m_state(state) {}

	template <typename action_t>
	bool operator()(action_t& action) {
		return action.apply(m_state);
	}

	game_state& m_state;
};


struct game_state {
	game_state(const player_id& player_1, const player_id& player_2, deck initial_deck = deck{})
		: m_deck{std::move(initial_deck)}
		, m_player_1(player_1)
		, m_player_2(player_2) {
		assert(player_1 != player_2 && "player id's needs to be different");
	}

	game_state(game_state&& copy) = delete;

	const player_state& player(const player_id& id) const {
		assert(has_player(id) && "game_state::player, no player matching id");
		return m_player_1.id() == id ? m_player_1 : m_player_2;
	}

	player_state& player(const player_id& id) {
		assert(has_player(id) && "game_state::player, no player matching id");
		return m_player_1.id() == id ? m_player_1 : m_player_2;
	}

	[[nodiscard]] bool has_player(const player_id& id) const {
		return m_player_1.id() == id || m_player_2.id() == id;
	}

	[[nodiscard]] bool game_over() const {
		return m_deck.empty();
	}

	void execute(play_card_action&& action) {
		[[maybe_unused]] const bool result = std::visit(action_runner{*this}, action);
		assert(result && "game_state::execute, failed to apply action");
	}

	void execute(draw_card_action&& action) {
		[[maybe_unused]] const bool result = std::visit(action_runner{*this}, action);
		assert(result && "game_state::execute, failed to apply action");
	}

	deck m_deck;
	discard_area m_discard;
	player_state m_player_1;
	player_state m_player_2;
};

struct game_state_view {
	game_state_view(const game_state& state, const player_id& viewer_id, const player_id& opponent_id)
		: m_hand(state.player(viewer_id).hand())
		, m_player(state.player(viewer_id).expedition())
		, m_opponent(state.player(opponent_id).expedition())
		, m_discard(state.m_discard)
		, m_deck_size(state.m_deck.size()) { }

	[[nodiscard]] const player_hand& hand() const {
		return m_hand;
	}

	[[nodiscard]] const expedition_area& player_area() const {
		return m_player;
	}
	
	[[nodiscard]] const expedition_area& opponent_area() const {
		return m_opponent; 
	}

	[[nodiscard]] const discard_area& discard() const {
		return m_discard;
	}

	[[nodiscard]] size_t deck_size() const {
		return m_deck_size;
	} 

private:
	player_hand m_hand;
	expedition_area m_player;
	expedition_area m_opponent;
	discard_area m_discard;
	size_t m_deck_size;
};
}  // namespace rover::lost_cities