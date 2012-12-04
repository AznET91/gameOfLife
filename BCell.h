/* 
 * File:   BCell.h
 * Author: Charles
 *
 * Created on December 2, 2012, 12:47 AM
 */

#ifndef BCELL_H
#define	BCELL_H

class BCell {
public:
    BCell();
    BCell(const BCell& orig);
    virtual ~BCell();
    void addAge();
private:
    int age;

};

#endif	/* BCELL_H */

