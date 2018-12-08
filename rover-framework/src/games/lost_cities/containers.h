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

	void add(card&& card) { 
		m_cards[card.color()].add(std::move(card));
	}

protected:
	std::array<container_t, color::__size__> m_cards;
};

struct card_storage {
	card_storage(std::initializer_list<card>&& content = {})
		: m_cards(std::move(content)) {}

	[[nodiscard]] decltype(auto) begin() const { return m_cards.begin(); }
	[[nodiscard]] decltype(auto) begin() { return m_cards.begin(); }

	[[nodiscard]] decltype(auto) end() const { return m_cards.end(); }
	[[nodiscard]] decltype(auto) end() { return m_cards.end(); }

	[[nodiscard]] size_t size() const { return m_cards.size(); }
	[[nodiscard]] bool empty() const { return m_cards.empty(); }
	void clear() { m_cards.clear(); }

protected:
	std::vector<card> m_cards;
};


struct card_area : public card_storage {
	card_area(std::initializer_list<card>&& content = {})
		: card_storage(std::move(content)) {}
	virtual ~card_area() = default;
	
	void add(card&& card) {
		assert(can_add(card) && "expedition::add() called with incorrect color");
		m_cards.emplace_back(std::move(card));
	}

	[[nodiscard]] virtual bool can_add(const card& card) const  = 0;
};

struct colored_card_area : public card_area {
	colored_card_area(color_t color, std::initializer_list<card>&& content = {}) 
		: card_area(std::move(content))
		, m_color(color) {}

	[[nodiscard]] const color_t& color() const {
		return m_color;
	}

protected:
	color_t m_color;

};
}  // namespace rover::lost_cities