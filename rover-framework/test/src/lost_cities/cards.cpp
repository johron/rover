#include "gtest/gtest.h"
#include "../src/games/lost_cities/cards.h"

using namespace rover::lost_cities;

TEST(card, equality) {
	constexpr card green_2(color::green, 2);
	constexpr card green_3(color::green, 3);
	static_assert(green_2 == green_2);
	static_assert(green_2 != green_3);
}

TEST(card, value_compare) {
	constexpr card green_2(color::green, 2);
	constexpr card green_3(color::green, 3);
	static_assert(green_2 < green_3);
	static_assert(green_2 <= green_3);
	static_assert(green_2 <= green_2);
	static_assert(green_3 > green_2);
	static_assert(green_3 >= green_2);
	static_assert(green_3 >= green_3);
}

TEST(card, type_size) {
	static_assert(sizeof(color_t) == 1);
	static_assert(sizeof(value_t) == 1);
	static_assert(sizeof(card) == 2);
}
