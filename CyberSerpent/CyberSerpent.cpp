
#include "CyberSerpent.h"


CyberSerpent::CyberSerpent()
	: m_Gameplay{}, m_IRobotDriver{}, m_KeyboardReader{}, m_VideoAnalyzer{}, m_Initialized{ false }
{
}

CyberSerpent::~CyberSerpent()
{
}

bool CyberSerpent::Initialize()
{
	//if (!m_IRobotDriver.Initialize())
	//	return false;

	m_KeyboardReader.setFunction(75, std::bind(&CyberSerpent::TournerRobotGauche, this));
	m_KeyboardReader.setFunction(77, std::bind(&CyberSerpent::TournerRobotDroite, this));

	m_VideoAnalyzer.Initialize(this);

	m_Initialized = true;
	return true;
}

void CyberSerpent::Start()
{
	if (!m_Initialized)
		return;

	m_KeyboardReader.start();
}


void CyberSerpent::TournerRobotGauche()
{
	std::cout << "GAUCHE" << std::endl;
	m_IRobotDriver.Gauche(100, 75);
}

void CyberSerpent::TournerRobotDroite()
{
	std::cout << "DROITE" << std::endl;
	m_IRobotDriver.Droite(100, 75);
}
