# Documentation for UR Team 3 Robot Program

## Functions For Robot Movement:

### 1) Perform forward movement
moveForward(int speed);
moveForward(unsigned long time,int speed);

### 2) Perform left turn movement
turnLeft(int speed);
turnLeft(unsigned long time, int speed);

### 3) Perform right turn movement
turnRight(int speed);
turnRight(unsigned long time, int speed);

### 4)Perform backward movement
moveBackward(int speed);
moveBackward(unsigned long time, int speed);

## Functions For Maze:
### 1) Starts the maze algorithm
maze(bool leftMode);
### 2) Notify the robot that the maze is completed and the maze algorithm can be stopped
setMazeCompleted();