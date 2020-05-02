// Copyright (c) 2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_UTIL_TYPES_H
#define BITCOIN_UTIL_TYPES_H

#include <type_traits>

template <class T>
struct always_false : std::false_type {
};

#endif // BITCOIN_UTIL_TYPES_H
