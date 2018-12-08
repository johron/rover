#pragma once

namespace rover::lost_cities {

using value_t = uint8_t;
using color_t = uint8_t;
enum color { blue, green, red, yellow, white, __size__ };

struct card {
	constexpr card(color_t _color, value_t _value)
		: m_color(_color)
		, m_value(_value) {
		assert(m_value <= 10 && m_value != 1 && "m_value outside accepted range"); // allowed values are 0(contract) and 2-10
	}

	[[nodiscard]] constexpr color_t color() const {
		return m_color;
	}

	[[nodiscard]] constexpr value_t value() const {
		return m_value;
	}

	[[nodiscard]] constexpr bool operator==(const card& other) const {
		return m_color == other.m_color && m_value == other.m_value;
	}

	[[nodiscard]] constexpr bool operator!=(const card& other) const {
		return !(*this == other);
	}

	[[nodiscard]] constexpr bool operator>(const card& other) const {
		return m_value > other.m_value;
	}

	[[nodiscard]] constexpr bool operator<(const card& other) const {
		return m_value < other.m_value;
	}

	[[nodiscard]] constexpr bool operator>=(const card& other) const {
		return *this > other || *this == other;
	}

	[[nodiscard]] constexpr bool operator<=(const card& other) const {
		return *this < other || *this == other;
	}


private:
	color_t m_color;
	value_t m_value;
};
}  // namespace rover::lost_cities