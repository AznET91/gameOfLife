/* 
 * File:   Life.cpp
 * Author: Charles
 * 
 * Created on December 2, 2012, 12:47 AM
 */

#include "Life.h"

Life::Life() {
    generation = 0;
}

Life::Life(const Life& orig) {
}

Life::~Life() {
}

Life::Life(ifstream& inFile, ofstream& outFile){
    //type of game
    //number of rows
    //number of columns
   
    inFile >> gameType >> rows >> columns;
    
    outFile << gameType << endl;
    outFile << rows << endl;
    outFile << columns << endl;
}

void Life::refresh() {
    if (gameType.compare("A") == 0) {

        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= columns; j++) {
                if (ACells[i][j].getNewStatus() == 0) {
                    ACells[i][j].kill();
                } else
                    ACells[i][j].res();
            }
        }
    } else {
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= columns; j++) {
                if (BCells[i][j].getNewStatus() == 0) {
                    BCells[i][j].kill();
                } else
                    BCells[i][j].res();
            }
        }
    }
}
    

void Life::printBoard(ofstream& outFile) {

    if (gameType.compare("A") == 0) {
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= columns; j++) {
                if (ACells[i][j].isAlive()) {
                    outFile << "*";
                } else
                    outFile << ".";
            }
            outFile << endl;
        }
        outFile << endl;
    }
    else {
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= columns; j++) {
                if (BCells[i][j].isAlive()) {
                    if (BCells[i][j].getAge() <= 10)
                        outFile << BCells[i][j].getAge();
                    else
                        outFile << "+";
                } 
                else
                    outFile << "-";
            }
            outFile << endl;
        }
        outFile << endl;
    }
    
}

void Life::checkNeighbors(int actualCellx, int actualCelly){
    
    int neighbors = 0;

    if (gameType.compare("A") == 0) {
        if (ACells[actualCellx - 1][actualCelly - 1].isAlive())
            neighbors++;
        if (ACells[actualCellx - 1][actualCelly].isAlive())
            neighbors++;
        if (ACells[actualCellx - 1][actualCelly + 1].isAlive())
            neighbors++;
        if (ACells[actualCellx][actualCelly - 1].isAlive())
            neighbors++;
        if (ACells[actualCellx][actualCelly].isAlive())
            neighbors++;
        if (ACells[actualCellx][actualCelly + 1].isAlive())
            neighbors++;
        if (ACells[actualCellx + 1][actualCelly - 1].isAlive())
            neighbors++;
        if (ACells[actualCellx + 1][actualCelly].isAlive())
            neighbors++;
        if (ACells[actualCellx + 1][actualCelly + 1].isAlive())
            neighbors++;

        if (ACells[actualCellx][actualCelly].isAlive()) {
            if (neighbors < 2 || neighbors > 3) {
                ACells[actualCellx][actualCelly].setStatus(0); //dies
            } 
            else
                ACells[actualCellx][actualCelly].setStatus(1); //lives
        } 
        else { // for them dead cells already
            if (neighbors == 3)
                ACells[actualCellx][actualCelly].setStatus(1);
            else
                ACells[actualCellx][actualCelly].setStatus(0);
        }
    } 
    else {
        if (BCells[actualCellx - 1][actualCelly].isAlive())
            neighbors++;
        if (BCells[actualCellx][actualCelly - 1].isAlive())
            neighbors++;
        if (BCells[actualCellx][actualCelly + 1].isAlive())
            neighbors++;
        if (BCells[actualCellx + 1][actualCelly].isAlive())
            neighbors++;

        if (BCells[actualCellx][actualCelly].isAlive()) {
            if (neighbors == 0 || neighbors == 2 || neighbors == 4)
                BCells[actualCellx][actualCelly].setStatus(0);
            else{
                BCells[actualCellx][actualCelly].setStatus(1);
                BCells[actualCellx][actualCelly].addAge();
            }
        } 
        else {
            if (neighbors == 1 || neighbors == 3){
                BCells[actualCellx][actualCelly].setStatus(1);
                BCells[actualCellx][actualCelly].addAge();
            }
            else
                BCells[actualCellx][actualCelly].setStatus(0);
        }
    }
    
}

void Life::initalize(){

    if (gameType.compare("A") == 0) {
        ACells.resize(columns + 2, vector<ACell > (rows + 2, false));
        for (int i = 0; i < rows + 2; i++) {
            for (int k = 0; k < columns + 2; k++) {
                ACells[i].push_back(ACell(false));
            }
        }
    } 
    else {
        BCells.resize(columns + 2, vector<BCell > (rows + 2, false));
        for (int i = 0; i < rows + 2; i++) {
            for (int k = 0; k < columns + 2; k++) {
                BCells[i].push_back(BCell(false));
            }
        }
    }
}

void Life::check() {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            checkNeighbors(i,j);
        }
    }
}

void Life::setAlive() {
    if (gameType.compare("A") == 0) {
        ACells[1][1].res();
        ACells[1][2].res();
        ACells[2][2].res();
        ACells[3][1].res();
        ACells[3][4].res();
        ACells[3][3].res();
    } else {
        BCells[1][1].res();
        BCells[1][2].res();
        BCells[2][2].res();
        BCells[3][1].res();
        BCells[3][4].res();
        BCells[3][3].res();
    }
}

