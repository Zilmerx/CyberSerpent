/*
 TODO LIST :

 Ajouter des mutex dans Send et autour de PortSerie.

*/

#include <iostream>
#include <windows.h>

using namespace std;

namespace IRobot
{

	enum DirectionY
	{
		HAUT,
		BAS,
	};

	enum DirectionX
	{
		GAUCHE,
		AVANT_GAUCHE,
		AVANT_DROITE,
		DROITE
	};

	enum CodeSensor
	{
		BUMPER,
		WHEEL,
		CLIFF,
		CLIFF_SIGNAL,
		WALL,
		WALL_SIGNAL,
		VIRTUAL_WALL,
		BATTERY_CHARGE,
		BATTERY_CAPACITY,
		DISTANCE,
		ANGLE
	};

	enum SuivreLigneState
	{
		TROP_A_DROITE,
		TROP_A_GAUCHE,
		INTERSECTION,
		CENTRE
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
	   int Sensor(CodeSensor sensor, DirectionX precision);

	   // Fonction qui fait 5 verification de la valeur des sensors et retourne la moyenne.
	   int S_Sensor(CodeSensor sensor);
	   int S_Sensor(CodeSensor sensor, DirectionX precision);

	   // Fonction qui fait jouer une musique.
	   void Music(int Numero);


	   // Constructeur --- Destructeur.
	   IRobot();
	   ~IRobot();

	private:

	   // Membres.
	   HANDLE PortSerie;
	   const int m_Temps_Ecriture;
	   const int m_Temps_Lecture;


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
	   int IRobot::Read(bool HighByte, char arg1, ...);

	   // Envoi de message d'erreur à l'utilisateur.
	   int Erreur( char* message, DWORD erreur, bool Shutdown );

	   // Transformation d'un short en un char, en choisissant si on veut le quartet HAUT ou BAS.
	   char ShortToChar(short Valeur, int PositionQuartet);
	};

}

