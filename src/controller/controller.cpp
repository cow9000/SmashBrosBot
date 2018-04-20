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

	if(mainStickX > 1) mainStickX = 1.0;
	if(mainStickX < 0) mainStickX = 0.0;

	if(mainStickY > 1) mainStickY = 1.0;
	if(mainStickY < 0) mainStickY = 0.0;

	this->mainStickX = mainStickX;
	this->mainStickY = mainStickY;
	writeToPipe(StickCommands::MAIN);
}

void Controller::setMainStickX(double mainStickX){


	if(mainStickX > 1) mainStickX = 1.0;
	if(mainStickX < 0) mainStickX = 0.0;

	this->mainStickX = mainStickX;
	writeToPipe(StickCommands::MAIN);
}
void Controller::setMainStickY(double mainStickY){

	if(mainStickY > 1) mainStickY = 1.0;
	if(mainStickY < 0) mainStickY = 0.0;

	this->mainStickY = mainStickY;
	writeToPipe(StickCommands::MAIN);

}

//C STICK
void Controller::setCStick(double cStickX, double cStickY){

	if(cStickX > 1) cStickX = 1.0;
	if(cStickX < 0) cStickX = 0.0;

	if(cStickY > 1) cStickY = 1.0;
	if(cStickY < 0) cStickY = 0.0;

	this->cStickX = cStickX;
	this->cStickY = cStickY;
	writeToPipe(StickCommands::C);
}

void Controller::setCStickX(double cStickX){
	if(cStickX > 1) cStickX = 1.0;
	if(cStickX < 0) cStickX = 0.0;

	this->cStickX = cStickX;
	writeToPipe(StickCommands::C);
}

void Controller::setCStickY(double cStickY){
	if(cStickY > 1) cStickY = 1.0;
	if(cStickY < 0) cStickY = 0.0;

	this->cStickY = cStickY;
	writeToPipe(StickCommands::C);
}

//Press or release methods
void Controller::sendControllerCommand(std::vector<ControllerCommands> commands){


	int removeIndex = -1;

	//Loop through the commands vector
	for(int addingIndex = 0; addingIndex < commands.size(); addingIndex++){

		for(int activeIndex = 0; activeIndex < activeControllerCommands.size(); activeIndex++){

			//If the command is found, store index of active command
			if(commands.at(addingIndex) == activeControllerCommands.at(activeIndex)){
				removeIndex = activeIndex;
			}
		}

		//If the button is already pressed down, release it.
	
		if(removeIndex >= 0){
			ControllerCommands command = activeControllerCommands.at(removeIndex);
			writeToPipe(command, true);


			if(removeIndex == 0){
				activeControllerCommands.erase(activeControllerCommands.begin() + 0);
			}else{
				activeControllerCommands.erase(activeControllerCommands.begin() + removeIndex);
			}
		}else{
			//This means that the button has not been pressed down yet

			ControllerCommands command = commands.at(addingIndex);
			activeControllerCommands.push_back(command);
			writeToPipe(command, false);
		}

		removeIndex = -1;




	}
}
