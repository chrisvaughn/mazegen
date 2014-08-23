//****************************************************************
//
// Name: Christopher Vaughn
// SL ID: cdv5673
// Date: 10/06/02
// Project: #3 Maze
//
// Filename: disjsets.h
//
// Certificate of Authenticity:
//	I Christopher Vaughn hereby state the following code is
//	entirely my own work.
//
//****************************************************************

#ifndef _Disjsets_H_
#define _Disjsets_H_

struct CellInfo
{
	int parent;
	bool n;
	bool s;
	bool e;
	bool w;
};


class Disjsets
{
	public:
		explicit Disjsets(int);

		int find(int);
		void unionSets(int, int);
		void print();
		bool OnlyOne();
		int WhatElements();

		CellInfo *set;

	private:
		int Elements;
};

#endif
