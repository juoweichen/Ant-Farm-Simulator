#!/usr/bin/bash
sh update_generator.sh

echo "\033[32mtest_flow_one\033[0m"
./lem-in < test_flow_one
echo "\033[32mtest_flow_ten\033[0m"
./lem-in < test_flow_ten
echo "\033[32mtest_flow_thousand\033[0m"
./lem-in < test_flow_thousand
echo "\033[32mtest_big\033[0m"
./lem-in < test_big
echo "\033[32mtest_bigsuper\033[0m"
./lem-in < test_bigsuper