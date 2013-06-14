#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__
using namespace Polycode;

class Obstacle{
public:
    ScenePrimitive *p;
    Vector3 pos;
    Obstacle(const Vector3 &pos, CollisionScene * cscene, Number length, float angle)
	:pos(pos)
    {

	p = new ScenePrimitive(ScenePrimitive::TYPE_CYLINDER,length, 
			       1.0,10.0);
       
	p->setPosition(pos);
	if(angle == 0)p->Translate(0,length/2,.5);
	else p->Translate(0,.5,0);
	p->setPitch(angle);
	p->setColor(1.0,1.0,0.0,1.0);
	cscene->addCollisionChild(p);
    }

};
#endif
