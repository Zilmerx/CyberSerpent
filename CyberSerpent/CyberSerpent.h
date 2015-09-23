#pragma once

#include <memory>

#include "Gameplay.h"
#include "IRobotDriver.h"
#include "KeyboardReader.h"

class Gameplay;
class IRobot::IRobot;
class KeyboardReader;

class CyberSerpent
{
	std::shared_ptr<Gameplay> m_Gameplay;
	std::shared_ptr<IRobot::IRobot> m_IRobotDriver;
	std::shared_ptr<KeyboardReader> m_KeyboardReader;

public:
	friend class Gameplay;
	friend class IRobot::IRobot;
	friend class KeyboardReader;

	CyberSerpent();
	~CyberSerpent();
private:

};