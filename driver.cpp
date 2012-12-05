/* 
 * File:   main.cpp
 * Author: Charles
 *
 * Created on December 1, 2012, 9:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "ACell.h"
#include "AbstractCell.h"
#include "Life.h"
#include <fstream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    ifstream in_stream;
    ofstream out_stream;
    
    
    in_stream.open("ACellLife.in");
    out_stream.open("ACellLife.out");
    
    Life thegame(in_stream,out_stream);
    
    thegame.initalize();
    thegame.setAlive();
    for(int i = 0; i <= 20; i++){
        if(i%5 == 0)
                thegame.printBoard(out_stream);
        thegame.check();
        thegame.refresh();
    }

    
    
    in_stream.close();
    out_stream.close();
    

    
    return 0;
}

