/*
 * File: solutions/euler003.hpp
 *
 *  Copyright (c) 2015, Denis Novikov
 *
 *  Created on: Mar 13, 2015
 *      Author: Denis Novikov
 *     Licence: GNU v.3.0
 * Description: see https://projecteuler.net/problem=3 for details.
 *
 * Problem (#003):
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 * 
 */

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
