#pragma once
#include "player_controller.h"
#include "game_state.h"

namespace rover::lost_cities {
struct default_controller : public player_controller {
	explicit default_controller(const player_id& id)
		: player_controller(id){}

	[[nodiscard]] play_card_action play_action(const game_state_view& state_view) override {
		auto hand = state_view.hand();
		std::sort(hand.begin(), hand.end(), [](const card& lhs, const card& rhs) {
			return lhs.value() < rhs.value();
		});

		auto& expedition = state_view.player_area();
		for (const auto& card : hand) {
			if (expedition.can_add(card)) {
				return action::play_to_expedition(id(), card);
			}
		}

		return action::play_to_discard(id(), hand[0]);
	}

	[[nodiscard]] draw_card_action draw_action(const game_state_view& /*state_view*/) override {
		return action::draw_from_deck(id());
	}
};
}