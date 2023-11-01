#!/bin/bash
FILE=$1
NAME=$2
g++ -g -I ./Helpers/Easybench -o "$NAME" "$FILE" ./Helpers/Easybench/Easybench.cpp
