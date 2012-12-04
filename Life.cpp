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

Life::Life(ifstream inFile, ofstream outFile){
    //type of game
    //number of rows
    //number of columns
}

void Life::refresh(){
    for(int i = 1; i < rows+2; i++){
        for(int j = 1; j < columns+2; j++){
            if(ACells[i][j].getNewStatus() == 0){
                ACells[i][j].kill();
            }
            else
                ACells[i][j].res();
        }
    }
    
}

void Life::printBoard(){
    
    //when you print, all you need to find 
    //out is how many columns its going to have
    
}

void Life::checkNeighbors(int actualCellx, int actualCelly){
    
    int neighbors;

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
    
    if(ACells[actualCellx][actualCelly].isAlive()){
        if(neighbors < 2 || neighbors > 3){
            ACells[actualCellx][actualCelly].setStatus(0); //dies
        }
        else
            ACells[actualCellx][actualCelly].setStatus(1); //lives
    }
    else{ // for them dead cells already
        if(neighbors == 0)
            ACells[actualCellx][actualCelly].setStatus(1);
        else
            ACells[actualCellx][actualCelly].setStatus(0);
    }
    
}

void Life::initalize(){
    
}

void Life::check() {
    for (int i = 1; i < rows + 2; i++) {
        for (int j = 1; j < columns + 2; j++) {
            if (ACells[i][j].getNewStatus() == 0) {
                ACells[i][j].kill();
            } else
                ACells[i][j].res();
        }
    }
}

