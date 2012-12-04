/* 
 * File:   ACell.h
 * Author: Charles
 *
 * Created on December 1, 2012, 11:58 PM
 */

#ifndef ACELL_H
#define	ACELL_H

#include "AbstractCell.h"

class ACell : public AbstractCell {
public:
    ACell();
    ACell(const ACell& orig);
    virtual ~ACell();
    ACell(bool life);
private:

};

#endif	/* ACELL_H */

