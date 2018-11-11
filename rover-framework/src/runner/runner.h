#pragma once

namespace rover {
	struct user_id {
		std::string name;
	};

	class framework {
	public:
		framework();

		template <typename T>
		auto run_solver() {
			return T::run("test.json");
		}
	};
}