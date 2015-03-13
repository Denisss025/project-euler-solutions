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
        auto sumN = [limit](U sum, U n) {
                // Check for overflow
                // (false positive are possible)
                if (std::sqrt(((std::numeric_limits<U>::max() - sum) / n) * 2) < 
                                static_cast<double>(limit) + 1.0) {
                        throw std::overflow_error{"n: " + std::to_string(n)};
                }
                
                const U limDivN = limit / n;
                return sum + n * limDivN * (1 + limDivN) / 2;
        };
        
        return sumN(sumN(U{}, 3) - sumN(U{}, 15), 5);
}

}  // namespace impl

template <typename I> inline static auto solution(I limit) ->
                impl::make_unsigned_t<I> {
        return impl::solution(static_cast<impl::make_unsigned_t<I>>(limit));
}

}  // namespace euler001
