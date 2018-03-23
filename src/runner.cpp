#include "Controller/Headers/Controller.hpp"
#include "Controller/Headers/ControllerCommands.hpp"

#include <vector>

int main(){

	Controller* controller = Controller::getInstance();

	std::vector<ControllerCommands> commands;
	std::vector<ControllerCommands> commands2;

	commands.push_back(ControllerCommands::A);
	commands.push_back(ControllerCommands::B);
	commands.push_back(ControllerCommands::Z);

	commands2.push_back(ControllerCommands::Z);
	commands2.push_back(ControllerCommands::B);
	commands2.push_back(ControllerCommands::A);


	controller->sendControllerCommand(commands);

	controller->setMainStick(0.5,0.6);
	controller->sendControllerCommand(commands2);

	return 0;

}
