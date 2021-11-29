#!/bin/bash

find . -name "*.[ch]" >cscope.files
find . -name "*.cpp" >>cscope.files
find ../LatheCPP/lathe_src -name "*.cpp" >>cscope.files
find ../LatheCPP/lathe_src -name "*.h" >>cscope.files
