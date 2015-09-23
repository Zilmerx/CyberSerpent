/*
 TODO LIST :

 Ajouter des mutex dans Send et autour de PortSerie.

*/

#include <iostream>
#include <windows.h>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <math.h>

using namespace std;

namespace IRobot
{

	enum DirectionY
	{
		HAUT = 11,
		BAS  = 12,
	};

	enum DirectionX
	{
		GAUCHE = 13,
		AVANT_GAUCHE = 14,
		AVANT_DROITE = 15,
		DROITE = 16
	};

	enum CodeSensor
	{
		BUMPER = 20,
		WHEEL = 21,
		CLIFF = 22,
		CLIFF_SIGNAL = 23,
		WALL = 24,
		WALL_SIGNAL = 25,
		VIRTUAL_WALL = 26,
		BATTERY_CHARGE = 27,
		BATTERY_CAPACITY = 28,
		DISTANCE = 29,
		ANGLE = 30
	};

	enum SuivreLigneState
	{
		TROP_A_DROITE = 41,
		TROP_A_GAUCHE = 42,
		INTERSECTION = 43,
		CENTRE = 44
	};


	class IRobot
	{

	public:

	   // Fonctions de mouvement du robot.
	   void Avant( short Vitesse );
	   void Arriere( short Vitesse );
	   void Stop ();
	   // Tourner sur place.
	   void HDroite( short Vitesse );
	   void HGauche( short Vitesse );
	   // Tourner avec un pourcentage de vitesse de moins sur une route.
	   void Droite( short Vitesse, char TournurePourcentage );
	   void Gauche( short Vitesse, char TournurePourcentage );
	   // Tourner sur place jusqu'à ce que l'on aie atteint l'angle.
	   void ADroite ( short Vitesse, char Angle);
	   void AGauche ( short Vitesse, char Angle);




	   // Fonction SuivreLigne, permet de suivre une ligne sur le sol à la vitesse entrée en paramètre.
	   char SuivreLigne( int Vitesse, int Luminosite_Plancher, int Luminosite_Bande);


	   // Fonction pour conduire un peu plus complexe. 
	   void Drive( short VitesseGauche, short VitesseDroite);


	   // Fonctions qui retournent la valeur des sensors.
	   // Fonction qui permet de lire les valeurs de retour des sensors. 
	   int Sensor(CodeSensor sensor);
	   int IRobot::Sensor(CodeSensor sensor, DirectionX precision);

	   // Fonction qui fait 5 verification de la valeur des sensors et retourne la moyenne.
	   int S_Sensor(CodeSensor sensor);
	   int S_Sensor(CodeSensor sensor, DirectionX precision);

	   // Fonction qui fait jouer une musique.
	   void IRobot::Music(int Numero);


	   // Constructeur --- Destructeur.
	   IRobot();
	   ~IRobot();

	private:

	   // Membres.
	   HANDLE PortSerie;
	   int m_Temps_Ecriture;
	   int m_Temps_Lecture;


	   // Fonction de démarrage.
	   void SetConnection();
	   // Sette les paramètres de communication.
	   void ComSetup(HANDLE PortSerie, int BaudRate, short ByteSize, short Parity, short StopBits);
	   // Sette les paramètres pour le timeout de la communication.
	   void ComTimeoutSetup( int IT, int RTTM, int RTTC, int WTTM, int WTTC);
	   // Envoie un message de salutation sonore.
	   void Bonjour();
	   // Permet de mettre des musiques dans le robot.
	   /*
	   1. Charge.
	   2. Erreur.
	   3. Song of storm.
	   */
	   void SetMusique();
	   // Enleve les messages à l'allumage du robot.
	   void Flush(int Quantité);

	   // Fonction d'écriture, permet d'envoyer le nombre de valeurs voulues au robot.
	   void Send(char arg1, ...);

	   // Fonction de lecture, permet d'envoyer des valeurs au robot et de lire le message de retour.
	   int Read(unsigned char Param1,bool HighByte);
	   int Read(unsigned char Param1, unsigned char Param2,bool HighByte);
	   int Read(unsigned char Param1, unsigned char Param2, unsigned char Param3,bool HighByte);
	   int Read(unsigned char Param1, unsigned char Param2, unsigned char Param3, unsigned char Param4,bool HighByte);
	   int Read(unsigned char Param1, unsigned char Param2, unsigned char Param3, unsigned char Param4, unsigned char Param5,bool HighByte);
	   int Read(unsigned char Param1, unsigned char Param2, unsigned char Param3, unsigned char Param4, unsigned char Param5, unsigned char Param6,bool HighByte);
	   int Read(unsigned char Param1, unsigned char Param2, unsigned char Param3, unsigned char Param4, unsigned char Param5, unsigned char Param6, unsigned char Param7,bool HighByte);

	   // Envoi de message d'erreur à l'utilisateur.
	   int Erreur( char* message, DWORD erreur, bool Shutdown );

	   // Transformation d'un short en un char, en choisissant si on veut le quartet HAUT ou BAS.
	   char ShortToChar(short Valeur, int PositionQuartet);

	};

}

