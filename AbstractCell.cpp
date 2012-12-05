/* 
 * File:   AbstractCell.cpp
 * Author: Charles
 * 
 * Created on December 1, 2012, 10:51 PM
 */

#include "AbstractCell.h"
#include <iostream>
#include <vector>

using namespace std;

AbstractCell::AbstractCell() {
    alive = false;
    status = 0;
}

AbstractCell::AbstractCell(const AbstractCell& orig) {
}

AbstractCell::~AbstractCell() {
}

AbstractCell::AbstractCell(bool life){
    alive = life;
    status = 0;
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
int AbstractCell::getNewStatus(){
    return status;
}

void AbstractCell::kill(){
    alive = false;
}

void AbstractCell::res(){
    alive = true;
}

void AbstractCell::setStatus(int stat){
    status = stat;
}