int AIRPUMP[3] = {2, 4, 3};
int DCMOTOR_A = 5, DCMOTOR_B = 6;
int TRIGGER = 7;
int ECHO[3] = {8, 12, 13};

unsigned long beginTime, elaspedTime;

int airpump[3] = {LOW, LOW, HIGH};
void TurnAirpump(int idx){
  airpump[idx] = !airpump[idx];
  digitalWrite(AIRPUMP[idx], airpump[idx]);
}

void RotateDCMotor(int isStraight){
  if (isStraight == 1){ // GO STRAIGHT
    digitalWrite(DCMOTOR_A, LOW);
    digitalWrite(DCMOTOR_B, HIGH);
  }
  else{ // GO REVERSE
    digitalWrite(DCMOTOR_A, HIGH);
    digitalWrite(DCMOTOR_B, LOW);
  }
}

void StopDCMotor(){
  digitalWrite(DCMOTOR_A, LOW);
  digitalWrite(DCMOTOR_B, LOW);
}

int ratio[3], check = 0, tmp[3];
int ratioSum;
void GetMixRatio(){
  for (int i = 14; i <= 19; ++i){
    if (analogRead(i) < 90 && i != tmp[0] && i != tmp[1]){
      tmp[check] = i;
      ratio[check] = i-13;
      ratioSum += i-13;
      check++;
    }
  }
}

float GetDistance(int idx){
  digitalWrite(TRIGGER, LOW);
  digitalWrite(ECHO[idx], LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);
  unsigned long duration = pulseIn(ECHO[idx], HIGH);
  return (float)(340*duration)/20000;
}

void setup(){
  // AIRPUMP
  pinMode(AIRPUMP[0], OUTPUT);
  pinMode(AIRPUMP[1], OUTPUT);
  pinMode(AIRPUMP[2], OUTPUT);
  // DC MOTOR
  pinMode(DCMOTOR_A, OUTPUT);
  pinMode(DCMOTOR_B, OUTPUT);
  // TRIGGER, ECHO;
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO[0], INPUT);
  pinMode(ECHO[1], INPUT);
  pinMode(ECHO[2], INPUT);

  // INIT AIRPUMPS
  for (int i = 0; i < 3; ++i)
    digitalWrite(AIRPUMP[i], airpump[i]);

  Serial.begin(9600);
  beginTime = millis();
}

bool ratioPrint = false;
bool dispensing[3], dispensed[3];
bool motorFinished[3];
bool finished;
int shift=1;
unsigned long beginDispenseTime[3];
void loop(){
  if (finished)
    return;
  elaspedTime = millis()-beginTime;
  
  if (check < 3)
    GetMixRatio();
  else{
    if (!ratioPrint){
    Serial.println(ratio[0]);
    Serial.println(ratio[1]);
    Serial.println(ratio[2]);
    ratioPrint = true;
    }
    if (GetDistance(0) < 3 && GetDistance(0)!=0 && !dispensed[0] && shift==1){
      if (!dispensing[0]){
        dispensing[0] = true;
        TurnAirpump(0);
        beginDispenseTime[0] = elaspedTime;
      }
      if (elaspedTime-beginDispenseTime[0] > 10000.0*ratio[0]/ratioSum){
        shift++;
        Serial.println(shift);
        TurnAirpump(0);
        dispensed[0] = true;
        RotateDCMotor(1);
      }
    }
    else if (GetDistance(1) < 3 && GetDistance(1)!=0 && !dispensed[1] && shift==2){
      if (!motorFinished[1]){
        delay(100);
        StopDCMotor();
        delay(500);
        motorFinished[1] = true;
      }
      if (!dispensing[1]){
        dispensing[1] = true;
        TurnAirpump(1);
        beginDispenseTime[1] = elaspedTime;
      }
      if (elaspedTime-beginDispenseTime[1] > 10000.0*ratio[1]/ratioSum){
        shift++;
        Serial.println(shift);
        TurnAirpump(1);
        dispensed[1] = true;
        RotateDCMotor(1);
      }
    }
    else if (GetDistance(2) < 3 && GetDistance(2)!=0 && !dispensed[2] && shift==3){
      if (!motorFinished[2]){
        delay(100);
        StopDCMotor();
        delay(500);
        motorFinished[2] = true;
      }
      if (!dispensing[2]){
        dispensing[2] = true;
        TurnAirpump(2);
        beginDispenseTime[2] = elaspedTime;
      }
      if (elaspedTime-beginDispenseTime[2] > 10000.0*ratio[2]/ratioSum){
        shift++;
        Serial.println(shift);
        TurnAirpump(2);
        dispensed[2] = true;
        finished = true;
        //StopDCMotor();
      }
    }
  }
}
