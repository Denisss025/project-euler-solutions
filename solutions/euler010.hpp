/*
* File: solutions/euler007.hpp
*
*  Copyright (c) 2015, Denis Novikov
*
*  Created on: Mar 26, 2015
*      Author: Denis Novikov
*     Licence: GNU v.3.0
* Description: see https://projecteuler.net/problem=10 for details.
*
* Problem (#010):
* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
*
* Find the sum of all the primes below two million.
*
*/
#pragma once

#include <array>
#include <vector>
#include <limits>
#include "euler090.hpp"

namespace euler010 {

namespace impl {
    
using bits_t = std::vector<bool>;

static inline auto unset_nonprime(bits_t &bits,
		unsigned j, unsigned n) -> void {
	if  (j >= bits.size()) return;
	bits[j] = false;
	return unset_nonprime(bits, j + n, n);
}

static inline auto is_nextprime(bits_t &b0, bits_t &b1,
		unsigned i, unsigned n) -> bool {
	return (!b0[i]) ? false : (
		unset_nonprime(b0, i + n,     n),
		unset_nonprime(b1, n - i - 2, n),
		true);
}

}  // namespace impl

static inline auto solution(unsigned limit) -> uint64_t {
	uint64_t sum = 2 + 3;

	using namespace impl;

	auto bits = [](unsigned size) {
		bits_t b(size, true);
		std::array<bits_t, 2> result;
		result[0] = b;
		result[1] = std::move(b);
		return result;
	}(6 + limit/6);

	const auto bits_size = bits[0].size();
	for (auto i = 0u, n = 0u; i < bits_size; ++i, --n) {
		if ((n += 5) >= limit) return sum;
		if (is_nextprime(bits[0], bits[1], i, n)) {
			if (std::numeric_limits<uint64_t>::max() - n < sum)
				throw std::overflow_error{"n: " + std::to_string(n)};
			sum += n;
		}

		if ((n += 2) >= limit) return sum;
		if (is_nextprime(bits[1], bits[0], i, n)) {
			if (std::numeric_limits<uint64_t>::max() - n < sum)
				throw std::overflow_error{"n: " + std::to_string(n)};
			sum += n;
		}
	}

	return sum;
}

static inline auto solution() -> uint64_t {
	return solution(2000000u);
}

}  // namespace euler010
