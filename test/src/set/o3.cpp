//          Copyright Rein Halbersma 2014-2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <set/exhaustive.hpp>           // all_singleton_set_triples
#include <set/primitives.hpp>           // op_equal_to, op_less
#include <xstd/bit_set.hpp>             // bit_set
#include <boost/container/flat_set.hpp> // flat_set
#include <boost/mpl/vector.hpp>         // vector
#include <boost/test/unit_test.hpp>     // BOOST_AUTO_TEST_SUITE, BOOST_AUTO_TEST_SUITE_END, BOOST_AUTO_TEST_CASE_TEMPLATE
#include <cstdint>                      // uint8_t, uint16_t, uint32_t, uint64_t
#include <set>                          // set

BOOST_AUTO_TEST_SUITE(Cubic)

using namespace xstd;

using int_set_types = boost::mpl::vector
<       std::set<int>
,       boost::container::flat_set<int>
,       bit_set< 0, uint8_t>
,       bit_set< 8, uint8_t>
,       bit_set< 9, uint8_t>
,       bit_set<17, uint8_t>
,       bit_set<17, uint16_t>
,       bit_set<17, uint32_t>
#if defined(__GNUG__) || defined(_MSC_VER) && defined(WIN64)
,       bit_set<17, uint64_t>
#endif
#if defined(__GNUG__)
,       bit_set<17, __uint128_t>
#endif
>;

BOOST_AUTO_TEST_CASE_TEMPLATE(Transitivity, T, int_set_types)
{
        all_singleton_set_triples<T>(op_equal_to());
        all_singleton_set_triples<T>(op_less());
}

BOOST_AUTO_TEST_SUITE_END()
