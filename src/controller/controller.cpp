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
	}else{
		//Write press command

		//echo 'PRESS A' > ~/my-dolphin-directory/pipe1
	}
}




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
