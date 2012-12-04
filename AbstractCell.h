/* 
 * File:   AbstractCell.h
 * Author: Charles
 *
 * Created on December 1, 2012, 10:51 PM
 */

#ifndef ABSTRACTCELL_H
#define	ABSTRACTCELL_H

class AbstractCell {
public:
    AbstractCell();
    AbstractCell(const AbstractCell& orig);
    AbstractCell(bool life);
    virtual ~AbstractCell();
    bool isAlive();
    void switchLife();
    int getNewStatus();
    void kill();
    void res();
    void setStatus(int stat);
private:
    bool alive;
    int status;
};

#endif	/* ABSTRACTCELL_H */

