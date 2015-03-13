/*
 * File: solutions/euler004.hpp
 *
 *  Copyright (c) 2015, Denis Novikov
 *
 *  Created on: Mar 13, 2015
 *      Author: Denis Novikov
 *     Licence: GNU v.3.0
 * Description: see https://projecteuler.net/problem=4 for details.
 *
 * Problem (#004):
 * A palindromic number reads the same both ways. The largest
 * palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * 
 */

#pragma once

#include <stdexcept>

namespace euler004 {

static inline auto solution() -> uint32_t {
	uint32_t u_{9u}, m_{9u}, l_{9u}, curr_{999999u};
    auto next = [&]() {
        if (u_ == 0u) throw std::range_error{"cannot generate less than 100001u"};

        auto current = curr_;
        
        if (l_ != 0u) {
            --l_;
            curr_ -= 1100u;
            return current;
        }

        l_ = 9u;
        curr_ += 9900u;

        if (m_ != 0u) {
            --m_;
            curr_ -= 10010u;
            return current;
        }

        m_ = 9u;
        curr_ += 90090u;

        --u_;
        curr_ -= 100001u;
        return current;
    };

    for (auto x = next(); x != 100001u; x = next()) {
        for (auto n = 999u; n > 99u && n >= x / n; --n) {
            if (x % n == 0) {
                return x;
            }
        }
    }

    return 0u;
}

}  // namespace euler004
