CC = g++ -std=c++11
exe_file = hunt
$(exe_file): game.o event.o player.o room.o gold.o wumpus.o pit.o bats.o driver.o
	$(CC)  game.o event.o player.o room.o gold.o wumpus.o pit.o bats.o driver.o -o $(exe_file)
game.o: game.cpp
	$(CC) -c game.cpp
event.o: event.cpp
	$(CC) -c event.cpp
player.o: player.cpp
	$(CC) -c player.cpp	
room.o: room.cpp
	$(CC) -c room.cpp	
gold.o: gold.cpp
	$(CC) -c gold.cpp	
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp	
pit.o: pit.cpp
	$(CC) -c pit.cpp	
bats.o: bats.cpp
	$(CC) -c bats.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)