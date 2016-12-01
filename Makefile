CXX = g++-5 
CXXFLAGS = -std=c++14  -MMD
EXEC = cc3k
OBJECTS = buff.o item.o treasure.o small_hoard.o normal_hoard.o dragon_hoard.o enemy.o human.o dwarf.o halfling.o orc.o elf.o merchant.o stair.o door.o tile.o passage.o object.o character.o player.o shade.o drow.o vampire.o troll.o goblin.o floor1.o subject.o gamecontroller.o style.o window.o panel.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
