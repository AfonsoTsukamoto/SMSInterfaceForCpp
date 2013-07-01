SMSInterfaceForCpp
======================================================

SuddenMotionSensorInterfaceForCpp. 


This is a simple interface for the possibility of using mac's sudden motion sensor with C++. Procedural, not O.O. 
I also made some small changes to sms lib in order to compile it for OSX 10.6. It hasn't been running since 10.5.
This first version has no calibration methods yet and a lousy name. 
Soon I'll commit a new version with a cooler name a some calibration easy to use methods/functions. 
(Might be methods cause I'm still thinking about making a class out of this, just need to figure out how to link Obj-cpp classes to C++ classes)
Language: Objective-Cpp

======================================================

I'll include a makefile soon, but in the meantime, for use with XCODE, follow these steps:

  1) Create an empty project and create a new target. Name it whatever you want.
  
  2) In the new target, add the next existing frameworks: foundation and iokit. 
  
  3) In the pre-compiled headers option of the target, remove all the refered path (it references Appkit which will not be used)
  
  4) build and run 
  
  5) shake your mac!
  
  
======================================================

There's a simple main program showing how to use the interface. It is pretty self-explanatory, but still:

  1) Call initMotionSensor() to start sms. 
  
  2) There are 4 update functions, 3 getters and an 'hybrid' (which returns a vector3D struct pointer) to use the way you prefer. 
  Just remember that before doing a get you must update or use the 'hybrid' method. 
  
  3) There's an extra function [hasMoved(float interval)] I made for the example that tells if there has been movement considering the given interval (think about it as epsilon).
  This is useful in the example in order to make the terminal less epileptic. 
  
  4) Regist a callback atexit with closeMotionSensor() or make sure your code passes by it before the program exits. 

======================================================
  
NOTE: In your C++ code, include ONLY the MotionInitializer.h header file. That's one of the tricks to get it running. 
This happens to be the almighty power (not that powerful) of this interface. Since the obj-cpp only includes obj-cpp on the implementation file,
this allows you to include the .h in your C++ file without compiler/linker problems. Since internally your C++ code will generate somthing like extern <name of the func> it works 
like if it was a C++ function call, which is not. YOU HAVE BEEN WARNED! 

======================================================

Check my page for more: web.ist.utl.pt/afonsotsukamoto
