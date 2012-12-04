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

using namespace std;

class Life {
public:
    Life();
    Life(const Life& orig);
    Life(ifstream inFile, ofstream outFile);
    virtual ~Life();
    void refresh();
    void checkNeighbors();
    void printBoard();
    void initalize();
private:
    int generation;
    std::vector<ACell> ACells;
    std::vector<BCell> BCells;

};

#endif	/* LIFE_H */

