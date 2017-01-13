set terminal  png size 512,512 font 'Verdana, 10'
set nokey
set title "Geometric distribution"
set output '//home//cat//Documents//CodingResearch//Tests//Gists//Geometric.png'
set ylabel "PDF"
set yrange [0:0.35]
set xlabel "Random numbers"
set xrange [0:40]
set xtics 1
set grid xtics ytics
plot '//home//cat//Documents//CodingResearch//Tests//Gists//out.txt' using 1:2 lw 2 lt rgb 'blue'
set terminal  png size 512,512 font 'Verdana, 10'
set nokey
set title "Geometric distribution"
set output '//home//cat//Documents//CodingResearch//Tests//Gists//Geometric.png'
set ylabel "PDF"
set yrange [0:0.35]
set xlabel "Random numbers"
set xrange [0:40]
set xtics 1
set grid xtics ytics
plot '//home//cat//Documents//CodingResearch//Tests//Gists//out.txt' using 1:2 lw 2 lt rgb 'blue'
