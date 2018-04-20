# Super Smash Bros: Melee, Artifical Intelligence
## Todo list:
- [ ] Write code to send commands to Dolphin
- [ ] Write code to retrieve game information from Dolphin
- [ ] Write Neural Network to play game
## What will this NN do?
This NN is being made to test the limits of the game Super Smash Bros: Melee. 
It will be used to find further powerful tools for competitive play, when it finds something out of the ordinary, it will record that.
## How will the program determine fitness?
The program will determine fitness by using a fitness number
	> Step 1: First we gather the number of stocks the opponent has, each stock is worth -999
	> Step 2: We then add the percentage the player has (if player has 200% then we would add 200 to -999)
	> Step 3: Sum these up, and that is the fitness of the neural network 