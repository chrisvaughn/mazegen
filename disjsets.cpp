//****************************************************************
//
// Name: Christopher Vaughn
// SL ID: cdv5673
// Date: 10/06/02
// Project: #3 Maze
//
// Filename: disjsets.cpp
//
// Certificate of Authenticity:
//	I Christopher Vaughn hereby state the following code is
//	entirely my own work.
//
//****************************************************************

#include "disjsets.h"
#include <iostream>
	using namespace std;

//************************************************************
// Function: Disjsets CONSTRUCTOR
// Pre: NONE
// Post: NONE
//************************************************************

Disjsets::Disjsets(int numElements)
{
	Elements = numElements;

	set = new CellInfo[Elements];

	for(int i=0; i <= Elements - 1; i++)
	{
		set[i].parent = -1;
	}
}

//************************************************************
// Function: 
// Pre: NONE
// Post: NONE
//************************************************************

int Disjsets::find(int index)
{
	if(set[index].parent < 0)
	{
		return index;
	}

	else
		return set[index].parent = find(set[index].parent);

}

//************************************************************
// Function: 
// Pre: NONE
// Post: NONE
//************************************************************

void Disjsets::unionSets(int root1, int root2)
{
	if(set[root1].parent < set[root2].parent)
	{
		int temp = set[root2].parent;
		set[root2].parent = root1;
		set[root1].parent = set[root1].parent + temp;
	}

	else if(set[root2].parent < set[root1].parent)
	{
		int temp = set[root1].parent;
		set[root1].parent = root2;
		set[root2].parent = set[root2].parent + temp;
	}

	else
	{
		if(set[root1].parent == set[root2].parent)
			set[root1].parent = 2*set[root1].parent;
		set[root2].parent = root1;
	}
}

//************************************************************
// Function: 
// Pre: NONE
// Post: NONE
//************************************************************

void Disjsets::print()
{
	for(int i=0; i <= Elements - 1; i++)
	{
		cout<<set[i].parent<<" ";
	}
	cout<<endl;

}

//************************************************************
// Function: 
// Pre: NONE
// Post: NONE
//************************************************************

bool Disjsets::OnlyOne()
{
	int numChildren = Elements*-1;

	bool OnlyOne = false;

	for(int i = 0;i<= Elements-1;i++)
	{
		if(set[i].parent == numChildren)
			OnlyOne = true;
	}

	return OnlyOne;
}

//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************

int Disjsets::WhatElements()
{
	return Elements;
}
