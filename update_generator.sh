#!/usr/bin/bash
echo "\033[32mupdate_all_test\033[0m"
./generator --flow-one > test_flow_one
./generator --flow-ten > test_flow_ten
./generator --flow-thousand > test_flow_thousand
./generator --big > test_big
./generator --big-superposition > test_bigsuper