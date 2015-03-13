#pragma once

namespace euler002 { 

namespace impl {

static constexpr inline auto add_fib(uint64_t sum, uint64_t curr, uint64_t prev) -> uint64_t {
	return curr < 4000000ul ? 
		add_fib(sum + ((curr & 0x01) == 0 ? curr : 0ul), prev + curr, curr) : sum;
}

}  // namespace impl

static constexpr inline auto solution() -> uint64_t {
	return impl::add_fib({}, 1ul, {});
}

}  // namespace euler002
