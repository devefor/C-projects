#!/bin/bash

directory="/opt/hw2/task3_prog/"

a_o2_wihtoutg=()
b_o2_wihtg=()
c_o0_wihtg=()

for binar in "$directory"*; do
    dump_d=$(objdump -d "$binar")
    dump_h=$(objdump -h "$binar")
    output=$("$binar" | head -n 1 | cut -c1)

    number=$(basename "$binar")
    number=${number%.out}
    number=$((10#$number))

    if echo "$dump_d" | grep -A 3 "Disassembly of section .text:" | grep -q "_start" && echo "$dump_h" | grep -q ".debug_info"; then
        if [ "$output" == "c" ]; then
            c_o0_wihtg+=("$number")
        fi
    elif echo "$dump_h" | grep -q ".debug_info"; then
        if [ "$output" == "b" ]; then
            b_o2_wihtg+=("$number")
        fi
    else 
        if [ "$output" == "a" ]; then
            a_o2_wihtoutg+=("$number")
        fi
    fi
done

IFS=' '
printf "%s" "${a_o2_wihtoutg[*]}"
echo
printf "%s" "${b_o2_wihtg[*]}"
echo
printf "%s" "${c_o0_wihtg[*]}"
echo