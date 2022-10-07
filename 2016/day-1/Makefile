Part1Sources = 
Part2Sources = 

both: *.cpp
	g++ part1.cpp $(Part1Sources) -o part1
	g++ part2.cpp $(Part2Sources) -o part2

part1: part1.cpp $(Part1Sources)
	g++ part1.cpp $(Part1Sources) -o part1

part2: part2.cpp $(Part2Sources)
	g++ part2.cpp $(Part2Sources) -o part2



nrunboth: *.cpp
	g++ part1.cpp $(Part1Sources) -o part1
	g++ part2.cpp $(Part2Sources) -o part2
	./part1
	./part2

nrunpart1: part1.cpp $(Part1Sources)
	g++ part1.cpp $(Part1Sources) -o part1 && ./part1

nrunpart2: part2.cpp $(Part2Sources)
	g++ part2.cpp $(Part2Sources) -o part2 && ./part2



bothnrun: *.cpp
	g++ part1.cpp $(Part1Sources) -o part1
	g++ part2.cpp $(Part2Sources) -o part2
	./part1
	./part2

part1nrun: part1.cpp $(Part1Sources)
	g++ part1.cpp $(Part1Sources) -o part1 && ./part1

part2nrun: part2.cpp $(Part2Sources)
	g++ part2.cpp $(Part2Sources) -o part2 && ./part2



nrun: *.cpp
	g++ part1.cpp $(Part1Sources) -o part1
	g++ part2.cpp $(Part2Sources) -o part2
	./part1
	./part2