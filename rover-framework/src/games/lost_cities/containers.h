#pragma once
#include "cards.h"

namespace rover::lost_cities {
template <typename container_t>
struct stack_group {
	stack_group()
		: m_cards{container_t(color::blue),
				  container_t(color::green),
				  container_t(color::red),
				  container_t(color::yellow),
				  container_t(color::white)} {}

	[[nodiscard]] size_t size(color_t color) const {
		return m_cards[color].size();
	}

	[[nodiscard]] bool empty(color_t color) const { 
		return m_cards[color].empty(); 
	}

	[[nodiscard]] bool can_add(const card& card) const {
		return m_cards[card.color()].can_add(card);
	}

	void add_card(card&& card) { 
		m_cards[card.color()].add_card(std::move(card));
	}

protected:
	std::array<container_t, color::__size__> m_cards;
};


struct card_area {
	virtual ~card_area() = default;

	void add_card(card&& card) {
		assert(can_add(card) && "expedition::add() called with incorrect color");
		m_cards.emplace_back(std::move(card));
	}

	[[nodiscard]] virtual bool can_add(const card& card) const  = 0;

	[[nodiscard]] size_t size() const {
		return m_cards.size();
	}

	[[nodiscard]] bool empty() const { 
		return m_cards.empty(); 
	}

protected: 
	std::vector<card> m_cards;
};

struct colored_card_area : public card_area {
	explicit colored_card_area(color_t color) 
		: m_color(color) {}

	[[nodiscard]] const color_t& color() const {
		return m_color;
	}

protected:
	color_t m_color;

};
}  // namespace rover::lost_cities