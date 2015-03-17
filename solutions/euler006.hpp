/*
* File: solutions/euler004.hpp
*
* Copyright (c) 2015, Denis Novikov
*
* Created on: Mar 17, 2015
* Author: Denis Novikov
* Licence: GNU v.3.0
* Description: see https://projecteuler.net/problem=6 for details.
*
* Problem (#006):
* The sum of the squares of the first ten natural numbers is,
*
* 1² + 2² + ... + 10² = 385
* The square of the sum of the first ten natural numbers is,
*
* (1 + 2 + ... + 10)² = 552 = 3025
*
* Hence the difference between the sum of the squares of the
* first ten natural numbers and the square of the sum
* is 3025 − 385 = 2640.
*
* Find the difference between the sum of the squares of the first one hundred
* natural numbers and the square of the sum.
*
*/
#pragma once

namespace euler006 {

namespace impl {

inline constexpr static auto calcResult(uint64_t result, uint64_t lim, uint64_t mul) noexcept -> uint64_t {
    return result * mul + ((lim & 1) == 1 ? 0u : 
            (lim * lim * mul / 8));
}

inline constexpr static auto solution(uint64_t n, 
        uint64_t i = 1u, uint64_t result = 0u) noexcept -> uint64_t {
    return i >= n ? calcResult(result, n + i, 2u + 3u * (n + i)) :
        solution(n - 1, i + 1, result + i * n);
}

}  // namespace impl

inline static auto solution(unsigned limit) -> uint64_t {
    return (limit == 0u) ? 0u : impl::solution(limit - 1u);
}

inline static auto solution() -> uint64_t {
    return solution(100u);
}

}  // namespace euler006
