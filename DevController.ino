const int lightSensor = A0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("1: Light sensor on");
  Serial.println("2: Light sensor off");
  Serial.println("3: Read light sensor");
}

void loop() {
  if (Serial.available()) 
  {
    switch (Serial.readStringUntil("\n").toInt())
    {
      case 1:
        Serial.println("Switching Light sensor on");
        digitalWrite(LED_BUILTIN, HIGH);    
        break;
      case 2:
        Serial.println("Switching Light sensor off");
        digitalWrite(LED_BUILTIN, LOW);    
        break;
      case 3:
        Serial.println(analogRead(lightSensor));
        break;
      default:
        Serial.println("Invalid option");
    } 
  }
}
