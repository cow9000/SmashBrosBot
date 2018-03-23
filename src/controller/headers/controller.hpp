/**
* Created by Derek Vawdrey, 2018
* Copyright 2018
**/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "ControllerCommands.hpp"

class Controller{
	private:
		static Controller* instance;
		Controller();

	public:
		static Controller* getInstance();

		void sendControllerCommand(ControllerCommands command);
};


#endif //CONTROLLER_HPP