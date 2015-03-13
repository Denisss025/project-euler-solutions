/*
 * File: solutions/euler001.hpp
 *
 *  Copyright (c) 2015, Denis Novikov
 *
 *  Created on: Mar 13, 2015
 *      Author: Denis Novikov
 *     Licence: GNU v.3.0
 * Description: see https://projecteuler.net/problem=1 for details.
 *
 * Problem (#001):
 * If we list all the natural numbers below 10 that are multiples
 * of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 */

#pragma once

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

namespace euler001 {

namespace impl {
    
template <typename I>
using make_unsigned_t = typename std::make_unsigned<I>::type;

template <typename U> inline static auto solution(U limit) -> U {
	limit -= 1;

	// limDiv03 * (1 + limDiv03) < pow((1 + limDiv03), 2) < maxU
	constexpr U maxU = std::numeric_limits<U>::max();
	const U limDiv03 = limit / 3;
	if (std::sqrt(maxU) < 1 + limDiv03) 
		throw std::overflow_error{"sum03"};

	// Since (5 * limDiv15) <= limDiv03 and limDiv15 <= limDiv03,
	// there is no need to check for overflow
	const U limDiv15 = limit / 15;
	const U sum03 = (limDiv03 * (1 + limDiv03) -
			5 *  limDiv15 * (1 + limDiv15)) / 2;

	// sum03 * 3 < maxU
	if (maxU / 3 < sum03) throw std::overflow_error{"sum03 * 3"};
	const U sum3 = 3 * sum03;

	// sum3 + 5 * limDiv05 * (1 + limDiv05) / 2 < < sum3 + 5 * pow((1 + limDiv05), 2) < maxU
	const U limDiv05 = limit / 5;
	if (std::sqrt(((maxU - sum3) / 5) * 2) < 1 + limDiv05)
		throw std::overflow_error{"sum3 + sum5"};
	return sum3 + 5 * limDiv05 * (1 + limDiv05) / 2;
}

}  // namespace impl


template <typename I> inline static auto solution(I limit) ->
                impl::make_unsigned_t<I> {
        return impl::solution(static_cast<impl::make_unsigned_t<I>>(limit));
}

inline static auto solution() -> unsigned {
	return impl::solution(1000u);
}

}  // namespace euler001
