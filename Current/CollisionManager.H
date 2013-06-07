#ifndef __COLLISIONMANAGER_H__
#define __COLLISIONMANAGER_H__

#include "Tunnel.H"
#include "Player.H"

using namespace Polycode;

class CollisionManager{

public:

    CollisionManager(){}

    bool testCollision(CollisionScene *c, Tunnel *t, Player *p)
    {
        CollisionResult resL = 
            c->testCollision(t->getLeft(),p->getEntity());
        CollisionResult resR =
            c->testCollision(t->getRight(),p->getEntity());

        //return( resL.collided || resR.collided );
    
        if(resR.collided)
            p->moveRight();
        if(resL.collided)
            p->moveLeft();

        return( resL.collided || resR.collided );
    }
    

};

#endif
