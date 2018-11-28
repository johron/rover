#pragma once
#include "cards.h"

namespace rover::lost_cities {
struct deck {
	deck(std::initializer_list<card>&& cards)
		: m_cards(std::move(cards)){};

	[[nodiscard]] card draw() {
		assert(!empty() && "drawing card from empty deck");
		auto card = m_cards.back();
		m_cards.pop_back();
		return card;
	};

	[[nodiscard]] const card& peek() { 
		assert(!empty() && "peeking on empty deck");
		return m_cards.back(); 
	};

	[[nodiscard]] size_t size() const { 
		return m_cards.size(); 
	};

	[[nodiscard]] bool empty() const {
		return m_cards.empty();
	}

	void shuffle(unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count()) {
		std::shuffle(m_cards.begin(), m_cards.end(), std::default_random_engine(seed));
	}

private:
	std::vector<card> m_cards;
};

// clang-format off
[[nodiscard]] inline deck make_deck() { return deck{
	card(color::blue, 0),
	card(color::blue, 0),
	card(color::blue, 0),
	card(color::blue, 2),
	card(color::blue, 3),
	card(color::blue, 4),
	card(color::blue, 5),
	card(color::blue, 6),
	card(color::blue, 7),
	card(color::blue, 8),
	card(color::blue, 9),
	card(color::blue, 10),

	card(color::green, 0),
	card(color::green, 0),
	card(color::green, 0),
	card(color::green, 2),
	card(color::green, 3),
	card(color::green, 4),
	card(color::green, 5),
	card(color::green, 6),
	card(color::green, 7),
	card(color::green, 8),
	card(color::green, 9),
	card(color::green, 10),

	card(color::red, 0),
	card(color::red, 0),
	card(color::red, 0),
	card(color::red, 2),
	card(color::red, 3),
	card(color::red, 4),
	card(color::red, 5),
	card(color::red, 6),
	card(color::red, 7),
	card(color::red, 8),
	card(color::red, 9),
	card(color::red, 10),

	card(color::yellow, 0),
	card(color::yellow, 0),
	card(color::yellow, 0),
	card(color::yellow, 2),
	card(color::yellow, 3),
	card(color::yellow, 4),
	card(color::yellow, 5),
	card(color::yellow, 6),
	card(color::yellow, 7),
	card(color::yellow, 8),
	card(color::yellow, 9),
	card(color::yellow, 10),

	card(color::white, 0),
	card(color::white, 0),
	card(color::white, 0),
	card(color::white, 2),
	card(color::white, 3),
	card(color::white, 4),
	card(color::white, 5),
	card(color::white, 6),
	card(color::white, 7),
	card(color::white, 8),
	card(color::white, 9),
	card(color::white, 10)}; 
}
// clang-format on
}  // namespace rover::lost_cities