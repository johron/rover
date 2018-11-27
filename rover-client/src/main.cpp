#include <rover/framework>

namespace tga_sample {

using duplicate = rover::problem_definition<bool, std::string>;
using solver_type = rover::abstract_solver<duplicate>;

struct sample_solver : public solver_type {
	virtual bool solve(const std::string& /*input*/) override {
		return true;
	}
};

}  // namespace tga_sample

int main(/*int argc, char** argv*/) {
	rover::registry<tga_sample::duplicate> registry;
	registry.add<tga_sample::sample_solver>(rover::participant{"sample_user_1"});
	registry.add<tga_sample::sample_solver>(rover::participant{"sample_user_2"});

	return 0;
}