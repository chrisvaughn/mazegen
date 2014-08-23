//****************************************************************
//
// Name: Christopher Vaughn
// SL ID: cdv5673
// Date: 10/06/02
// Project: #3 Maze
//
// Filename: mazegen.cpp
//
// Certificate of Authenticity:
//  I Christopher Vaughn hereby state the following code is
//  entirely my own work.
//
//****************************************************************

#include "mazegen.h"
#include "disjsets.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************
mazeGen::mazeGen()
{
    srand(time(NULL));
}

//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************
mazeGen::mazeGen(Disjsets maze, int elements)
{
    for (int i = 0; i <= elements - 1; i++)
    {
        maze.set[i].n = true;
        maze.set[i].s = true;
        maze.set[i].e = true;
        maze.set[i].w = true;
    }
    srand(time(NULL));
}

//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************

mazeGen::~mazeGen()
{
    NULL;
}

//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************
int mazeGen::randNum(int max)
{
    int num;

    num = (int)rand() % max;

    return num;

}

//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************
int mazeGen::randDirection(int selected, int Rows, int Cols)
{
    bool valid = false;

    int num;

    while (!valid)
    {
        num = rand() % 4;

        if (num == 0)
            NULL;

        else if (num == 1)  //NORTH
        {
            if (selected >= Cols)
                valid = true;
        }

        else if (num == 2) //SOUTH
        {
            if (selected <= ((Rows * Cols) - 1) - Cols)
                valid = true;
        }

        else if (num == 3) //EAST
        {
            bool isEqual = false;

            for (int i = Cols - 1; i <= (Rows * Cols) - 1; i = i + Cols)
            {
                if (selected == i)
                    isEqual = true;
            }

            if (!isEqual)
                valid = true;
        }

        else //WEST
        {
            bool isEqual = false;

            for (int i = 0; i <= (Rows * Cols) - Cols; i = i + Cols)
            {
                if (selected == i)
                    isEqual = true;
            }

            if (!isEqual)
                valid = true;
        }
    }
    return num;
}

//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************

int mazeGen::computeCell(int selected, int direction, int Cols)
{
    int newCell;

    if (direction == 1) //NORTH
        newCell = selected - Cols;
    else if (direction == 2) // SOUTH
        newCell = selected + Cols;
    else if (direction == 3) //EAST
        newCell = selected + 1;
    else //WEST
        newCell = selected - 1;

    return newCell;
}

//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************
void mazeGen::KnockDown(int selected, int direction, Disjsets maze, int Cols)
{
    if (direction == 1) //NORTH
    {
        maze.set[selected].n = false;
        maze.set[computeCell(selected, direction, Cols)].s = false;
    }

    else if (direction == 2) //SOUTH
    {
        maze.set[selected].s = false;
        maze.set[computeCell(selected, direction, Cols)].n = false;
    }

    else if (direction == 3) //EAST
    {
        maze.set[selected].e = false;
        maze.set[computeCell(selected, direction, Cols)].w = false;
    }

    else  //WEST
    {
        maze.set[selected].w = false;
        maze.set[computeCell(selected, direction, Cols)].e = false;
    }
}

//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************
void mazeGen::StartFinish(Disjsets maze, int Rows, int Cols)
{
    int start, finish = 0;

    start = rand() % (Cols - 1);

    finish = rand() % (Cols - 1); // step 1 of finish

    finish = ((Rows * Cols) - 1) - finish;

    maze.set[start].n = false;
    maze.set[finish].s = false;
}

//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************

void mazeGen::GraphicPrint(Disjsets maze, int Rows, int Cols)
{
    cout << ".";
    for (int t = 0; t < Cols; t++) //PRINTS TOP
    {
        if (maze.set[t].n)
            cout << "_";
        else
            cout << " ";
        cout << ".";
    }

    cout << endl;

    int index = 0;

    for (int i = 0; i < Rows; i++) //REPEAT FOR EACH ROW
    {
        for (int j = 0; j < Cols; j++) //FOR EACH COLUMN
        {
            if (j == 0)
            {
                if (maze.set[index].w)
                    cout << "|";
                else
                    cout << ".";
            }

            if (maze.set[index].s)
                cout << "_";
            else
                cout << " ";

            if (maze.set[index].e)
                cout << "|";
            else
                cout << ".";

            index++;
        }
        cout << endl;
    }
    cout << endl;

}

string mazeGen::buildHTML(Disjsets maze, int Rows, int Cols)
{
    string html = "";
    html += "<table id='mazegen' cellspacing=0 cellpadding=0>\n";

    int index = 0;

    for (int i = 0; i < Rows; i++) //REPEAT FOR EACH ROW
    {
        html += "\t<tr height=25>\n";
        for (int j = 0; j < Cols; j++) //FOR EACH COLUMN
        {
            html += "\t\t<td width=24 style='";
            if (maze.set[index].n)
            {
                html += "border-top: 2px black solid;";
            }
            if (maze.set[index].w)
            {
                html += "border-left: 2px black solid;";
            }
            if (maze.set[index].s)
            {
                html += "border-bottom: 2px black solid;";
            }
            if (maze.set[index].e)
            {
                html += "border-right: 2px black solid;";
            }
            html += "'</td>\n";
            index++;
        }
        html += "\t</tr>\n";
    }
    html += "</table>\n";

    return html;
}

//************************************************************
// Function:
// Pre: NONE
// Post: NONE
//************************************************************

void mazeGen::print(Disjsets maze, int Rows, int Cols)
{

    for (int i = 0; i <= Rows * Cols - 1; i++)
    {
        cout << "Cell: " << i + 1 << " - ";
        if (maze.set[i].n)
            cout << "N ";
        else
            cout << "  ";
        if (maze.set[i].s)
            cout << "S ";
        else
            cout << "  ";
        if (maze.set[i].e)
            cout << "E ";
        else
            cout << "  ";
        if (maze.set[i].w)
            cout << "W ";
        else
            cout << "  ";
        cout << endl;
    }
}
