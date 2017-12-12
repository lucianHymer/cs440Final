#!/bin/bash

#bnfc -m -cpp_stl zp.cf
#make
#make -f Makefile.codegen
./compiler2017 $1 a.apm
./pstack/api a
