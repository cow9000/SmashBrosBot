#include "headers/Controller.hpp"

//Singleton
Controller* Controller::instance = 0;



//Singleton pattern
/**
* Returns the singleton instance
*/
Controller * Controller::getInstance(){
	if(instance == 0){
		instance = new Controller();
	}
	return instance;
}

Controller::Controller(){}






//Sending controlls
//https://wiki.dolphin-emu.org/index.php?title=Pipe_Input

void Controller::writeToPipe(ControllerCommands command, bool released){
	if(released){
		//Write release command

		//echo 'RELEASE A' > ~/my-dolphin-directory/pipe1
		std::cout << "RELASE " << command << std::endl;
	}else{
		//Write press command

		//echo 'PRESS A' > ~/my-dolphin-directory/pipe1
		std::cout << "PRESS " << command << std::endl;
	}
}

void Controller::writeToPipe(StickCommands stickType){
	if(stickType == StickCommands::MAIN){
		//MAIN STICK
		//echo 'SET MAIN X Y' > ~/my-dolphin-directory/pipe1
		std::cout << "SET MAIN " << getMainStickX() << " " << getMainStickY() << std::endl;
	}else{
		//echo 'SET C X Y' > ~/my-dolphin-directory/pipe1
		std::cout << "SET C " << getCStickX() << " " << getCStickY() << std::endl;
	}
}

//0 to 1 methods for STICK
//MAIN STICK
void Controller::setMainStick(double mainStickX, double mainStickY){
	this->mainStickX = mainStickX;
	this->mainStickY = mainStickY;
	writeToPipe(StickCommands::MAIN);
}

void Controller::setMainStickX(double mainStickX){
	this->mainStickX = mainStickX;
	writeToPipe(StickCommands::MAIN);
}
void Controller::setMainStickY(double mainStickY){
	this->mainStickY = mainStickY;
	writeToPipe(StickCommands::MAIN);

}

//C STICK
void Controller::setCStick(double cStickX, double cStickY){
	this->cStickX = cStickX;
	this->cStickY = cStickY;
	writeToPipe(StickCommands::C);
}

void Controller::setCStickX(double cStickX){
	this->cStickX = cStickX;
	writeToPipe(StickCommands::C);
}

void Controller::setCStickY(double cStickY){
	this->cStickY = cStickY;
	writeToPipe(StickCommands::C);
}

//Press or release methods
void Controller::sendControllerCommand(std::vector<ControllerCommands> commands){



	//Loop through the commands vector
	for(int addingIndex = 0; addingIndex < commands.size(); addingIndex++){

		//Index to remove command, -1 indicated no command to be removed
		int removeIndex = -1;

		for(int activeIndex = 0; activeIndex < activeControllerCommands.size(); activeIndex++){

			//If the command is found, store index of active command
			if(commands.at(addingIndex) == activeControllerCommands.at(activeIndex)){
				removeIndex = activeIndex;
				break;
			}
		}



		//If the button is already pressed down, release it.
		if(removeIndex > -1){
			ControllerCommands command = activeControllerCommands.at(addingIndex);
			writeToPipe(command, true);
			activeControllerCommands.erase(activeControllerCommands.begin() + removeIndex);
		}else{
			//This means that the button has not been pressed down yet
			ControllerCommands command = commands.at(addingIndex);
			activeControllerCommands.push_back(command);
			writeToPipe(command, false);
		}


	}
}
