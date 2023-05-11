#!/bin/bash
cd c:/NFBase/GitHub/CompCode/PIP
g++ -g -I ../Helpers/Easybench -o points PIP.cpp ../Helpers/Easybench/Easybench.cpp
gdb points
catch throw #in gdb
run #in gdb
