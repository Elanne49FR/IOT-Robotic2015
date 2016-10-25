
#include "Controle.h"
#include "Detecteur.h"
#include "Communication.h"

class Mode{

  private:

    int MarcheAvantArriere = 0;  // 0 : Pas de Mouvement | 1: Marche Avant | 2: Marche Arriere
    int Orientation = 0; // 0 : Pas de Direction | 1: Droite | 2: Gauche
    int mur = 0; // Detection des Murs
    int milli = 0; // Temps de Traitement
    Controle cont;
    Detecteur detectgauche;
    Detecteur detectdroite;
    Communication com;
    char Message= 'I';
  
  public:

  void setup() 
  {
      com.setup();
      cont.setup();
      detectgauche.setup(11,13);
      detectdroite.setup(10,12);
  }
  
   void Automatique()//Passage mode automatique
  {
  
  while(Message != 'M')//Tant que passage Manuel non demandé
  {   
    
    Message = com.lirelog();//Lire trame bluetooth
    
    if(mur == 0)//Si mur non detecté
    {
        
       
        if(detectgauche.Valeur() <= 30 && detectdroite.Valeur() > 30)//si elle voit a gauche
        {
              MarcheAvantArriere= 1;//elle avance
              Orientation 2; //elle tourne MarcheAvantArrieredroite
              milli = 0;
        } 
          
        if(detectdroite.Valeur() <= 30 && detectgauche.Valeur() > 30)//si elle voit a droite
        {
              MarcheAvantArriere = 1;//elle avance
              Orientation 1;//elle tourne a gauche
              milli = 0;
        }
        
        if(detectdroite.Valeur() > 35 && detectgauche.Valeur() > 35)//si elle ne voit rien 
        {
              MarcheAvantArriere = 1;//elle avance
              Orientation 0;//elle avance tout droit
              milli = 0;
        }
        
        if(detectdroite.Valeur() <= 35 && detectgauche.Valeur() <= 35)//si elle voit a droite et a gauche   
        {
              MarcheAvantArriere = 0;//elle stop 
              
              if(milli == 0)
              {
                  milli = millis();
              }

              if(milli != 0 && millis() > milli + 2000)
              {
                  mur = 1;
                  milli = 0;
              }
        }
 
        
        
    }

  if(mur == 1)//Si mur detecter on recule
  {
        
        if (detectgauche.Valeur() <= detectdroite.Valeur())
        {
          Orientation 2;
          MarcheAvantArriere = 2;
        }
  
        if (detectdroite.Valeur() > detectgauche.Valeur())
        {
          Orientation 1;
          MarcheAvantArriere = 2;
        }
        
        if(milli == 0)
        {
          milli = millis();
        }
        
        if(milli != 0 && millis() > milli + 3000)
        {
           mur = 2;
           milli = 0;
        }
     
  }

  if(mur == 2)//Si mur detecter on évite
  {
        
        if (detectgauche.Valeur() <= detectdroite.Valeur())
        {
          Orientation 1;
          MarcheAvantArriere = 1;
        }
  
        if (detectdroite.Valeur() > detectgauche.Valeur())
        {
          Orientation 2;
          MarcheAvantArriere = 1;
        }
        
        if(milli == 0)
        {
          milli = millis();
        }
        
        if(milli != 0 && millis() > milli + 3000)
        {
           mur = 0;
           milli = 0;
        }
     
  }
  
  cont.Control(a,b);
  }
  
  cont.Control(0,0);
  Manuel();
}

void Manuel()//passage mode manuel
{
  while(Message != 'A')
  {   
    Message = com.lirelog();//Lire trame bluetooth
    
    if(Message == 's')
        {
          MarcheAvantArriere = 0;
        }   
    if(Message == 'a')
        {
          MarcheAvantArriere = 1;
        }   
    if(Message == 'r')
        {
          MarcheAvantArriere = 2;
        }
    if(Message == 'p')
        {
          Orientation 0;
        }   
    if(Message == 'd')
        {
          Orientation 1;
        }   
    if(Message == 'g')
        {
          Orientation 2;
        }
     
    cont.Control(a,b);
  }
  
  Automatique();
}    
   
};



