CXX = g++-5 -g
CXXFLAGS = -std=c++14  -MMD
EXEC = cc3k
OBJECTS = vertical_wall.o horizontal_wall.o display.o buff.o treasure.o small_hoard.o normal_hoard.o dragon_hoard.o potion.o restore_health.o poison_health.o boost_atk.o boost_def.o wound_atk.o wound_def.o enemy.o human.o dwarf.o halfling.o orc.o elf.o merchant.o stair.o door.o tile.o passage.o object.o character.o player.o shade.o drow.o vampire.o troll.o goblin.o floor1.o subject.o gamecontroller.o style.o window.o panel.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lncurses

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
