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
and even characters like \x1A! \n" > test_files/ascii1.input
printf "Hello, World!" > test_files/ascii2.input

printf "Hello,\x00World!\n" > test_files/data.input
printf "Hello,\x06World!\n" > test_files/data1.input
printf "Hello, \0x15World!\n" > test_files/data2.input

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
