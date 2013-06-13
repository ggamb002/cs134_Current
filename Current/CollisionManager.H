#ifndef __COLLISIONMANAGER_H__
#define __COLLISIONMANAGER_H__

#include "Tunnel.H"
#include "Player.H"

using namespace Polycode;

class CollisionManager{

public:

    ScenePrimitive *speedCheck;

    CollisionManager(CollisionScene *c)
    {
        speedCheck = new ScenePrimitive(ScenePrimitive::TYPE_BOX,10.0,10.0,10.0);
        speedCheck->setPosition(-100.0,0.0,0.0);
        speedCheck->setColor(0.0,0.0,0.0,0.0);
        c->addCollisionChild(speedCheck);
    }

    bool testCollision(CollisionScene *c, Tunnel *t, Player *p)
    {
	if(t == NULL || c==NULL ||p==NULL) return false;
        CollisionResult resL = 
            c->testCollision(t->getLeft(),p->getEntity());
        CollisionResult resR =
            c->testCollision(t->getRight(),p->getEntity());
	CollisionResult resG =
            c->testCollision(t->getGround(),p->getEntity());
//        if(resR.collided)
//            p->moveRight();
//        if(resL.collided)
//            p->moveLeft();
        if(resR.collided)
        {
            if((*p).p->getPosition().z > t->getLeft()->getPosition().z)
                p->moveRight();
            else
                p->moveLeft();  
        }
        if(resL.collided)
        {
            if((*p).p->getPosition().z < t->getRight()->getPosition().z)
                p->moveLeft();
            else
                p->moveRight();
        }
	if(resG.collided)
	{
	    p->moveUp();	
	}
	if(p->p->getPosition().y > TUNNEL_HEIGHT)
	{
	    p->moveDown();
	}
        return( resL.collided || resR.collided ||resG.collided);
    }

    Number getSpeed(CollisionScene *c, Tunnel *t)
    {
        if(c==NULL || t==NULL) return -1;
        CollisionResult resG = 
            c->testCollision(t->getGround(),speedCheck);
        if(resG.collided)
        {
            printf("Man %f\n",(*t).speedFactor);
            return (*t).speedFactor;
        }
        else
            return -1;
    }

    void moveForward(Number sp)
    {
        speedCheck->Translate(Vector3(-1*sp,0,0));
    }

};

#endif
