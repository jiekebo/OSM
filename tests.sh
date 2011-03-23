#!/bin/sh
set -e
make -C tests clean
make -C tests

tests="hw exec halt calc counter shell zombiegone badexec hello salon"

for test in $tests; do
    util/tfstool delete fyams.harddisk $test || true
    util/tfstool write fyams.harddisk tests/$test $test
done
