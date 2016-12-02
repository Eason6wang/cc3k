#include "gamecontroller.h"

int main(int argc, char* argv[]) {
    //iosfailure
    GameController g{};
	try {
		std::cout << "choose e/c to use wasd/command (this massage will be deleted later)" << std::endl;
		if (argc == 2) {
			g.startGame(argv[1]);
		} else {
			g.startGame();
		}
	}
	catch (...){
		return 0;
	}
}
