#!/bin/bash

./runtest.sh $1 > ${1}_expected.out
./runtest.sh $1 &> ${1}_expected.err
