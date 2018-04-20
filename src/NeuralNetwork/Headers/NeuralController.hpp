#ifndef NEURALCONTROLLER_HPP
#define NEURALCONTROLLER_HPP

class NeuralController{
	private:
		static NeuralController* instance;
		NeuralController();

	public:
		static NeuralController* getInstance();

};



#endif