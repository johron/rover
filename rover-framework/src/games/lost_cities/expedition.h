#pragma once

namespace rover::lost_cities {
struct expedition : public colored_card_area {
	explicit expedition(color_t color)
		: colored_card_area(color) {}

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

	[[nodiscard]] virtual bool can_add(const card& card) const override {
		return card.color() == m_color && (m_cards.empty() ? true : card >= m_cards.back());
	}
};

struct expedition_area : public stack_group<expedition> {
	[[nodiscard]] int score(color_t color) const { 
		return m_cards[color].score();
	}

	[[nodiscard]] int total_score() const {
		return m_cards[color::blue].score() + m_cards[color::green].score() + m_cards[color::red].score() +
			   m_cards[color::yellow].score() + m_cards[color::white].score();

	}
};
}  // namespace rover::lost_cities