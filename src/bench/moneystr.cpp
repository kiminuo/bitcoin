// Copyright (c) 2016-2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <bench/bench.h>

#include <util/moneystr.h>

#include <array>
#include <vector>

static const std::array<std::string, 25> input_arr = {
        {
            "12345.6789",
            "100000000.00",
            "10000000.00",
            "1000000.00",
            "100000.00",
            "10000.00",
            "1000.00",
            "100.00",
            "10.00",
            "1.00",
            "1",
            "   1",
            "1   ",
            "  1 ",
            "0.1",
            "0.01",
            "0.001",
            "0.0001",
            "0.00001",
            "0.000001",
            "0.0000001",
            "0.00000001",
            " 0.00000001 ",
            "0.00000001 ",
            " 0.00000001"
        }
    };

static void MoneyStrParseMoney(benchmark::Bench& bench)
{
    bench.run([&] {
        for (const std::string& s : input_arr) {
            CAmount ret = 0;
            (void) ParseMoney(s, ret);
        }
    });
}

static void MoneyStrParseMoneyNew(benchmark::Bench& bench)
{
    bench.run([&] {
        for (const std::string& s : input_arr) {
            (void) ParseMoneyNew(s);
        }
    });
}

BENCHMARK(MoneyStrParseMoney);
BENCHMARK(MoneyStrParseMoneyNew);
