#pragma once

#include "card_stack.h"
#include "cards.h"
#include "deck.h"
#include "discard.h"
#include "expedition.h"
#include "player_area.h"

namespace rover::lost_cities {
/*
struct play_card {};
struct discard_card {};
using player_action = std::variant<play_card, discard_card>;

namespace draw_source {
struct deck {};
template <color_t _color>
struct discard {};
}  // namespace draw_source

using player_draw = std::variant<draw_source::deck,
								 draw_source::discard<color::blue>,
								 draw_source::discard<color::green>,
								 draw_source::discard<color::red>,
								 draw_source::discard<color::yellow>,
								 draw_source::discard<color::white>>;

struct player_controller {
	virtual ~player_controller() = default;
	virtual player_action get_action() = 0;
	virtual player_draw get_draw_source() = 0;
};

struct game_state {
	game_state(long long seed) / * : m_deck{make_deck()}* / {
		//m_deck.shuffle(seed);
	}

	void apply_action(player_action&& action) {
	
	}

	void apply_draw(player_draw&& draw) {
	
	}

	bool is_finished() const {
		return false;
		//return m_deck.empty();
	}

private:
	//deck m_deck;
	//discard m_discard;
	player_state m_player_1_state;
	player_state m_player2_state;
};

struct game_session {
	game_session(long long seed,
				 std::unique_ptr<player_controller> player_1,
				 std::unique_ptr<player_controller> player_2)
		: m_game_state(seed), m_player_1(std::move(player_1)), m_player_2(std::move(player_2)) {
	}

	void run() {
		auto* active_player = m_player_1.get();
		auto* passive_player = m_player_2.get();
		while (!m_game_state.is_finished()) {
			m_game_state.apply_action(active_player->get_action());
			m_game_state.apply_draw(active_player->get_draw_source());
			std::swap(active_player, passive_player);
		}

		// report result
	}

private:
	game_state m_game_state;
	std::unique_ptr<player_controller> m_player_1;
	std::unique_ptr<player_controller> m_player_2;
};*/

}  // namespace rover::lost_cities
