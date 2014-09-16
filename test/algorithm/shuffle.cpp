//  Copyright Eric Niebler 2014
//
//  Use, modification and distribution is subject to the
//  Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
// For more information, see http://www.boost.org/libs/range/
//
//  Copyright 2005 - 2007 Adobe Systems Incorporated
//  Distributed under the MIT License(see accompanying file LICENSE_1_0_0.txt
//  or a copy at http://stlab.adobe.com/licenses.html)

//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include <random>
#include <range/v3/core.hpp>
#include <range/v3/algorithm/equal.hpp>
#include <range/v3/algorithm/shuffle.hpp>
#include "../simple_test.hpp"
#include "../test_utils.hpp"
#include "../test_iterators.hpp"

int main()
{
    {
        int ia[100];
        int ib[100];
        int orig[100];
        ranges::iota(ia, 0);
        ranges::iota(ib, 0);
        ranges::iota(orig, 0);
        const unsigned sa = sizeof(ia)/sizeof(ia[0]);
        std::minstd_rand g;
        ranges::shuffle(random_access_iterator<int*>(ia), sentinel<int*>(ia+sa), g);
        CHECK(!ranges::equal(ia, orig));
        ranges::shuffle(ib, ib+sa, g);
        CHECK(!ranges::equal(ia, ib));
    }

    {
        int ia[100];
        int ib[100];
        int orig[100];
        ranges::iota(ia, 0);
        ranges::iota(ib, 0);
        ranges::iota(orig, 0);
        const unsigned sa = sizeof(ia)/sizeof(ia[0]);
        std::minstd_rand g;
        auto rng = ranges::make_range(random_access_iterator<int*>(ia), sentinel<int*>(ia+sa));
        ranges::shuffle(rng, g);
        CHECK(!ranges::equal(ia, orig));
        ranges::shuffle(ib, g);
        CHECK(!ranges::equal(ia, ib));
    }

    return ::test_result();
}
