#ifndef __ENEMY_H__
#define __ENEMY_H__
using namespace Polycode;

class Enemy{
public:
    ScenePrimitive *p;
    Vector3 pos;
    Enemy(const Vector3 &pos, CollisionScene * cscene)
	:pos(pos)
    {

	p = new ScenePrimitive(ScenePrimitive::TYPE_CYLINDER,length, 
			       1.0,10.0);
	p->setPosition(pos);
	p->setPitch(angle);
	p->setColor(1.0,1.0,0.0,1.0);
	cscene->addCollisionChild(p);
    }

};
#endif
