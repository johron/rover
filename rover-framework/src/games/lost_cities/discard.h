#pragma once
#include "containers.h"

namespace rover::lost_cities {
struct discard_pile : public card_stack {
	explicit discard_pile(const color_t& color)
		: card_stack(color, [this](const card& card) { return card.color() == m_color; }) {}

	[[nodiscard]] const card& top() const {
		assert(!empty() && "discard::top() called on empty discard");
		return m_cards.back();
	}

	[[nodiscard]] card&& draw() {
		assert(!empty() && "discard::draw() called on empty discard");
		card card = m_cards.back();
		m_cards.pop_back();
		return std::move(card);
	}
};

struct discard_area : public stack_group<discard_pile> {
	void add_card(card&& card) {
		m_cards[card.color()].add_card(std::move(card));
	}

	[[nodiscard]] const card& top(color_t color) const {
		return m_cards[color].top();
	}

	[[nodiscard]] card&& draw(color_t color) { 
		return m_cards[color].draw();
	}
};
}  // namespace rover::lost_cities