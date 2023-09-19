#define trig 2 //Pin Trigger del Sensor
#define echo 3 //Pin Echo del Sensor

#define M11 5 //Pin 1 Motor 1
#define M12 6 //Pin 2 Motor 1

#define M21 10 //Pin 1 Motor 2
#define M22 11 //Pin 2 Motor 2

#define VelIn A0 //Pin de potenciometro velocidad

void setup()
{
  Serial.begin(9600); //Configuracion de velocidad del puerto Serie

  pinMode(VelIn, INPUT); //Pin de entrada Potenciometro

  pinMode(M11, OUTPUT); //Pin salida Motor 1
  pinMode(M12, OUTPUT); //Pin salida Motor 1
  pinMode(M21, OUTPUT); //Pin salida Motor 2
  pinMode(M22, OUTPUT); //Pin salida Motor 2

  digitalWrite(M11, LOW); //Inicializar en apagado
  digitalWrite(M12, LOW); //Inicializar en apagado
  digitalWrite(M21, LOW); //Inicializar en apagado
  digitalWrite(M22, LOW); //Inicializar en apagado

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  float Dist = 0;

  do
  {
    digitalWrite(trig, 0);//Inicializamos el pin en 0 para evitar falsos positivos
    delay(100);//Delay de 100ms para asegurar de que se reciba el siguiente pulso
    digitalWrite(trig, 1);//Cambiamos el pin a HIGH para dar el pulso de disparo
    delayMicroseconds(10);//Enviamos un pulso de 10Ms
    digitalWrite(trig, 0);

    Dist = pulseIn(echo, 1);//Obtenemos el ancho del pulso del pin echo
    Dist = Dist / 59; //dividimos por 59 para convertir a Cm
  }
  while (!(Dist > 0)); //El programa se mantendra en este bucle hasta confirmar que los sensores estan funcionando

  Serial.println("Programa Iniciado");
}


void loop()
{
    //Todo lo colocado aca se repetira constantemente
}
