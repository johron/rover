#pragma once

namespace rover::lost_cities {

using value_t = uint8_t;

struct color_t { 
	enum class value : uint8_t { blue, green, red, yellow, white };
	constexpr explicit color_t(value _color)
		: m_color(_color) { }

	[[nodiscard]] constexpr bool operator==(const color_t& other) const {
		return m_color == other.m_color;
	}

	[[nodiscard]] constexpr bool operator!=(const color_t& other) const {
		return m_color != other.m_color;
	}
private:
	value m_color;
};

namespace color {
constexpr color_t blue = color_t(color_t::value::blue);
constexpr color_t green = color_t(color_t::value::green);
constexpr color_t red = color_t(color_t::value::red);
constexpr color_t yellow = color_t(color_t::value::yellow);
constexpr color_t white = color_t(color_t::value::white);
}  // namespace color


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