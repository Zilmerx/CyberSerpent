#pragma once

#include <memory>

#include "Gameplay.h"
#include "IRobotDriver.h"
#include "KeyboardReader.h"
#include "VideoAnalyzer.h"

class CyberSerpent
{
	Gameplay m_Gameplay;
	IRobot::IRobot m_IRobotDriver;
	KeyboardReader m_KeyboardReader;
	VideoAnalyzer m_VideoAnalyzer;

	bool m_Initialized;
public:

	CyberSerpent();
	~CyberSerpent();

	bool Initialize();

	void Start();

private:

	void TournerRobotGauche();
	void TournerRobotDroite();

};