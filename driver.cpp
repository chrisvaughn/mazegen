//****************************************************************
//
// Name: Christopher Vaughn
// SL ID: cdv5673
// Date: 10/06/02
// Project: #3 Maze
//
// Filename: driver.cpp
//
// Certificate of Authenticity:
//  I Christopher Vaughn hereby state the following code is
//  entirely my own work.
//
//****************************************************************

#include "disjsets.h"
#include "mazegen.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    int menuSel;
    int randCell, direction, rCParent, adjParent;
    int numRows, numCols;

    bool validMenu = false;
    ofstream html_out;
    html_out.open ("maze.html");

    cout << "Please Enter the number of Rows: ";
    cin >> numRows;

    cout << "Please Enter the number of Columns: ";
    cin >> numCols;

    int elements = numRows * numCols;

    Disjsets a(elements);

    mazeGen maze(a, elements);

    while (!a.OnlyOne())
    {
        randCell = maze.randNum(elements - 1);
        direction = maze.randDirection(randCell, numRows, numCols);
        rCParent = a.find(randCell);
        adjParent = a.find(maze.computeCell(randCell, direction, numCols));
        if (rCParent != adjParent)
        {
            a.unionSets(rCParent, adjParent);
            maze.KnockDown(randCell, direction, a, numCols);
        }
    }

    maze.StartFinish(a, numRows, numCols);

    maze.GraphicPrint(a, numRows, numCols);
    html_out << maze.buildHTML(a, numRows, numCols);
    html_out.close();
}
