#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <vector>

class Unit{

private:



public:

	int loseHP(int a,int b){return (a-b);};

};

struct sNode{

		bool bObstacle = false;
		bool bVisited = false;
		float fGlobalGoal;
		float fLocalGoal;
		int x;
		int y;
		std::vector <sNode*> vecNeighbours;
		sNode* parent;
	};

#endif // UNIT_H
