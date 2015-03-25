/*
* File: solutions/euler009.hpp
*
* Copyright (c) 2015, Denis Novikov
*
*  Created on: Mar 25, 2015
*      Author: Denis Novikov
*     Licence: GNU v.3.0
* Description: see https://projecteuler.net/problem=9 for details.
*
* Problem (#009):
* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
*
* a² + b² = c²
* For example, 3² + 4² = 9 + 16 = 25 = 5².
* 
* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
* Find the product abc.
*
*/
#pragma once

#include "euler008.hpp"

namespace euler009 {

namespace impl {

constexpr static inline auto sqr(uint64_t a) -> uint64_t {
	return a * a;
}

constexpr static inline auto prod(unsigned b, unsigned c, unsigned sum) -> uint64_t {
	return (sum - b - c != b && b < c && sqr(sum - b - c) + sqr(b) == sqr(c)) ?
			((sum - b - c) * b * c) : 0u;
}

constexpr static inline auto fast_sqrt(unsigned x, unsigned next_x, unsigned a) -> unsigned {
	return (next_x >= x) ? x : fast_sqrt(next_x, 
			((sqr(next_x) + a)/next_x) >> 1, a);
}

constexpr static inline auto fast_sqrt(unsigned x, unsigned a) -> unsigned {
	return fast_sqrt(x, ((sqr(x) + a)/x) >> 1, a);
}

constexpr static inline auto sbc(unsigned a, unsigned c = 0u) -> unsigned {
	return a == 0 ? c : sbc(a >> 1, c + 1);
}

constexpr static inline auto fast_sqrt(unsigned a) -> unsigned {
	return fast_sqrt(1 << (sbc(a, 0u) + 1), a);
}

constexpr static inline auto calc_d(unsigned c, unsigned sum) -> 
		unsigned {
	return fast_sqrt(sqr(c) + 2u * sum * c - sqr(sum));
}

constexpr static inline auto calc_prod(unsigned c, unsigned sum) -> uint64_t {
	return (c + calc_d(c, sum) <= sum) ?
			prod(((sum - c - calc_d(c, sum)) / 2), c, sum) : 0u;
}

constexpr static inline auto solution(unsigned sum, unsigned c) -> uint64_t {
	return (c > sum - 4u) ? 0u :
			(calc_prod(c, sum) != 0u) ?
					(calc_prod(c, sum)) :
					solution(sum, c + 1);
}

}  // namespace impl


constexpr static inline auto solution(unsigned sum) -> uint64_t {
	return impl::solution(sum, sum/3u);
}

constexpr static inline auto solution() -> uint64_t {
	return solution(1000u);
}

}  // namespace euler009
