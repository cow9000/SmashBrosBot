#include "headers/Controller.hpp"

//Singleton
Controller* Controller::instance = 0;



//Singleton pattern
Controller * Controller::getInstance(){
	if(instance == 0){
		instance = new Controller();
	}
	return instance;
}

Controller::Controller(){}

//Sending controlls
//https://wiki.dolphin-emu.org/index.php?title=Pipe_Input
