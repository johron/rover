#include "gtest/gtest.h"
#include "rover/framework.h"

using namespace rover::lost_cities;

TEST(card_storage, construct) {
	const card_storage storage({card(color::blue, 0), card(color::blue, 2)});
}

TEST(card_storage, size) {
	const card_storage storage({card(color::blue, 0), card(color::blue, 2)});
	EXPECT_EQ(storage.size(), 2);
}

TEST(card_storage, empty) {
	const card_storage storage({card(color::blue, 0), card(color::blue, 2)});
	EXPECT_FALSE(storage.empty());
}

TEST(card_storage, clear) {
	card_storage storage({card(color::blue, 0), card(color::blue, 2)});
	EXPECT_EQ(storage.size(), 2);
	storage.clear();
	EXPECT_EQ(storage.size(), 0);
}

TEST(card_storage, non_const_iterator) {
	card_storage storage({card(color::blue, 0), card(color::blue, 2), card(color::blue, 2)});
	size_t count = 0;
	int value = 0;
	for (auto& card : storage) {
		count += 1;
		value += card.value();
	}
	EXPECT_EQ(count, 3);
	EXPECT_EQ(value, 4);
}

TEST(card_storage, const_iterator) {
	const card_storage storage({card(color::blue, 0), card(color::blue, 2), card(color::blue, 2)});
	size_t count = 0;
	int value = 0;
	for (const auto& card : storage) {
		count += 1;
		value += card.value();
	}
	EXPECT_EQ(count, 3);
	EXPECT_EQ(value, 4);
}