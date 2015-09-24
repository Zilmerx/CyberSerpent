#pragma once

#include <memory>

class CyberSerpent;

class VideoAnalyzer
{
	CyberSerpent* m_Game;

public:
	VideoAnalyzer();
	~VideoAnalyzer();

	void Initialize(CyberSerpent* linked);
};