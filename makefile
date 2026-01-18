hepsi: derle calistir

derle:
	g++ -I./include -Wall -std=c++11 -c ./src/AnaDugum.cpp -o ./lib/AnaDugum.o
	g++ -I./include -Wall -std=c++11 -c ./src/AnaListe.cpp -o ./lib/AnaListe.o
	g++ -I./include -Wall -std=c++11 -c ./src/dikdortgen.cpp -o ./lib/dikdortgen.o
	g++ -I./include -Wall -std=c++11 -c ./src/ekran.cpp -o ./lib/ekran.o
	g++ -I./include -Wall -std=c++11 -c ./src/main.cpp -o ./lib/main.o
	g++ -I./include -Wall -std=c++11 -c ./src/sekil.cpp -o ./lib/sekil.o
	g++ -I./include -Wall -std=c++11 -c ./src/SekilDugumu.cpp -o ./lib/SekilDugumu.o
	g++ -I./include -Wall -std=c++11 -c ./src/SekilListesi.cpp -o ./lib/SekilListesi.o
	g++ -I./include -Wall -std=c++11 -c ./src/ucgen.cpp -o ./lib/ucgen.o
	g++ -I./include -Wall -std=c++11 -c ./src/yildiz.cpp -o ./lib/yildiz.o
	g++ -Wall -std=c++11 ./lib/*.o -o ./bin/program.exe

calistir:
	./bin/program.exe