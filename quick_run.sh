#!/usr/bin/bash
echo "\033[32msubject-1.map\033[0m"
./lem-in < farms/subject-1.map
echo "\033[32msubject-2.map\033[0m"
./lem-in < farms/subject-2.map
echo "\033[32msubject-3.map\033[0m"
./lem-in < farms/subject-3.map
echo "\033[32msubject-4.map\033[0m"
./lem-in < farms/subject-4.map
echo "\033[32msubject-5.map\033[0m"
./lem-in < farms/subject-5.map

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