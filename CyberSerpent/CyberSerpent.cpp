
#include "CyberSerpent.h"

CyberSerpent::CyberSerpent()
	: m_Gameplay{ std::make_shared<Gameplay>(this) }, m_KeyboardReader{ std::make_shared<KeyboardReader>(this) }
{

}

CyberSerpent::~CyberSerpent()
{

}