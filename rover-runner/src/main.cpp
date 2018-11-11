#include <rover/framework>

using namespace std::chrono_literals;

namespace sample {
	struct solver_1 {
		static rover::user_id id() {
			return rover::user_id{ "sample user #1" };
		}

		static bool run(const std::string& /*filename*/) {
			std::this_thread::sleep_for(2s);
			return false;
		}
	};

	struct solver_2 {
		static rover::user_id id() {
			return rover::user_id{ "sample user #2" };
		}

		static bool run(const std::string& /*filename*/) {
			std::this_thread::sleep_for(1s);
			return false;
		}
	};
}

int main(/*int argc, char** argv*/) {
	rover::framework framework;

	framework.run_solver<sample::solver_1>();
	framework.run_solver<sample::solver_2>();
	
	
	return 0;
}