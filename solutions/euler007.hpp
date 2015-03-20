/*
* File: solutions/euler007.hpp
*
* Copyright (c) 2015, Denis Novikov
*
* Created on: Mar 20, 2015
* Author: Denis Novikov
* Licence: GNU v.3.0
* Description: see https://projecteuler.net/problem=7 for details.
*
* Problem (#007):
* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
* we can see that the 6th prime is 13.
*
* What is the 10 001st prime number?
*
*/
#pragma once#include <array>
#include <vector>
#include "euler006.hpp"

namespace euler007 {

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

static inline auto solution(uint16_t num) -> unsigned{
	if (num < 3) return num + 1;

	num -= 2;
	auto bits = [](unsigned size) {
		impl::bits_t b(size, true);
		std::array<impl::bits_t, 2> result;
		result[0] = b;
		result[1] = std::move(b);
		return result;
	}(num * 2);

	const auto bits_size = bits[0].size();
	for (auto i = 0u, n = 0u; i < bits_size; ++i, --n) {
		if (impl::is_nextprime(bits[0], bits[1], i, n += 5) && !--num) return n;
		if (impl::is_nextprime(bits[1], bits[0], i, n += 2) && !--num) return n;
	}

	return 0u;
}

static inline auto solution() -> unsigned {
	return solution(10001u);
}

}  // namespace euler007
