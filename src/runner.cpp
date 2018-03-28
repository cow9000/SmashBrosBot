#include "Controller/Headers/Controller.hpp"
#include "Controller/Headers/ControllerCommands.hpp"

#include <vector>

int main(){

	Controller* controller = Controller::getInstance();

	//EXAMPLE ON HOW TO SEND CONTROLLER COMMANDS
	std::vector<ControllerCommands> commands;
	commands.push_back(ControllerCommands::A);
	commands.push_back(ControllerCommands::B);
	commands.push_back(ControllerCommands::Z);

	controller->sendControllerCommand(commands);

	//SETTING MAIN STICK
	controller->setMainStick(0.5,0.6);

	//SETTING C-STICK
	controller->setCStick(0.1,0.4);


	return 0;

}
