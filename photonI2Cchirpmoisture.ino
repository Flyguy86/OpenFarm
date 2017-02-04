// Chirp I2C Moisture sensor Base Calibration,   615 = Glass of water   320 = No contact     Damp soil = 460

//SYSTEM_MODE(MANUAL);
TCPClient webClient;
TCPServer webServer = TCPServer(88);

unsigned int moist;
unsigned int temp;
unsigned short int light;
unsigned long int lastAttemp;
unsigned int sensorRefresh = 60000; // 1000=1second 350000=5min
unsigned int maxSensorValue = 65000;  //if above this value, will reset photon and attempt to sync back up with sensor
char publishString[64];

void writeI2CRegister8bit(int addr, int reg, int value) {
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.write(value);
  Wire.endTransmission();
}

void writeI2CRegister8bit(int addr, int value) {
  Wire.beginTransmission(addr);
  Wire.write(value);
  Wire.endTransmission();
}

unsigned int readI2CRegister16bit(int addr, int reg) {
  Wire.beginTransmission(addr);
  Wire.write(reg);
  Wire.endTransmission();
  delay(20);
  Wire.requestFrom(addr, 2);
  unsigned int t = Wire.read() << 8;
  t = t | Wire.read();
  return t;
}

void serveWebpage() {

  webClient.print("<html><body>");
  webClient.print("{ \"Time\": \"");
  webClient.print(Time.now()); 
  webClient.print("\", "); // opening JSON
  webClient.print(" \"Name\": \"Mositure\", "); // Device ID
  webClient.print(" \"Loc\": \"GreenHouse1\", "); // Device ID
  webClient.print(" \"Orient\": \"Front Right\", "); // Device ID
  webClient.print("\"TempRaw\": \"");
  webClient.print(temp);
  webClient.print("\", ");
  webClient.print("\"Moist\": \"");
  webClient.print(moist);
  webClient.print("\", ");
  webClient.print("\"Light\": \"");
  webClient.print(light);
  webClient.print("\" } ");  //closing JSON statement
  webClient.println("</body></html>\n\n");
  webClient.flush();
  webClient.stop();
}

void serveWebpageNoData() {

  webClient.print("<html><body>");
  webClient.print("{ \"Reading\": \"Sensor\"}");
  webClient.println("</body></html>\n\n");  
  webClient.flush();
  webClient.stop();
}


void readsensor(void)
{
 if(millis()-lastAttemp < sensorRefresh && moist != 0)
    return;

  writeI2CRegister8bit(0x20, 3); //request light measurement
  moist = readI2CRegister16bit(0x20, 0);
  temp = readI2CRegister16bit(0x20, 5);
  light = readI2CRegister16bit(0x20, 4);
  Serial.print(" Moisture: ");
  Serial.print(moist); //read capacitance register
  Serial.print(", Temperature (k): ");
  Serial.print(temp); //temperature register
  Serial.print(", Light level: ");
  Serial.println(light); //read light register
  
  lastAttemp = millis();
 
  if ( moist > maxSensorValue || temp > maxSensorValue || light > maxSensorValue ){
        writeI2CRegister8bit(0x20, 6); //reset I2C sensor
//      System.reset(); 
  }else{
		sprintf(publishString,"{\"Moisture\": %d, \"Temperature\": %d, \"Light Leve\": %d}",moist,temp,light);
		Particle.publish("Sensor", publishString);
  }
  
  // read DHT temp/Humid sensor here... After I2C communications
}


void setup() {
  Wire.begin();
  Serial.begin(9600);
//  writeI2CRegister8bit(0x21, 1, 0x20);  changes the address...
  writeI2CRegister8bit(0x20, 6); //reset
  writeI2CRegister8bit(0x20, 3); //request light measurement
}

void loop() {

  if (webClient.connected() && webClient.available()) {
    serveWebpage();
    webClient.stop();
  }
  else {
    readsensor();
    webClient = webServer.available();
  }
      
}
