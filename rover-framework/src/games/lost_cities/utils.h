#pragma once

namespace rover::lost_cities::util {
[[nodiscard]] inline uint32_t time_based_seed() {
	return static_cast<uint32_t>(std::chrono::system_clock::now().time_since_epoch().count());
}
}  // namespace rover::lost_cities::util