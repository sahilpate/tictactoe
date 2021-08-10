CC = g++
CFLAGS = -c -Wall -Wextra -Werror -pedantic -std=c++17
OBJS = TTTGame.o TTTPlayer.o TTTComputerPlayer.o TTTPHumanPlayer.o
EXE = tictactoe

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LFLAGS)

TTTGame.o: TTTGame.cpp TTTGame.hpp
	$(CC) TTTGame.cpp TTTGame.hpp $(CFLAGS)

TTTPlayer.o: TTTPlayer.cpp TTTPlayer.hpp
	$(CC) TTTPlayer.cpp TTTPlayer.hpp $(CFLAGS)

TTTComputerPlayer.o: TTTComputerPlayer.cpp TTTComputerPlayer.hpp
	$(CC) TTTComputerPlayer.cpp TTTComputerPlayer.hpp $(CFLAGS)

TTTPlayer.o: TTTHumanPlayer.cpp TTTHumanPlayer.hpp
	$(CC) TTTHumanPlayer.cpp TTTHumanPlayer.hpp $(CFLAGS)

clean:
	rm $(EXE) $(OBJS) *.gch