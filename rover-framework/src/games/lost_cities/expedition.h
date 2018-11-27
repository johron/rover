#pragma once

namespace rover::lost_cities {
struct expedition {
	explicit expedition(color_t color)
		: m_color(color) {}

	void add_card(card&& card){
		assert(can_add(card) && "expedition::add() called with incorrect color");
		m_cards.emplace_back(card);
	}

	[[nodiscard]] bool can_add(const card& card) const {
		return card.color() == m_color && (m_cards.empty() ? true : card >= m_cards.back());
	}

	[[nodiscard]] size_t size() const {
		return m_cards.size();
	}

	[[nodiscard]] bool empty() const {
		return m_cards.empty();
	}

	[[nodiscard]] int score() const {
		if (m_cards.empty()) {
			return 0;
		} else {
			const auto bonus = m_cards.size() >= 8 ? 20 : 0;
			auto total_sum = -20;
			auto multiplier = 1;

			for (const auto& card : m_cards) {
				if (const auto value = card.value()) {
					total_sum += value;
				} else {
					multiplier++;
				}
			}

			return (total_sum * multiplier) + bonus;
		}
	}

	[[nodiscard]] const color_t& color() const {
		return m_color;
	}

private:
	std::vector<card> m_cards;
	color_t m_color;
};

}  // namespace rover::lost_cities