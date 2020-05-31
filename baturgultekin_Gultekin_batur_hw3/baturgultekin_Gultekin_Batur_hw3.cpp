#include <string>
#include "robots.h"
#include "minifw.h"

using namespace std;

bool moveRobot1(Robot& robot1, Robot& robot2, int road) 
	// moveRobot1 = the cycle which enabled to move robot and check barriers
{
	int x = 1;
	int moveOfMirror = 0;
	// x = 1 and moveOfMirror = 0  to use in while fuction for checking the movement of robots is it facing wall or not

	robot1.TurnRight();
	robot2.TurnRight();
	robot2.TurnRight();
	robot2.TurnRight();
	while(x <= road)
	{
		// check the robots if they encountered with a wall or not
		if(!robot1.FacingWall())
		{
			robot1.Move(1);
			moveOfMirror++;
		}

		x++;
	}
	robot2.Move(moveOfMirror);
	if(robot1.Blocked() && road != moveOfMirror)
		// if they encountered with a wall app shows a message and return false
	{
		ShowMessage("Robots encountered a wall. End of the spiral.");
		return false;
	}
	else
		// if they did not encounter with a wall it continue
		return true;
}


bool inputcheck1 (int xpos ){
	// inputcheck1= a function to check cordinate inputs is has a true value or false

	if (xpos >= 0 && xpos <= 11 ){
		return true;}

	else
	{
		ShowMessage ("Invalid X cordinate.");
		return false;
	}
}

bool inputcheck2 (int ypos ){
	// inputcheck2= a function to check cordinate inputs is has a true value or false

	if (ypos >= 0 && ypos <= 11 ){
		return true;}

	else
	{
		ShowMessage ("Invalid Y cordinate.");
		return false;
	}
}

int main() 
{
	int xpos, ypos;

	ShowMessage("This program moves the original robot in a clockwise spiral and mirror robot in a counter-clockwise spiral for two rounds.");

	GetInput("Please Enter X position of the robot", xpos);
	//with GetInput member funciton, starting cordinates taken from user
	if(inputcheck1(xpos))
	{
		GetInput("Please Enter Y position of the robot", ypos);
		if(inputcheck2(ypos))
		{
			Robot robot1(xpos, ypos, east, 0);
			Robot robot2(23-xpos, ypos, west, 0);

			robot1.SetColor(blue);		
			robot2.SetColor(red);	
			// this member function changes the collor of robots
			if(!moveRobot1(robot1, robot2,1))
				return 0;
			if(!moveRobot1(robot1, robot2,1))
				return 0;
			if(!moveRobot1(robot1, robot2,2))
				return 0;
			if(!moveRobot1(robot1, robot2,2))
				return 0;
			//moveRobot1 function is checked if robots are facing with a wall, these functions will end the spiral
			robot1.SetColor(green);
			robot2.SetColor(purple);
			// this member function changes the collor of robots
			if(!moveRobot1(robot1, robot2,3))
				return 0;
			if(!moveRobot1(robot1, robot2,3))
				return 0;
			if(!moveRobot1(robot1, robot2,4))
				return 0;
			if(!moveRobot1(robot1, robot2,4))
				return 0;
			//moveRobot1 function is checked if robots are facing with a wall, these functions will end the spiral
		}
	}
	return 0;
}