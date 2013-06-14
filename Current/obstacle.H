#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__
using namespace Polycode;

class Obstacle{
public:
    ScenePrimitive *p;
    Vector3 pos;
    Number scale;
    Obstacle(const Vector3 &pos, CollisionScene * cscene, Number length, float angle)
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
