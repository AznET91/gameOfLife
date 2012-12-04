/* 
 * File:   BCell.cpp
 * Author: Charles
 * 
 * Created on December 2, 2012, 12:47 AM
 */

#include "BCell.h"
#include "AbstractCell.h"

BCell::BCell() {
    age = 0;
}

BCell::BCell(const BCell& orig) {
}

BCell::~BCell() {
}

void BCell::addAge(){
    age += 1;
}

