//          Copyright Rein Halbersma 2014-2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_VECTOR_SIZE 50

#include <xstd/bit_set.hpp>                     // basic_bit_set
#include <boost/container/flat_set.hpp>         // flat_set
#include <boost/mpl/vector.hpp>                 // vector
#include <boost/test/test_case_template.hpp>    // BOOST_AUTO_TEST_CASE_TEMPLATE
#include <boost/test/unit_test.hpp>             // BOOST_AUTO_TEST_SUITE, BOOST_CHECK, BOOST_CHECK_EQUAL, BOOST_AUTO_TEST_SUITE_END
#include <cstdint>                              // uint8_t, uint16_t, uint32_t, uint64_t
#include <set>                                  // set
#include <type_traits>                          // is_default_constructible_v

BOOST_AUTO_TEST_SUITE(TypeTraits)

using namespace xstd;

using int_set_types = boost::mpl::vector
<       std::set<int>
,       boost::container::flat_set<int>
,       basic_bit_set<  0, uint8_t>
,       basic_bit_set<  1, uint8_t>
,       basic_bit_set<  8, uint8_t>
,       basic_bit_set<  9, uint8_t>
,       basic_bit_set< 16, uint8_t>
,       basic_bit_set< 17, uint8_t>
,       basic_bit_set< 24, uint8_t>
,       basic_bit_set<  0, uint16_t>
,       basic_bit_set<  1, uint16_t>
,       basic_bit_set< 16, uint16_t>
,       basic_bit_set< 17, uint16_t>
,       basic_bit_set< 32, uint16_t>
,       basic_bit_set< 33, uint16_t>
,       basic_bit_set< 48, uint16_t>
,       basic_bit_set<  0, uint32_t>
,       basic_bit_set<  1, uint32_t>
,       basic_bit_set< 32, uint32_t>
,       basic_bit_set< 33, uint32_t>
,       basic_bit_set< 64, uint32_t>
,       basic_bit_set< 65, uint32_t>
,       basic_bit_set< 96, uint32_t>
#if defined(__GNUG__) || defined(_MSC_VER) && defined(WIN64)
,       basic_bit_set<  0, uint64_t>
,       basic_bit_set<  1, uint64_t>
,       basic_bit_set< 64, uint64_t>
,       basic_bit_set< 65, uint64_t>
,       basic_bit_set<128, uint64_t>
,       basic_bit_set<129, uint64_t>
,       basic_bit_set<192, uint64_t>
#endif
#if defined(__GNUG__)
,       basic_bit_set<  0, __uint128_t>
,       basic_bit_set<  1, __uint128_t>
,       basic_bit_set<128, __uint128_t>
,       basic_bit_set<129, __uint128_t>
,       basic_bit_set<256, __uint128_t>
,       basic_bit_set<257, __uint128_t>
,       basic_bit_set<384, __uint128_t>
#endif
>;

BOOST_AUTO_TEST_CASE_TEMPLATE(IsNothrowDefaultConstructible, T, int_set_types)
{
        static_assert(std::is_default_constructible_v<T>);
}

BOOST_AUTO_TEST_SUITE_END()
