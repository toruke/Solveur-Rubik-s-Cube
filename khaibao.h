
// PWM pins
int pinServ1a = 2;
int pinServ1b = 3;
int pinServ2a = 4;
int pinServ2b = 5;
int pinServ3a = 6;
int pinServ3b = 7;
int pinServ4a = 8;
int pinServ4b = 9;

/////////////////// Calibrate Servo parameters //////////////
int gan1b = 170;  // close // forward
int gan2b = 170;
int gan3b = 170;
int gan4b = 170;

int xa1b = 55; 
int xa2b = 55;
int xa3b = 50;
int xa4b = 0;

int dung1a = 153;
int dung2a = 25;
int dung3a = 165;
int dung4a = 23;

int ngang1a = 53;
int ngang2a = 122;
int ngang3a = 70;
int ngang4a = 123;

/////////////////// Delay time //////////////
int normal_time = 200; //for every other move
int time1 = 100; //time variable for 2 servos move forward to hold & 2 servos move backward (almost) at the same time
int time2 = 50; //time variable for a servo rotate & move backward/move forward & rotate in (almost) one move

// Variables
String data = "";
int count = 0;
int L = 0;
int index = 0;
int trash = 0;
bool solved = true;
