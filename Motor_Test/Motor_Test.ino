
const int IN1 = 26;
const int IN2 = 25;
int enable1Pin = 23;
//int enable2Pin = 22;

int velocidadDerecha = 150; //ciclo de trabajo de 0 a 255
int canal1MotorD = 0;
int canal2MotorD = 1;

int frecuencia = 10000;
int resolucion = 8;

void setup() {
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  //pinMode (enable1Pin, OUTPUT);
  //pinMode (enable2Pin, OUTPUT);
  
  ledcSetup (canal1MotorD,frecuencia,resolucion);
  ledcAttachPin (IN1,canal1MotorD);

  ledcSetup (canal2MotorD,frecuencia,resolucion);
  ledcAttachPin (IN2,canal2MotorD);
}

void loop() {
  // put your main code here, to run repeatedly:
 
  giroHorario (canal1MotorD, canal2MotorD, velocidadDerecha);
  delay (3000);
  giroAntihorario (canal1MotorD, canal2MotorD, velocidadDerecha);
  delay (3000);
  pararMotor (canal1MotorD, canal2MotorD);
  delay (3000);
}

void giroHorario (int canal1, int canal2, int cv)
{

ledcWrite (canal1, cv);
ledcWrite (canal2, 0);
}

void giroAntihorario (int canal1, int canal2, int cv)
{

ledcWrite (canal1, 0);
ledcWrite (canal2, cv);
}

void pararMotor (int canal1, int canal2)
{
ledcWrite (canal1, 0);
ledcWrite (canal2, 0);
}
