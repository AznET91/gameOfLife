/* 
 * File:   BCell.h
 * Author: Charles
 *
 * Created on December 2, 2012, 12:47 AM
 */

#ifndef BCELL_H
#define	BCELL_H

#include "AbstractCell.h"

class BCell: public AbstractCell {
public:
    BCell();
    BCell(const BCell& orig);
    BCell(bool life);
    virtual ~BCell();
    void addAge();
    int getAge();
private:
    int age;

};

#endif	/* BCELL_H */

