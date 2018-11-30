#pragma once
#include "cards.h"
#include "containers.h"

namespace rover::lost_cities {
struct hand : public card_area {
	void remove_card(const card& card) {
		assert(contains(card) && "hand::remove() called with card that can't be found");
		m_cards.erase(std::remove(m_cards.begin(), m_cards.end(), card), m_cards.end());
	}

	[[nodiscard]] bool contains(const card& card) const {
		return std::find(m_cards.begin(), m_cards.end(), card) != m_cards.end();
	}

	virtual bool can_add(const card& /*card*/) const override {
		return true;
	}
};
}  // namespace rover::lost_cities