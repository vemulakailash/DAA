set title 'Binary Search vs Ternary Search'
set xlabel 'Input Size (n)'
set ylabel 'Number of Comparisons'
set grid
plot 'data.txt' using 1:2 with linespoints title 'Binary Search','data.txt' using 1:3 with linespoints title 'Ternary Search'
pause -1
