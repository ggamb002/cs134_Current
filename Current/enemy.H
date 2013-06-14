#ifndef __ENEMY_H__
#define __ENEMY_H__
using namespace Polycode;
const float INCREMENT=.1;
class Enemy{
public:
    ScenePrimitive *p;
    Vector3 i_pos;
    Vector3 pos;
    Number goal;

    bool is_vertical;
    bool toward;
    Enemy(const Vector3 &pos, CollisionScene * cscene, Number goal, 
	  bool is_vertical = true)
	:pos(pos),i_pos(pos),goal(goal),is_vertical(is_vertical),toward(true)
    {

	p = new ScenePrimitive(ScenePrimitive::TYPE_CONE,1.0, 
			       1.0,10.0);
	p->setPosition(pos);
	p->setColor(0.0,0.0,1.0,1.0);
	cscene->addCollisionChild(p);
    }
    void Update()
    {
	Vector3 v;
	if(is_vertical){
	    if(i_pos.y > goal){
		v = Vector3(0,-INCREMENT,0);
	    }
	    else{
		v = Vector3(0,INCREMENT,0);
	    }
	    if(abs(p->getPosition().y-goal)<INCREMENT){
		Number tmp = goal;
		goal = i_pos.y;
		i_pos.y = tmp;
		
	    }
	}
	else{
	    if(i_pos.z > goal){
		v = Vector3(0,0,-INCREMENT);
	    }
	    else{
		v = Vector3(0,0,INCREMENT);
	    }
	    if(abs(p->getPosition().z-goal)<INCREMENT){
		Number tmp = goal;
		goal = i_pos.z;
		i_pos.z = tmp;
		
	    }
	}
	p->Translate(v);
	
    }

};
#endif
