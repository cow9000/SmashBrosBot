/**
* Created by Derek Vawdrey, 2018
* Copyright 2018
**/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <vector>

#include "ControllerCommands.hpp"

class Controller{
	private:
		static Controller* instance;
		Controller();

		std::vector<ControllerCommands> activeControllerCommands;

		void writeToPipe(ControllerCommands command, bool released);

		double mainStickX;
		double mainStickY;

		double cStickX;
		double cStickY;


	public:
		static Controller* getInstance();

		//List of controller commands, this will either add them to the list or remove them from the list.
		void sendControllerCommand(std::vector<ControllerCommands> commands);
		void setMainStickX(double mainStickX);
		void setMainStickY(double mainStickY);

		void setCStickX(double cStickX);
		void setCStickY(double cStickY);

		double returnMainStickX(){return mainStickX;}
		double returnMainStickY(){return mainStickY;}
		double returnCStickX(){return cStickX;}
		double returnCStickY(){return cStickY;}
};


#endif //CONTROLLER_HPP
