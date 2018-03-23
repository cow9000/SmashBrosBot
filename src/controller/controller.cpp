#include "headers/controller.hpp"

//Singleton
Controller * Controller::getInstance(){
	if(instance == 0){
		instance = new Controller();
	}
	return instance;
}

Controller::Controller(){}

//Sending controlls
//https://wiki.dolphin-emu.org/index.php?title=Pipe_Input
