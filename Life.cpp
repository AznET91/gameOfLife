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
    checkNeighbors();
    printBoard();
    
}

void Life::printBoard(){
    
    //when you print, all you need to find 
    //out is how many columns its going to have
    
}

void Life::checkNeighbors(){
    /*Corners
     [0,0] top left
     [row-1,0] bottom left
     [0,col-1] top right
     [row-1,col-1] bottom right*/
    
    /*Edges
     [0 , 1 to (col-2)] top edge
     [1 to (row-2) , 0] left edge
     [1 to (row-2) , (col-1)] right edge
     [(row-1) , 1 - (col-2) ]*/
    
    /*Insides
     Can i just do everything else?
     Kinda like, else do this lol*/
    
    //need a way to figure out how to associate
    
}

void Life::initalize(){
    
}

