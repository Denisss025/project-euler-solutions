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

namespace euler005 {

namespace impl {
    
struct num_t {
    unsigned value;
    bool     used;
    
    auto operator ++() -> num_t& {
        return ++value, *this;
    }
};

}  // namespace impl

inline static auto solution(unsigned limit) -> unsigned {
    std::vector<impl::num_t> v(limit - 1);
    std::iota(v.begin(), v.end(), impl::num_t{2u, true});
    auto last = v.end();
    auto result = 1u;
    for (auto first = v.begin(); first != last; ++first) {
        if (result % first->value != 0) {
            result *= first->value;
            for (auto it = v.begin(); it != first; ++it) {
                if (it->used && ((result / it->value) % it->value) == 0) {
                    result /= it->value;
                    it->used = false;
                }
            }
        } else {
            first->used = false;
        }
    }

    return result;
}

inline static auto solution() -> unsigned {
    return solution(20u);
}

}  // namespace euler005
