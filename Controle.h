
class Controle{

  private:

    const int forward = 3;
    const int back = 4;
    const int right = 5;
    const int left = 6;
  
  public:

  void setup() //initialisation port controle moteur
  {
      pinMode(forward, OUTPUT);
      pinMode(back, OUTPUT);
      pinMode(right, OUTPUT);
      pinMode(left, OUTPUT);
  
  }
  
   void Avancer()
   {
      digitalWrite(forward,HIGH);
      digitalWrite(back,LOW);
   }
   
   void Reculer()
   {
      digitalWrite(back,HIGH);
      digitalWrite(forward,LOW);
   }
   
   void Arreter()
   {
      digitalWrite(forward,LOW);
      digitalWrite(back,LOW);
   }

   void TournerDroite()
   {
      digitalWrite(right,HIGH);
      digitalWrite(left,LOW);
   }

   void TournerGauche()
   {
      digitalWrite(left,HIGH);
      digitalWrite(right,LOW);
   }

   void ToutDroit()
   {
      digitalWrite(right,LOW);
      digitalWrite(left,LOW);
   }

   
  void Control(int propultion, int mouvement)//Fonction de control
  {
      if (propultion == 0)
      {
          Arreter();
      }
      if (propultion == 1)
      {
          Avancer();
      }
      if (propultion == 2)
      {
          Reculer();
      }
      if (mouvement == 0)
      {
          ToutDroit();
      }
      if (mouvement == 1)
      {
          TournerGauche();
      }
      if (mouvement == 2)
      {
          TournerDroite();
      }
  }
   
};



