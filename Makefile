CXX = g++-5 -g
CXXFLAGS = -std=c++14  -MMD
EXEC = cc3k
OBJECTS = enemy.o human.o stair.o door.o tile.o passage.o object.o character.o player.o shade.o floor1.o gamecontroller.o subject.o window.o panel.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
