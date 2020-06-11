#!/usr/bin/env bash
#
# Copyright (c) 2019-2020 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C.UTF-8

export CONTAINER_NAME=ci_native_nowallet
export DOCKER_NAME_TAG=ubuntu:20.04
export PACKAGES="python3-zmq clang-7 llvm-7"  # Use clang-7 to test C++17 & std::filesystem compatibility, see doc/dependencies.md
export DEP_OPTS="NO_WALLET=1"
export GOAL="install"
export BITCOIN_CONFIG="--enable-glibc-back-compat --enable-reduce-exports CC=clang-7 CXX=clang++-7 --with-boost-process"
