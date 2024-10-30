#!/bin/bash

temp=$(mktemp -d)

tar -xzf /opt/hw1/datasets.tar.gz -C $temp/
sort -t $'\t' -k2 $temp/queries.txt > $temp/sort_queries.txt
sort -k1 $temp/features.txt > $temp/sort_features.txt
join -t $'\t' -1 2 -2 1 $temp/sort_queries.txt $temp/sort_features.txt > $temp/join.txt

cat $temp/join.txt | cut -f1,2,4,5
rm -Rf $temp
