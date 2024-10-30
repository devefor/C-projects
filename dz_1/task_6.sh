#!/bin/bash

sed -i 's/printf("%d\\n", 345)/print123()/g' main.cpp
sed -i '1i\#include <stdio.h>' header1.h