#!/bin/bash

find . -name "*.[ch]" >cscope.files
find . -name "*.cpp" >>cscope.files
find ../LatheCPP/src -name "*.cpp" >>cscope.files
find ../LatheCPP/include -name "*.h" >>cscope.files

