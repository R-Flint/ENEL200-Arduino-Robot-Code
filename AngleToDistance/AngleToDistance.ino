const float WB = 0.5; // wheel base (m)

float angleToDistance(float angle_degrees) {
  float angle_radians = (angle_degrees * 3.14) / 180 // converts angle in degrees to radians 
  return (angle_radians * WB) / 2; // formula for angle -> distance
}


void setup() {
  Serial.begin(9600); // open coms
  while (!Serial.available()) {} // while getting user input

  float angle = Serial.parseFloat(); // get angle
  float distance = Serial.parseFloat()// get distance

  serial.print("left wheel distance: ")
  serial.println(distance)
  serial.print("right wheel distance: ")
  serial.println(-distance)

}

void loop() {
  // put your main code here, to run repeatedly:

}
