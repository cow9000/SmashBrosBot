#include "Headers/NeuralController.hpp"

NeuralController* NeuralController::instance = 0;

NeuralController::getInstance(){
	if(instance == 0){
		instance = new NeuralController();
	}
	return instance();
}