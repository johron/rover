#pragma once

namespace rover {
struct participant {
	std::string m_name;
};

template <class result, class input>
struct problem_definition {
	using result_t = result;
	using input_t = input;
};

template <class problem>
struct abstract_solver {
	virtual ~abstract_solver() = default;

	virtual typename problem::result_t solve(
		const typename problem::input_t& input) = 0;
};

template <class problem>
class registry {
public:
	template <class T>
	void add(participant&& user) {
		static_assert(std::is_base_of_v<abstract_solver<problem>, T>);
		m_solvers[user.m_name] = []() { return std::make_unique<T>(); };
	}

private:
	using create_solver_func =
		std::function<std::unique_ptr<abstract_solver<problem>>()>;
	std::map<std::string, create_solver_func> m_solvers;
};

class framework {
public:
	framework();

	[[nodiscard]] bool exit_requested() const;
};
}  // namespace rover