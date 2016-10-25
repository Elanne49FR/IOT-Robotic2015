#include <SoftwareSerial.h>

SoftwareSerial mavoieserie(8, 9); // (RX, TX) (pin Rx BT, pin Tx BT)

class Communication{

  public:

  void setup() 
  {
        // Ouvre la voie série avec l'ordinateur
        Serial.begin(9600);
        // Ouvre la voie série avec le module BT
        mavoieserie.begin(9600); //38400 quand mode commande forcé
        mavoieserie.write("Bienvenue dans le panneau de controle de votre Voiture Intelligente ");
  }
  
   char lirelog()
   {
      return mavoieserie.read();//Lire trame bluetooth
   }

   
};



