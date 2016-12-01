#include "gamecontroller.h"

int main(int argc, char* argv[]) {
    //iosfailure
    GameController g{};
	if (argc == 2) {
		g.startGame(argv[1]);
	} else {
		g.startGame();
	}
}
