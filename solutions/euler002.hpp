#pragma once

namespace euler002 { 

namespace impl {

static constexpr inline auto sum_ef(uint64_t sum, uint64_t curr, uint64_t prev) -> uint64_t {
	return curr >= 4000000ul ? sum :
		sum_ef(sum + ((curr & 0x01) == 0 ? curr : 0ul), prev + curr, curr);
}

}  // namespace impl

static constexpr inline auto solution() -> uint64_t {
	return impl::sum_ef({}, {1}, {});
}

}  // namespace euler002
