/**
* Created by Derek Vawdrey, 2018
* Copyright 2018
**/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <vector>
#include <iostream>

#include "ControllerCommands.hpp"

class Controller{
	private:
		static Controller* instance;
		Controller();

		std::vector<ControllerCommands> activeControllerCommands;

		void writeToPipe(ControllerCommands command, bool released);
		void writeToPipe(StickCommands stickType);

		double mainStickX;
		double mainStickY;

		double cStickX;
		double cStickY;


	public:
		static Controller* getInstance();

		//List of controller commands, this will either add them to the list or remove them from the list.
		void sendControllerCommand(std::vector<ControllerCommands> commands);

		void setMainStick(double mainStickX, double mainStickY);
		void setMainStickX(double mainStickX);
		void setMainStickY(double mainStickY);

		void setCStick(double cStickX, double cStickY);
		void setCStickX(double cStickX);
		void setCStickY(double cStickY);

		double getMainStickX(){return mainStickX;}
		double getMainStickY(){return mainStickY;}
		double getCStickX(){return cStickX;}
		double getCStickY(){return cStickY;}
};


#endif //CONTROLLER_HPP
