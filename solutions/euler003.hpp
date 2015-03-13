#pragma once

namespace euler003 {

namespace impl {

static inline constexpr auto reduce(uint64_t val, uint64_t divisor) -> uint64_t {
	return (val <= divisor || val % divisor != 0) ? val :
			reduce(val / divisor, divisor);
}

static inline constexpr auto max_pf2(uint64_t val, uint64_t divisor) -> uint64_t {
	return (divisor >= val) ? val :
			max_pf2(reduce(val, divisor), divisor + 2);
}

static inline constexpr auto max_pf(uint64_t val) -> uint64_t {
	return impl::max_pf2(reduce(val, 2ul), 3ul);
}

}  // namespace impl

static inline auto solution() -> uint64_t {
	return impl::max_pf(600851475143);
}

}  // namespace euler003
