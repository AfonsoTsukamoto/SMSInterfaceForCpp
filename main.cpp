/*
 *  main.cpp
 *  SMSExample
 */

#include <iostream>
#include "MotionInitializer.h"
#define SENS 0.01
void out(void){
	std::cout << "Closing sensor" << std::endl;
	closeMotionSensor();
}

int main(int argc, char *argv[]){
	vector3D *_lePos;
	
	//init the sensor and regist its at exit function for a smooth end
	initMotionSensor();
	atexit(out);
	
	std::cout << "Start moving your mac!" << std::endl;
	
	//Infinite loop of updates
	while(1){
		_lePos = updateAndGet3Motion();
		if(hasMoved(SENS))
			std::cout << (*_lePos)._x << (*_lePos)._y << (*_lePos)._z << std::endl;
	}
	return 0;
	
}
