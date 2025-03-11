//access the built-in servo library
#include "khaibao.h"
#include <Servo.h>

Servo Serv1a;  // Create a servo object named Serv1a
Servo Serv1b;  // Create a servo object named Serv1b
Servo Serv2a;  // Create a servo object named Serv2a
Servo Serv2b;  // Create a servo object named Serv2b
Servo Serv3a;  // Create a servo object named Serv3a
Servo Serv3b;  // Create a servo object named Serv3b
Servo Serv4a;  // Create a servo object named Serv4a
Servo Serv4b;  // Create a servo object named Serv4b

void ini() {
  // Vertical
  Serv1a.write(dung1a);
  Serv2a.write(dung2a);
  Serv3a.write(dung3a);
  Serv4a.write(dung4a);
  // Backward
  Serv1b.write(xa1b);
  Serv2b.write(xa2b);
  Serv3b.write(xa3b);
  Serv4b.write(xa4b);
  delay(200);

  // Attach the servo motors to their pins
  Serv1b.attach(pinServ1b);
  Serv2b.attach(pinServ2b);
  Serv3b.attach(pinServ3b);
  Serv4b.attach(pinServ4b);
  delay(200);

  Serv1a.attach(pinServ1a);
  delay(200);
  Serv2a.attach(pinServ2a);
  delay(200);
  Serv3a.attach(pinServ3a);
  delay(200);
  Serv4a.attach(pinServ4a);
  delay(200);
}



/////////////////////////////////// Write your own functions ///////////////////////////////////
void Start() {  // Grab the Rubik cube when type START
  Serv1b.write(gan1b);
  Serv2b.write(gan2b);
  Serv3b.write(gan3b);
  Serv4b.write(gan4b);
}

void End() {  // Release the Rubik cube when type END
  Serv1b.write(xa1b);
  Serv2b.write(xa2b);
  Serv3b.write(xa3b);
  Serv4b.write(xa4b);
}
/////////////////////////////////// Write your own functions ///////////////////////////////////



void setup() {
  Serial.begin(9600);
  ini();
  Serial.println("Done!");
  Serial.println("Input the rubik cube");
  Serial.println("Type START to grab");
}


void loop() {
  if (solved == false) {
    // wait for moves
    if (Serial.available() > 0) {
      data = Serial.readStringUntil('\n');
      Serial.print("data: ");
      Serial.println(data);

      // Get "END": release the Rubik cube
      if (data == "END") {
        solved = true;
        End();
        Serial.print("START?");
      } else {
        L = data.length();
        index = 1;
        String S[int(L / 2) + 1];

        /*String analyze*/
        trash = 0;
        /*Data tracking*/
        count = 0;
        while (index > 0) {
          index = data.indexOf(' ');
          //                          Serial.println(index);
          if (index > 0) {
            S[trash] = data.substring(0, index);
          } else {
            S[trash] = data.substring(0, L);
          }
          //                          Serial.println(S[trash]);
          trash = trash + 1;
          count = index + 1;
          data = data.substring(count, L);
        }
        /* OUTPUT: s (sequence of solve steps)*/
        trash = 0;
        while (trash < int(L / 2) + 1) {

          /////////////////////////////////// Write your own code ///////////////////////////////////dung= vertical, ngnang = horizontal, gan =avancer, xa=reculer
          //FRONT
          if (S[trash] == "F'") {  // Rotate Front Clockwise
            Serial.println("Got F'");
            Serv1a.write(ngang1a);
            delay(172);
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(50);
          } else if (S[trash] == "F") {  // Rotate Front counter-Clockwise
            Serial.println("Got F");
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(ngang1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(250);
            Serv1a.write(dung1a);
            delay(200);
          } else if (S[trash] == "F2") {
            Serial.println("Got F2");
            Serv1a.write(ngang1a);
            delay(152);
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(250);
            Serv1a.write(ngang1a);
            delay(152);
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(1500);
            ;
          } else if (S[trash] == "F2'") {
            Serial.println("Got F2'");
            Serv1a.write(ngang1a);
            delay(152);
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(200);
            Serv1a.write(ngang1a);
            delay(152);
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(50);
          }
          ///
          //RIGHT
          ///dung= vertical, ngnang = horizontal, gan =avancer, xa=reculer
          else if (S[trash] == "R") {  // Rotate Front Clockwise
            Serial.println("Got R");
            Serv4a.write(ngang4a);
            delay(152);
            Serv4b.write(xa4b);
            delay(200);
            Serv4a.write(dung4a);
            delay(200);
            Serv4b.write(gan4b);
            delay(50);
          } else if (S[trash] == "R'") {  // Rotate Front counter-Clockwise
            Serial.println("Got R'");
            Serv4b.write(xa4b);
            delay(200);
            Serv4a.write(ngang4a);
            delay(200);
            Serv4b.write(gan4b);
            delay(200);
            Serv4a.write(dung4a);
            delay(200);
          } else if (S[trash] == "R2") {
            Serial.println("Got R2");
            Serv4a.write(ngang4a);
            delay(152);
            Serv4b.write(xa4b);
            delay(200);
            Serv4a.write(dung4a);
            delay(200);
            Serv4b.write(gan4b);
            delay(200);
            Serv4a.write(ngang4a);
            delay(152);
            Serv4b.write(xa4b);
            delay(200);
            Serv4a.write(dung4a);
            delay(200);
            Serv4b.write(gan4b);
            delay(50);
          } else if (S[trash] == "R2'") {
            Serial.println("Got R2'");
            Serv4a.write(ngang4a);
            delay(152);
            Serv4b.write(xa4b);
            delay(200);
            Serv4a.write(dung4a);
            delay(200);
            Serv4b.write(gan4b);
            delay(200);
            Serv4a.write(ngang4a);
            delay(152);
            Serv4b.write(xa4b);
            delay(200);
            Serv4a.write(dung4a);
            delay(200);
            Serv4b.write(gan4b);
            delay(50);
          }
          ///
          //BACK
          ///dung= vertical, ngnang = horizontal, gan =avancer, xa=reculer
          else if (S[trash] == "B") {  // Rotate Front Clockwise
            Serial.println("Got B");
            Serv2a.write(ngang2a);
            delay(152);
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(50);
          } else if (S[trash] == "B'") {  // Rotate Front counter-Clockwise
            Serial.println("Got B'");
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(ngang2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
          } else if (S[trash] == "B2") {
            Serial.println("Got B2");
            Serv2a.write(ngang2a);
            delay(152);
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(200);
            Serv2a.write(ngang2a);
            delay(152);
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(50);
          } else if (S[trash] == "B2'") {  //Idea :  we can put the same code as B2 if the delay(152) is working
            Serial.println("Got B2'");
            Serv2a.write(ngang2a);
            delay(152);
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(200);
            Serv2a.write(ngang2a);
            delay(152);
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(50);
          }
          ///
          //LEFT
          ///dung= vertical, ngnang = horizontal, gan =avancer, xa=reculer
          else if (S[trash] == "L'") {  // Rotate Front Clockwise
            Serial.println("Got L'");
            Serv3a.write(ngang3a);
            delay(152);
            Serv3b.write(xa3b);
            delay(200);
            Serv3a.write(dung3a);
            delay(200);
            Serv3b.write(gan3b);
            delay(50);
          } else if (S[trash] == "L") {  // Rotate Front counter-Clockwise
            Serial.println("Got L");
            Serv3b.write(xa3b);
            delay(200);
            Serv3a.write(ngang3a);
            delay(200);
            Serv3b.write(gan3b);
            delay(200);
            Serv3a.write(dung3a);
            delay(200);
          } else if (S[trash] == "L2") {  // same code as L2' if it's faster
            Serial.println("Got L2'");
            Serv3a.write(ngang3a);
            delay(152);
            Serv3b.write(xa3b);
            delay(200);
            Serv3a.write(dung3a);
            delay(200);
            Serv3b.write(gan1b);
            delay(200);
            Serv3a.write(ngang3a);
            delay(152);
            Serv3b.write(xa3b);
            delay(200);
            Serv3a.write(dung3a);
            delay(200);
            Serv3b.write(gan3b);
            delay(50);
          } else if (S[trash] == "L2'") {
            Serial.println("Got L2'");
            Serv3a.write(ngang3a);
            delay(152);
            Serv3b.write(xa3b);
            delay(200);
            Serv3a.write(dung3a);
            delay(200);
            Serv3b.write(gan1b);
            delay(200);
            Serv3a.write(ngang3a);
            delay(152);
            Serv3b.write(xa3b);
            delay(200);
            Serv3a.write(dung3a);
            delay(200);
            Serv3b.write(gan3b);
            delay(50);
          }
          ///
          //UP
          ///dung= vertical, ngnang = horizontal, gan =avancer, xa=reculer
          else if (S[trash] == "U") {
            Serial.println("Got U");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(201);
            //3,4 rotate -> up side will face 2
            Serv4a.write(ngang4a);
            Serv3a.write(ngang3a);
            delay(200);
            //1,2 move forward to hold
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(31);  //it can faster
            //3,4 move backward to change to vertical then move forward
            Serv4b.write(xa4b);
            Serv3b.write(xa3b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(197);
            //2 will rotate the up side
            Serv2a.write(ngang2a);
            delay(152);
            //2 move backward & rotate to vertical
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            //2 move forward to hold
            Serv2b.write(gan2b);
            delay(199);  //prise 3-1 ou 2-1 ?
            //3,4 move backward & rotate to horizontal & move forward
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(100);
            //1,2 move backward
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(200);
            //3,4 rotate the rubik
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            //1,2 move forward to hold
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(50);
          } else if (S[trash] == "U'") {
            Serial.println("Got U'");
            //1,2 move backward
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(201);
            //3,4 rotate -> up side will face 2
            Serv4a.write(ngang4a);
            Serv3a.write(ngang3a);
            delay(200);
            //1,2 move forward to hold
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(31);
            //3,4 move backward to change to vertical then move forward
            Serv4b.write(xa4b);
            Serv3b.write(xa3b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(199);  /// prise 3-1
            //2 will rotate the up side
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(ngang2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            //3,4 move backward & rotate to horizontal & move forward
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(200);
            //1,2 move backward
            Serv1b.write(xa1b);
            Serv2b.write(xa1b);
            delay(200);
            //3,4 rotate the rubik
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            //1,2 move forward to hold
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(50);
          } else if (S[trash] == "U2") {
            Serial.println("Got U2");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(201);
            //3,4 rotate -> up side will face 2
            Serv4a.write(ngang4a);
            Serv3a.write(ngang3a);
            delay(200);
            //1,2 move forward to hold
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(31);
            //3,4 move backward to change to vertical then move forward
            Serv4b.write(xa4b);
            Serv3b.write(xa3b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(197);
            //2 will rotate the up side TWICE
            Serv2a.write(ngang2a);
            delay(152);
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(200);
            Serv2a.write(ngang2a);
            delay(152);
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(199);  //prise 3-1 ou 2-1 ?
            //3,4 move backward & rotate to horizontal & move forward
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(100);
            //1,2 move backward
            Serv1b.write(xa1b);
            Serv2b.write(xa1b);
            delay(200);
            //3,4 rotate the rubik
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            //1,2 move forward to hold
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(50);
          } else if (S[trash] == "U2'") {
            Serial.println("Got U2'");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(201);
            //3,4 rotate -> up side will face 2
            Serv4a.write(ngang4a);
            Serv3a.write(ngang3a);
            delay(150);
            //1,2 move forward to hold
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(31);
            //3,4 move backward to change to vertical then move forward
            Serv4b.write(xa4b);
            Serv3b.write(xa3b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(197);
            //2 will rotate the up side TWICE
            Serv2a.write(ngang2a);
            delay(152);
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(200);
            Serv2a.write(ngang2a);
            delay(152);
            Serv2b.write(xa2b);
            delay(200);
            Serv2a.write(dung2a);
            delay(200);
            Serv2b.write(gan2b);
            delay(199);  //prise 3-1 ou 2-1 ?
            //3,4 move backward & rotate to horizontal & move forward
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(100);
            //1,2 move backward
            Serv1b.write(xa1b);
            Serv2b.write(xa1b);
            delay(200);
            //3,4 rotate the rubik
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            //1,2 move forward to hold
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(50);
          }
          ///
          //DOWN
          ///
          else if (S[trash] == "D") {
            Serial.println("Got D");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(201);  //maybe it'll work
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(31);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(199);  /// prise 3-1
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(ngang1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(199);  // prise 3-1 ou 2-1 ?
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(100);
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(50);
          } else if (S[trash] == "D2") {
            Serial.println("Got D2");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(201);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(31);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(197);
            Serv1a.write(ngang1a);
            delay(152);
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(200);
            Serv1a.write(ngang1a);
            delay(152);
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(199);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(100);
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(50);
          } else if (S[trash] == "D'") {
            Serial.println("Got D'");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(201);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(31);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(197);
            Serv1a.write(ngang1a);
            delay(152);
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(199);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);  //maybe we can change
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(100);  // dangereux horizontale
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(50);
          } else if (S[trash] == "D2'") {
            Serial.println("Got D2'");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(201);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(31);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(197);
            Serv1a.write(ngang1a);
            delay(152);
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(200);
            Serv1a.write(ngang1a);
            delay(152);
            Serv1b.write(xa1b);
            delay(200);
            Serv1a.write(dung1a);
            delay(200);
            Serv1b.write(gan1b);
            delay(199);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(200);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(200);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(100);  //dangereux
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(200);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(200);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(50);
          }

          /////////////////////////////////// Write your own code ///////////////////////////////////
          Serial.print(S[trash]);
          Serial.print(" ");
          trash = trash + 1;
        }
        Serial.println(" ");
        Serial.println("Completed!");
        Serial.println("Type END to release");
        data = "";
      }
    }
  } else {
    if (Serial.available() > 0) {
      data = Serial.readStringUntil('\n');
      if (data == "START") {
        Start();
        solved = false;
        Serial.println("Input solving steps");
      }
      data = "";
    }
    data = "";
  }
}
