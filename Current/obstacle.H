#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__
using namespace Polycode;

class Obstacle{
public:
    ScenePrimitive *p;
    Vector3 pos;
    Number scale;
    Obstacle(const Vector3 &pos, CollisionScene * cscene, Number scale = 1.0)
    {
	int x = rand() % 5;
	switch (x) {
	case 0:
	    p = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 
				   scale * 1.0,scale * 1.0, scale * 1.0);
	    break;
	case 1:
	    p = new ScenePrimitive(ScenePrimitive::TYPE_CONE, 
				   scale * 1.0, scale *1.0,10.0);
	    break;
	case 2:
	    p = new ScenePrimitive(ScenePrimitive::TYPE_SPHERE, 
				   scale * 1.0, 10.0,10.0);
	    break;
	case 3:
	    p = new ScenePrimitive(ScenePrimitive::TYPE_CYLINDER, 
				   scale * 1.0, scale * 1.0,10.0);
	    break;
	case 4:
	    p = new ScenePrimitive(ScenePrimitive::TYPE_TORUS, 
				   scale * 1.0, scale *.5, 10.0,10.0);
	    p->setRoll(90.0);
	    break;
	default:
	    p = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 
				   scale * 1.0,scale * 1.0, scale * 1.0);
	    break;
	}
	p->setPosition(pos);
	p->setColor(1.0,1.0,0.0,1.0);
	cscene->addCollisionChild(p);
    }


};
#endif
