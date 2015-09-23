#pragma once

#include <vector>
#include "Point2D.h"
#include "CyberSerpent.h"

class CyberSerpent;

class Gameplay
{
   std::shared_ptr<CyberSerpent> m_Game;

   std::vector<Point2D> m_Obstacles;

public:

   const static int MAPSIZE_X = 500;
   const static int MAPSIZE_Y = 500;


private:
   // Mets "amount" Point2D dans le tableau, qui ont un x,y entre "0" et "MAPSIZE_X"/"MAPSIZE_Y".
   void fillWithRandPoints(std::vector<Point2D>& tab, int amount);


public:
   Gameplay(CyberSerpent* serpent);
   ~Gameplay();

};