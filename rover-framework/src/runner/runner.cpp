#include "runner.h"

namespace rover {

framework::framework() = default;

bool framework::exit_requested() const {
	return false;
}

}  // namespace rover
