/* 
 * File:   Life.h
 * Author: Charles
 *
 * Created on December 2, 2012, 12:47 AM
 */

#ifndef LIFE_H
#define	LIFE_H

#include "vector"
#include "ACell.h"
#include "BCell.h"
#include "fstream"
#include "string"

using namespace std;

class Life {
public:
    Life();
    Life(const Life& orig);
    Life(ifstream& inFile, ofstream& outFile);
    virtual ~Life();
    void refresh();
    void checkNeighbors(int actualCellx, int actualCelly);
    void printBoard(ofstream& outFile);
    void initalize();
    void check();
    void setAlive();
private:
    int generation;
    int rows;
    int columns;
    string gameType;
    vector<vector<ACell> > ACells;
    vector<vector<BCell> > BCells;

};

#endif	/* LIFE_H */

