#!/bin/bash

nc -q 1 $MASTER_SERVER 12345 <<< "HELLO_i_AM_a_WORKER,$(hostname)"
nc -lp 6789
echo ""
