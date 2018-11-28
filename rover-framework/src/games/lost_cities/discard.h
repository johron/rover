#pragma once

namespace rover::lost_cities {
struct discard {
	explicit discard(const color_t& color)
		: m_color(color) {}

	[[nodiscard]] const card& top() const {
		assert(!empty() && "dicard::top() called on empty discard");
		return m_cards.back();
	}

	void add_card(card&& card) {
		m_cards.emplace_back(std::move(card));
	}

	[[nodiscard]] constexpr bool can_add(const card& card) const {
		return card.color() == m_color;
	}

	[[nodiscard]] bool empty() const {
		return m_cards.empty();
	}

	[[nodiscard]] size_t size() const {
		return m_cards.size();
	}

private:
	std::vector<card> m_cards;
	color_t m_color;
};
}  // namespace rover::lost_cities