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
  delay(normal_time);

  // Attach the servo motors to their pins
  Serv1b.attach(pinServ1b);
  Serv2b.attach(pinServ2b);
  Serv3b.attach(pinServ3b);
  Serv4b.attach(pinServ4b);

  Serv1a.attach(pinServ1a);
  Serv2a.attach(pinServ2a);
  Serv3a.attach(pinServ3a);
  Serv4a.attach(pinServ4a);
}

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

void setup() {
  Serial.begin(9600);
  ini();
  Serial.println("Done!");
  Serial.println("Input the rubik cube");
  Serial.println("Type START to grab");
}

void loop(){
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
          //FRONT
          if (S[trash] == "F'") {  // Rotate Front counter-Clockwise
            Serial.println("Got F'");
            Serv1a.write(ngang1a);
            //one move
            delay(time2); 
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(dung1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            delay(normal_time);
           } 
          else if (S[trash] == "F") {  // Rotate Front Clockwise
            Serial.println("Got F");
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(ngang1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            //one move: come closer and rotate to vertical at the same time
            delay(time2);
            Serv1a.write(dung1a);
            delay(normal_time);
          } 
          else if (S[trash] == "F2") {
            Serial.println("Got F2");
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(ngang1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            //one move
            delay(time2);
            Serv1a.write(dung1a);
            delay(normal_time);
            
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(ngang1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            //one move
            delay(time2);
            Serv1a.write(dung1a);
            delay(normal_time);
          }
          else if (S[trash] == "F2'"){
            Serial.println("Got F2'");
            Serv1a.write(ngang1a);
            //one move
            delay(time2);
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(dung1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            delay(normal_time);

            Serv1a.write(ngang1a);
            //one move
            delay(time2);
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(dung1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            delay(normal_time);
          }

          //RIGHT
          ///dung= vertical, ngang = horizontal, gan =avancer, xa=reculer
          else if (S[trash] == "R") {  
            Serial.println("Got R");
            Serv4a.write(ngang4a);
            //one move
            delay(time2);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv4b.write(gan4b);
            delay(normal_time);
          } 
          else if (S[trash] == "R'") {  
            Serial.println("Got R'");
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv4b.write(gan4b);
            //one move
            delay(time2);
            Serv4a.write(dung4a);
            delay(normal_time);
          } 
          else if (S[trash] == "R2") {
            Serial.println("Got R2");
            Serv4a.write(ngang4a);
            //one move
            delay(time2);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv4b.write(gan4b);
            delay(normal_time);

            Serv4a.write(ngang4a);
            //one move
            delay(time2);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv4b.write(gan4b);
            delay(normal_time);
          }
          else if (S[trash] == "R2'"){
            Serial.println("Got R2'");
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv4b.write(gan4b);
            //one move
            delay(time2);
            Serv4a.write(dung4a);
            delay(normal_time);

            Serv4b.write(xa4b);
            delay(normal_time);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv4b.write(gan4b);
            //one move
            delay(time2);
            Serv4a.write(dung4a);
            delay(normal_time);
          }
          
          //BACK
          ///dung= vertical, ngnang = horizontal, gan =avancer, xa=reculer
          else if (S[trash] == "B") {  
            Serial.println("Got B");
            Serv2a.write(ngang2a);
            //one move
            delay(time2);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(dung2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            delay(normal_time);
          } 
          else if (S[trash] == "B'") {  
            Serial.println("Got B'");
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(ngang2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            //one move
            delay(time2);
            Serv2a.write(dung2a);
            delay(normal_time);
          } 
          else if (S[trash] == "B2") {
            Serial.println("Got B2");
            Serv2a.write(ngang2a);
            //one move
            delay(time2);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(dung2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            delay(normal_time);

            Serv2a.write(ngang2a);
            //one move
            delay(time2);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(dung2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            delay(normal_time);
          }
          else if (S[trash] == "B2'"){
            Serial.println("Got B2'");
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(ngang2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            //one move
            delay(time2);
            Serv2a.write(dung2a);
            delay(normal_time);

            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(ngang2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            //one move
            delay(time2);
            Serv2a.write(dung2a);
            delay(normal_time);
          }
          
          //LEFT
          ///dung= vertical, ngnang = horizontal, gan =avancer, xa=reculer
          else if (S[trash] == "L'") {  
            Serial.println("Got L'");
            Serv3a.write(ngang3a);
            //one move
            delay(time2);
            Serv3b.write(xa3b);
            delay(normal_time);
            Serv3a.write(dung3a);
            delay(normal_time);
            Serv3b.write(gan3b);
            delay(normal_time);
          } 
          else if (S[trash] == "L") {  
            Serial.println("Got L");
            Serv3b.write(xa3b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            delay(normal_time);
            Serv3b.write(gan3b);
            //one move
            delay(time2);
            Serv3a.write(dung3a);
            delay(normal_time);
          } 
          else if (S[trash] == "L2") {
            Serv3b.write(xa3b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            delay(normal_time);
            Serv3b.write(gan3b);
            //one move
            delay(time2);
            Serv3a.write(dung3a);
            delay(normal_time);
            
            Serv3b.write(xa3b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            delay(normal_time);
            Serv3b.write(gan3b);
            //one move
            delay(time2);
            Serv3a.write(dung3a);
            delay(normal_time);
          }
          else if (S[trash] == "L2'"){
            Serial.println("Got L2'");
            Serv3a.write(ngang3a);
            //one move
            delay(time2);
            Serv3b.write(xa3b);
            delay(normal_time);
            Serv3a.write(dung3a);
            delay(normal_time);
            Serv3b.write(gan1b);
            delay(normal_time);

            Serv3a.write(ngang3a);
            //one move
            delay(time2);
            Serv3b.write(xa3b);
            delay(normal_time);
            Serv3a.write(dung3a);
            delay(normal_time);
            Serv3b.write(gan3b);
            delay(normal_time);
          }
          
          //UP
          ///dung= vertical, ngnang = horizontal, gan =avancer, xa=reculer
          else if (S[trash] == "U") {
            Serial.println("Got U");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv4a.write(ngang4a);
            Serv3a.write(ngang3a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            //4 servos move at the same time
            delay(time1);
            Serv4b.write(xa4b);
            Serv3b.write(xa3b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(normal_time);
            Serv2a.write(ngang2a);
            //one move
            delay(time2);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(dung2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            //3 servos move at the same time
            delay(time1);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            //4 servos move at the same time (not sure if 3,4 can catch rubik on time bc theyre horizontal)
            delay(time1);
            Serv1b.write(xa1b);
            Serv2b.write(xa1b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(normal_time);
          } 
          else if (S[trash] == "U'") {
            Serial.println("Got U'");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv4a.write(ngang4a);
            Serv3a.write(ngang3a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            //4 servos move at the same time
            delay(time1);
            Serv4b.write(xa4b);
            Serv3b.write(xa3b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(normal_time);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(ngang2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            //one move
            delay(time2);
            Serv2a.write(dung2a);
            delay(normal_time);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            //4 servos move at the same time (not sure if 3,4 can catch rubik on time bc theyre horizontal)
            delay(time1);
            Serv1b.write(xa1b);
            Serv2b.write(xa1b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(normal_time);
          } 
          else if (S[trash] == "U2"){
            Serial.println("Got U2");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv4a.write(ngang4a);
            Serv3a.write(ngang3a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            //4 servos move at the same time
            delay(time1);
            Serv4b.write(xa4b);
            Serv3b.write(xa3b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(normal_time);
            Serv2a.write(ngang2a);
            //one move
            delay(time2);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(dung2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            delay(normal_time);
            Serv2a.write(ngang2a);
            //one move
            delay(time2);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(dung2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            //3 servos move at the same time
            delay(time1);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            //4 servos move at the same time (not sure if 3,4 can catch rubik on time bc theyre horizontal)
            delay(time1);
            Serv1b.write(xa1b);
            Serv2b.write(xa1b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(normal_time);
          }
          else if (S[trash] == "U2'") {
            Serial.println("Got U2'");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv4a.write(ngang4a);
            Serv3a.write(ngang3a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            //4 servos move at the same time
            delay(time1);
            Serv4b.write(xa4b);
            Serv3b.write(xa3b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(normal_time);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(ngang2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            //one move
            delay(time2);
            Serv2a.write(dung2a);
            delay(normal_time);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv2a.write(ngang2a);
            delay(normal_time);
            Serv2b.write(gan2b);
            //one move
            delay(time2);
            Serv2a.write(dung2a);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            //4 servos move at the same time (not sure if 3,4 can catch rubik on time bc theyre horizontal)
            delay(time1);
            Serv1b.write(xa1b);
            Serv2b.write(xa1b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(normal_time);
          }
          
          //DOWN
          else if (S[trash] == "D") {
            Serial.println("Got D");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            //4 servos move
            delay(time1);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(normal_time);
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(ngang1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            //one move
            delay(time2);
            Serv1a.write(dung1a);
            delay(normal_time);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            //4 servos (not sure if 3,4 can catch rubik on time bc theyre horizontal)
            delay(time1);
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(normal_time);
          } 
          else if (S[trash] == "D2") {
            Serial.println("Got D2");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            //4 servos move
            delay(time1);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(normal_time);
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(ngang1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            //one move
            delay(time2);
            Serv1a.write(dung1a);
            delay(normal_time);
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(ngang1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            delay(normal_time);
            Serv1a.write(dung1a);
            delay(normal_time);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            //4 servos (not sure if 3,4 can catch rubik on time bc theyre horizontal)
            delay(time1);
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(normal_time);
          }
          else if (S[trash] == "D'"){
            Serial.println("Got D'");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            //4 servos move
            delay(time1);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(normal_time);
            Serv1a.write(ngang1a);
            //one move
            delay(time2);
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(dung1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            //4 servos (not sure if 3,4 can catch rubik on time bc theyre horizontal)
            delay(time1);
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(normal_time);
          }
          else if (S[trash] == "D2'"){
            Serial.println("Got D2'");
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            //4 servos move
            delay(time1);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            delay(normal_time);
            Serv1a.write(ngang1a);
            //one move
            delay(time2);
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(dung1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            delay(normal_time);
            Serv1a.write(ngang1a);
            //one move
            delay(time2);
            Serv1b.write(xa1b);
            delay(normal_time);
            Serv1a.write(dung1a);
            delay(normal_time);
            Serv1b.write(gan1b);
            delay(normal_time);
            Serv3b.write(xa3b);
            Serv4b.write(xa4b);
            delay(normal_time);
            Serv3a.write(ngang3a);
            Serv4a.write(ngang4a);
            delay(normal_time);
            Serv3b.write(gan3b);
            Serv4b.write(gan4b);
            //4 servos (not sure if 3,4 can catch rubik on time bc theyre horizontal)
            delay(time1);
            Serv1b.write(xa1b);
            Serv2b.write(xa2b);
            delay(normal_time);
            Serv3a.write(dung3a);
            Serv4a.write(dung4a);
            delay(normal_time);
            Serv1b.write(gan1b);
            Serv2b.write(gan2b);
            delay(normal_time);
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
