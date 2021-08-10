CC = g++
CFLAGS = -c -Wall -Wextra -Werror -pedantic -std=c++17
OBJS = TTTGame.o TTTPlayer.o TTTCompPlayer.o TTTHumanPlayer.o main.o
EXE = tictactoe

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LFLAGS)

TTTGame.o: TTTGame.cpp TTTGame.hpp
	$(CC) TTTGame.cpp TTTGame.hpp $(CFLAGS)

TTTPlayer.o: TTTPlayer.cpp TTTPlayer.hpp
	$(CC) TTTPlayer.cpp TTTPlayer.hpp $(CFLAGS)

TTTCompPlayer.o: TTTCompPlayer.cpp TTTCompPlayer.hpp
	$(CC) TTTCompPlayer.cpp TTTCompPlayer.hpp $(CFLAGS)

TTTHumanPlayer.o: TTTHumanPlayer.cpp TTTHumanPlayer.hpp
	$(CC) TTTHumanPlayer.cpp TTTHumanPlayer.hpp $(CFLAGS)

main.o: main.cpp
	$(CC) main.cpp $(CFLAGS)

clean:
	rm $(EXE) $(OBJS) *.gch