/*
* File: solutions/euler007.hpp
*
* Copyright (c) 2015, Denis Novikov
*
* Created on: Mar 23, 2015
* Author: Denis Novikov
* Licence: GNU v.3.0
* Description: see https://projecteuler.net/problem=8 for details.
*
* Problem (#008):
* The four adjacent digits in the 1000-digit number that have
* the greatest product are 9 × 9 × 8 × 9 = 5832.
*
* 73167176531330624919225119674426574742355349194934
* 96983520312774506326239578318016984801869478851843
* 85861560789112949495459501737958331952853208805511
* 12540698747158523863050715693290963295227443043557
* 66896648950445244523161731856403098711121722383113
* 62229893423380308135336276614282806444486645238749
* 30358907296290491560440772390713810515859307960866
* 70172427121883998797908792274921901699720888093776
* 65727333001053367881220235421809751254540594752243
* 52584907711670556013604839586446706324415722155397
* 53697817977846174064955149290862569321978468622482
* 83972241375657056057490261407972968652414535100474
* 82166370484403199890008895243450658541227588666881
* 16427171479924442928230863465674813919123162824586
* 17866458359124566529476545682848912883142607690042
* 24219022671055626321111109370544217506941658960408
* 07198403850962455444362981230987879927244284909188
* 84580156166097919133875499200524063689912560717606
* 05886116467109405077541002256983155200055935729725
* 71636269561882670428252483600823257530420752963450
*
* Find the thirteen adjacent digits in the 1000-digit number
* that have the greatest product. What is the value of this product?
*
*/
#pragma once

#include <algorithm>
#include "euler007.hpp"

namespace euler008 {

namespace impl {

template <typename It>
constexpr static inline auto val(It c) -> uint64_t {
	return static_cast<uint64_t>(*c - '0');
}

template <typename String>
static inline auto data(String &s) -> const char* {
	return s.data();
}

template <typename CharT, size_t n>
constexpr static inline auto data(CharT (&s)[n]) -> CharT* {
	return s;
}

template <typename String>
static inline auto size(String &s) -> decltype(s.size()) {
	return s.size();
}

template <typename CharT, size_t n>
constexpr static inline auto size(CharT (&)[n]) -> size_t {
	return n;
}

template <typename FwdIt>
static inline auto solution(FwdIt first, FwdIt last, FwdIt queue_first,
		uint8_t queue_size, uint8_t adj_num,
		uint64_t prod, uint64_t max_prod) -> uint64_t {
	if (first == last) return max_prod;

	++queue_size;
	if (queue_size == 1u) prod = 1u;

	auto c = val(first);
	if (c == 0u) {
		queue_first = std::next(first);
		queue_size = 0u;
	} else {
		decltype(c) q_front = 1u;
		if (queue_size > adj_num) {
			q_front = val(queue_first);
			++queue_first;
		}
		prod /= q_front;
		prod *= c;

		q_front = q_front - 1u + queue_size - adj_num;
		max_prod = (c > q_front) ? std::max(max_prod, prod) : max_prod;
	}

	return solution(++first, last, queue_first, 
			queue_size, adj_num, prod,
			max_prod);
}

}  // namespace impl

template <typename String>
static inline auto solution(const String &numbers, uint8_t adj_num) -> uint64_t {
	return impl::solution(impl::data(numbers), 
			std::next(impl::data(numbers), impl::size(numbers)),
			impl::data(numbers), {}, adj_num, {}, {});
}

}  // namespace euler008
