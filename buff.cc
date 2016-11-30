#include "buff.h"

void clearScreen(){
	for(int i = 0; i < 100; i++){
		std::cout << std::endl;
	}
}

int getRandom(int min, int max){
	int n = max - min + 1;
	int rn = rand() % n + min;
	return rn;
}

