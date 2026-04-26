#!/bin/sh

make clean
make || exit 1
./c-calc