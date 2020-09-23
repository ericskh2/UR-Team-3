#include <NewPing.h>
#include <vector>

//Ultrasonic Sensor Setup
#define TRIGGER_PIN_1 2
#define ECHO_PIN_1 3
#define TRIGGER_PIN_2 4
#define ECHO_PIN_2 5
#define MAX_DISTANCE 200


NewPing ultrasonic1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing ultrasonic2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);

//Motor Setup
#define motor1_in1 6
#define motor1_in2 9
#define motor2_in1 10
#define motor2_in2 11

//Time delay setup
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

//Maze
vector<int> travelled; // 0 = front, 1 = left, 2 = right, 3 = back
bool mazeSolved = false;

//Movement of Robot
void moveForward(int speed){
  analogWrite(motor1_in1,speed);
  analogWrite(motor1_in2,0);
  analogWrite(motor2_in1,speed);
  analogWrite(motor2_in2,0);
  travelled.push_back(0);
}

void turnLeft(int speed){
  analogWrite(motor1_in1,0);
  analogWrite(motor1_in2,speed);
  analogWrite(motor2_in1,speed);
  analogWrite(motor2_in2,0);
  travelled.push_back(1);
}

void turnRight(int speed){
  analogWrite(motor1_in1,speed);
  analogWrite(motor1_in2,0);
  analogWrite(motor2_in1,0);
  analogWrite(motor2_in2,speed);
  travelled.push_back(2);
} 

void moveBackward(int speed){
  analogWrite(motor1_in1,0);
  analogWrite(motor1_in2,speed);
  analogWrite(motor2_in1,0);
  analogWrite(motor2_in2,speed);  
}

void moveForward(long time, int speed){
  previousMillis = 0;
  while(true){
    currentMillis = millis();  
    if(currentMillis - previousMillis >= time){
      previousMillis = currentMillis;
    }
      break;
    }
    analogWrite(motor1_in1,speed);
    analogWrite(motor1_in2,0);
    analogWrite(motor2_in1,speed);
    analogWrite(motor2_in2,0);
    travelled.push_back(0);
}

void turnLeft(long time,int speed){
  previousMillis = 0;
  while(true){
    currentMillis = millis();
    if(currentMillis - previousMillis >= time){
      previousMillis = currentMillis;
      break;
    }
    analogWrite(motor1_in1,0);
    analogWrite(motor1_in2,speed);
    analogWrite(motor2_in1,speed);
    analogWrite(motor2_in2,0);
    travelled.push_back(1);
  }
}

void turnRight(long time, int speed){
  previousMillis = 0;
  while(true){
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= time){
      previousMillis = currentMillis;
      break;  
    }  
  analogWrite(motor1_in1,speed);
  analogWrite(motor1_in2,0);
  analogWrite(motor2_in1,0);
  analogWrite(motor2_in2,speed);
  travelled.push_back(2);
  }
} 

void moveBackward(long time, int speed){
  unsigned long previousMillis = 0;
  while(true){
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis ){
      previousMillis = currentMillis;
      break;
    }
    analogWrite(motor1_in1,0);
    analogWrite(motor1_in2,speed);
    analogWrite(motor2_in1,0);
    analogWrite(motor2_in2,speed);
  }
}

void stop(){
  analogWrite(motor1_in1,0);
  analogWrite(motor1_in2,0);
  analogWrite(motor2_in1,0);
  analogWrite(motor2_in2,0);  
}

void maze(bool leftMode){
  while(!mazeSolved){
    if(leftMode){
      if(left_distance<10){ // First rule: if there is road to left
        turnLeft(2000,255);
        moveForward(1000,255);
      } else if (front_distance<10){ // Second rule: if there is road forward
        moveForward(100,255);
        travelled.push_back(0);
        } else { //Third rule: if there is no road for left and forward
          turnRight(2000,255);
        }  
    }
  }
  vector<string>::iterator it; // print the shortest route at the end
  for(it = travelled.begin();it!=travelled.end();it++){
    Serial.print(*it);
  }
}

void setup() {
  Serial.begin(9600);
  // pinMode of ultrasonic sensors are defined in NewPing library itself
  pinMode(motor1_in1,OUTPUT);
  pinMode(motor1_in2,OUTPUT);
  pinMode(motor2_in1,OUTPUT);
  pinMode(motor2_in2,OUTPUT);
}
 
void loop() {
  delay(1000);
  Serial.print("Ping Sensor1: ");
  Serial.print(ultrasonic1.ping_cm());
  Serial.println("cm");
  Serial.print("Ping Sensor2: ");
  Serial.print(ultrasonic2.ping_cm());
  Serial.println("cm");
}