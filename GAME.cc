#include "GAME.h"
#include "window.h"
#include "normal_gamecontroller.h"
#include "dlc_gamecontroller.h"
using namespace std;

void Game::selectVersion(string file){
	//shared_ptr<Window> startWindow;
	char version;
		std::cout << "choose n/d to use normal/dlc (this massage will be deleted later)" << std::endl;
	cin >> version;
//	ifstream f {file};
	if (version == 'n'){
		n_game.play(file);
	} else {
		d_game.play(file);
	}
}
