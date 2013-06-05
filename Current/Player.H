#ifndef __PLAYER_H__
#define __PLAYER_H__

using namespace Polycode;

class Player{

public:
    ScenePrimitive *p;
    Number speed;

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

};

#endif
