CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD
EXEC = chess
OBJECTS = main.o game.o textObserver.o bishop.o board.o bot.o king.o knight.o level1Bot.o level2Bot.o level3Bot.o level4Bot.o level5Bot.o move.o observer.o pawn.o piece.o player.o queen.o rook.o subject.o tile.o sdl_wrap.o human.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lSDL2 -lSDL2_image -lSDL2_ttf

-include ${DEPENDS}


.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
