#ifndef __PLAYER_H__
#define __PLAYER_H__

using namespace Polycode;

class Player{

public:
    ScenePrimitive *p;
    Number speed;
    Vector3 prevPos;

    Player(const Vector3 &pos, CollisionScene *cscene):speed(.15)
    {
        p = new ScenePrimitive(ScenePrimitive::TYPE_BOX,1.0,1.0,1.0);
        p->setPosition(pos);
        p->setColor(1.0,0.0,0.0,1.0);

        cscene->addCollisionChild(p);
    }

    ~Player()
    {
        delete p;
    }

    void moveLeft()
    {
        p->Translate(Vector3(0,0,speed));
    } 

    void moveRight()
    {
        p->Translate(Vector3(0,0,-1*speed));
    }

    void moveForward()
    {
        p->Translate(Vector3(-1*speed,0,0));
    }

    void update()
    {
        this->moveForward();
    }

    void undoMove()
    {
        p->setPosition(prevPos);
    }
    
    void setColor(Number r, Number g, Number b, Number a)
    {
        p->setColor(r,g,b,a);
    }

    ScenePrimitive* getEntity()
    {
        return p;
    }

};

#endif
