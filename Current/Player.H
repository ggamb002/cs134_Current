#ifndef __PLAYER_H__
#define __PLAYER_H__

using namespace Polycode;

class Player{

public:
    ScenePrimitive *p;
    Number speed;
    Number bound;
    Number homeslice;
    bool l;
    bool r;
    bool u;
    bool d;
    bool f;
    bool b;
    Player(const Vector3 &pos, CollisionScene *cscene)
	:speed(.25),l(false),r(false),u(false), d(false),f(false),b(false),
	 homeslice(pos.z)
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
    void moveLeft(Number sp)
    {
        p->Translate(Vector3(0,0,sp));
    }

    void moveRight()
    {
        p->Translate(Vector3(0,0,-1*speed));
    }
    void moveDown()
    {
        p->Translate(Vector3(0,-1*speed,0));
    }
    void moveUp()
    {
	p->Translate(Vector3(0,1*speed,0));
    }
    void moveRight(Number sp)
    {
        p->Translate(Vector3(0,0,-1*sp));
    }

    void moveForward()
    {
        p->Translate(Vector3(-1*speed,0,0));
	homeslice+=-1*speed;
    }

    void moveForward(Number sp)
    {
        p->Translate(Vector3(-1*sp,0,0));
    }

    void boost()
    {
	
    }
    void brake()
    {

    }
    void move_toward_center()
    {

    }
    void update()
    {
        this->moveForward();
	if(l)moveLeft();
	if(r)moveRight();
	if(d)moveDown();
	if(u)moveUp();
	if(f)boost();
	if(b)brake();
	if(!f && !b)move_toward_center();
	
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
