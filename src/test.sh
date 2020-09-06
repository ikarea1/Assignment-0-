#!/usr/bin/env bash

# Exit immediately if any command below fails.
set -e

make


echo "Generating a test_files directory.."
mkdir -p test_files
rm -f test_files/*


echo "Generating test files.."
printf "Hello, World!\n" > test_files/ascii.input
printf "In this World we can test the different allowed ASCII characters like \x08 , \x09 , \x0A , \x0B , \x0C , \x0D
and even characters like \x1B !\n" > test_files/ascii1.input
printf "We can also test other characters that are allowed: \x20, \x21, \x22, \x23, \x24" > test_files/ascii2.input
printf "We can also try the highest ASCII characters allowed: \x7C, \x7D, \x7E" > test_files/ascii3.input

printf "If we include alot of ASCII characters that are allowed: \x08 , \x09 , \x0A , \x0B , \x0C and then includes
an unallowed character like \x1A" > test_files/data.input
printf "We could write characters like x06: \x06 which should not be allowed in our ASCII set" > test_files/data1.input
printf "We could also try some other unwarranted characters: x0E: \x0E" > test_files/data2.input
printf "There are many characters which should all fail: \x0F, \x10, \x11, \x12, \x13" > test_files/data3.input

printf "" > test_files/empty.input
> test_files/empty1.input

echo "Running the tests.."
exitcode=0
for f in test_files/*.input
do
  echo ">>> Testing ${f}.."
  file    "${f}" | sed 's/ASCII text.*/ASCII text/' > "${f}.expected"
  ./file  "${f}" > "${f}.actual"

  if ! diff -u "${f}.expected" "${f}.actual"
  then
    echo ">>> Failed :-("
    exitcode=1
  else
    echo ">>> Success :-)"
  fi
done
exit $exitcode
