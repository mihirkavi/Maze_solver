# maze_solver
This is an arduino IDE based code which allows the bot to autonomously take decisions and solve the maze traced by a black line:
right hand wall maze solving algorithm
In this algorithm priorities are set when the bot encounters a right joint() The priorities are as follows: If 'T' joint witha right turn is present then it goes straight If 'T' joint witha left turn is present then it takes a left turn finally if it is a dead end it takes a 'U' turn

So, the priorities are as follows: Left turn > staright > right The highest priority is of the left turn whereas the lowest priority is of the right turn This algorithm enables the bot to simply solve the maze.

Once this algorithm is implemented in the dry run it stores the correct turns in the memory and access these turn instructions in the next run.
