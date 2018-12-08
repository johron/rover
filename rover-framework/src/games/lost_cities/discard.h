#pragma once
#include "containers.h"

namespace rover::lost_cities {
struct discard_pile : public colored_card_area {
	explicit discard_pile(const color_t& color)
		: colored_card_area(color) {}

	[[nodiscard]] const card& top() const {
		assert(!empty() && "discard::top, called on empty discard");
		return m_cards.back();
	}

	[[nodiscard]] card draw() {
		assert(!empty() && "discard::draw, called on empty discard");
		card card = m_cards.back();
		m_cards.pop_back();
		return card;
	}

	[[nodiscard]] virtual bool can_add(const card& card) const override {
		return card.color() == m_color;
	}
};

struct discard_area : public stack_group<discard_pile> {
	void add(card&& card) {
		m_cards[card.color()].add(std::move(card));
	}

	[[nodiscard]] const card& top(color_t color) const {
		return m_cards[color].top();
	}

	[[nodiscard]] card draw(color_t color) { 
		return m_cards[color].draw();
	}
};
}  // namespace rover::lost_cities