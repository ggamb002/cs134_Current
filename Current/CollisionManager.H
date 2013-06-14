#ifndef __COLLISIONMANAGER_H__
#define __COLLISIONMANAGER_H__

#include "Tunnel.H"
#include "Player.H"
#include "treasure.H"

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
                p->moveRight(.6);
            else
                p->moveLeft(.6);  
        }

        if(resL.collided)
        {
            if((*p).p->getPosition().z < t->getRight()->getPosition().z)
                p->moveLeft(.6);
            else
                p->moveRight(.6 );
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
    bool obstacleCollision(Obstacle * o, Player *p, CollisionScene * c)
    {
	CollisionResult r = 
            c->testCollision(o->p,p->getEntity());
	if(r.collided){
	    p->HP-=1;
	    return true;
	}
	return false;
    } 
    Number getSpeed(CollisionScene *c, Tunnel *t)
    {
        if(c==NULL || t==NULL) return -1;
        CollisionResult resG = 
            c->testCollision(t->getGround(),speedCheck);
        if(resG.collided)
        {
            return (*t).speedFactor;
        }
        else
            return -1;
    }

    void moveForward(Number sp)
    {
        speedCheck->Translate(Vector3(-1*sp,0,0));
    }

    bool checkTreasure(CollisionScene *c, Player *p, Treasure *t)
    {
        if(p == NULL || t == NULL) return false;

        CollisionResult result = c->testCollision(p->getEntity(),t->getEntity());

        if(result.collided)
            t->collectTreasure(c);

        return(result.collided);
    }

};

#endif
