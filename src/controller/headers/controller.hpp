/**
* Created by Derek Vawdrey, 2018
* Copyright 2018
**/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

Controller* Controller::instance = 0;

class Controller{
	private:
		static Controller* instance;
		controller();
	public:
		static Controller* getInstance();
};


#endif //CONTROLLER_HPP