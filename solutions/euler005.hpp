/*
* File: solutions/euler004.hpp
*
* Copyright (c) 2015, Denis Novikov
*
* Created on: Mar 16, 2015
* Author: Denis Novikov
* Licence: GNU v.3.0
* Description: see https://projecteuler.net/problem=5 for details.
*
* Problem (#005):
* 2520 is the smallest number that can be divided by each of the
* numbers from 1 to 10 without any remainder.
*
* What is the smallest positive number that is evenly divisible
* by all of the numbers from 1 to 20?
*
*/
#pragma once

#include <cmath>
#include <algorithm>
#include <limits>
#include <stdexcept>

#include "euler004.hpp"

namespace euler005 {

inline static auto solution(unsigned limit) -> uint64_t {
	if (limit < 3u) return limit;

	std::vector<bool> v((limit - 1) * 2, true);

	const auto n = v.size();
	const auto log2Lim = std::log2l(limit);

	auto result = static_cast<uint64_t>(std::exp2(std::floor(log2Lim)));

	// Go through even numbers
	for (auto i = 0u, num = 3u; i < n; ++i, num += 2)
		if (v[i]) {
			auto mul = static_cast<uint64_t>(
				std::pow(num, std::floor(log2Lim / std::log2l(num))));
			if (std::numeric_limits<uint64_t>::max() / mul < result)
				throw std::overflow_error{"num: " + std::to_string(num)};
			result *= mul;
			for (auto j = i + num; j < n; j += num) v[j] = false;
		}
	
	return result;
}

inline static auto solution() -> uint64_t {
	return solution(20u);
}

}  // namespace euler005
