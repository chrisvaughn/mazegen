//****************************************************************
//
// Name: Christopher Vaughn
// SL ID: cdv5673
// Date: 10/06/02
// Project: #3 Maze
//
// Filename: mazegen.h
//
// Certificate of Authenticity:
//	I Christopher Vaughn hereby state the following code is
//	entirely my own work.
//
//****************************************************************



#include "disjsets.h"


#ifndef _mazeGen_H_
#define _mazeGen_H_

class mazeGen
{

	public:
		mazeGen();
		mazeGen(Disjsets, int);
		~mazeGen();

		int randNum(int);
		int randDirection(int, int, int);

		int computeCell(int, int,int);
		void KnockDown(int,int, Disjsets, int);

		void StartFinish(Disjsets, int, int);

		void print(Disjsets, int, int);
		void GraphicPrint(Disjsets, int, int);
};

#endif


