#!/usr/bin/env python3
# Copyright (c) 2021 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""Test mempool fee histogram."""

from decimal import Decimal

from test_framework.test_framework import BitcoinTestFramework
from test_framework.util import (
    assert_equal,
    assert_greater_than,
    assert_greater_than_or_equal,
    assert_no_key,
)

class MempoolFeeHistogramTest(BitcoinTestFramework):
    def set_test_params(self):
        self.num_nodes = 1

    def skip_test_if_missing_module(self):
        self.skip_if_no_wallet()

    def run_test(self):
        node = self.nodes[0]

        node.sendtoaddress(node.getnewaddress(), 1)

        info = node.getmempoolinfo()
        assert_no_key('fee_histogram', info)

        info = node.getmempoolinfo(["0.00000100","0.00000200","0.00000300","0.00000400","0.00000500"])
        total_fees = 0

        for key, bin in info['fee_histogram']['ranges'].items():
            assert_equal(key, bin['from_feerate'])
            if bin['fees'] > 0:
                assert_greater_than(bin['count'], 0)
            else:
                assert_equal(bin['count'], 0)
            assert_greater_than_or_equal(bin['fees'], 0)
            assert_greater_than_or_equal(bin['sizes'], 0)
            if bin['to_feerate'] != 'Max':
                assert_greater_than(Decimal(bin['to_feerate']), Decimal(bin['from_feerate']))
            total_fees += bin['fees']

        assert_equal(total_fees, info['fee_histogram']['total_fees'])


if __name__ == '__main__':
    MempoolFeeHistogramTest().main()
