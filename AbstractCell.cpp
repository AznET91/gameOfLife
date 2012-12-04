/* 
 * File:   AbstractCell.cpp
 * Author: Charles
 * 
 * Created on December 1, 2012, 10:51 PM
 */

#include "AbstractCell.h"
#include <iostream>

using namespace std;

AbstractCell::AbstractCell() {
    alive = false;
}

AbstractCell::AbstractCell(const AbstractCell& orig) {
}

AbstractCell::~AbstractCell() {
}

AbstractCell::AbstractCell(bool life){
    alive = life;
}

bool AbstractCell::isAlive(){
    return alive;
}

void AbstractCell::switchLife(){
    if(alive)
        alive = false;
    else
        alive = true;
}