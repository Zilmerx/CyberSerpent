#pragma once

#include <memory>

class CyberSerpent;

class VideoAnalyzer
{
	std::shared_ptr<CyberSerpent> m_Game;


public:
	VideoAnalyzer(CyberSerpent* parent);
	~VideoAnalyzer();
};