
class Detecteur{

  private:
  
    int echo = 0;
    int trig = 0;
    long lecture_echo;
    long cm;
  
  public:

  void setup(int e, int t) //initialisation port de communication
  {
    echo = e;
    trig = t;
    pinMode(trig, OUTPUT);
    digitalWrite(trig, LOW);
    pinMode(echo, INPUT);

  
  }
  
   int Valeur()//retour la distance détecter par le capteur
   {
      digitalWrite(trig, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig, LOW);
      lecture_echo = pulseIn(echo, HIGH);
      cm = lecture_echo / 58;
      return cm;
   }
   

};
