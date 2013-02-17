#!/bin/bash
filename=$1
/usr/bin/gnuplot <<EOF 
set terminal x11 persist
set style data lines
set title "Comparing Sorting Efficiency"
set xlabel 'array size'
set ylabel 'seconds to sort'
set grid
plot "$filename" using 1:2  title 'bubblesort' with lines, \
	"$filename" using 1:3 title 'mergesort' with lines, \
	"$filename" using 1:4 title 'heapsort' with lines, \
	"$filename" using 1:5 title 'quicksort' with line
EOF
