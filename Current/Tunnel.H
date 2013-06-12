#ifndef __TUNNEL_H__
#define __TUNNEL_H__

#include <math.h>

using namespace Polycode;

class Tunnel{
    
public:
        
    ScenePrimitive *rw;
    ScenePrimitive *lw;
    ScenePrimitive *g;
    //Number scale;
    Number position;
    Number width;

    //Standard Tunnel Section
    Tunnel(const Number &w, const Number &pos,CollisionScene *scene)
        :position(pos),width(w)
    {
        rw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,50,5,.1);
        rw->setPosition(Vector3(-1*position,2.5,width/2.0));
        rw->setColor(.71,.63,1.0,1.0);

        lw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,50,5,.1);
        lw->setPosition(Vector3(-1*position,2.5,width/-2.0));
        lw->setColor(.51,.63,1.0,1.0);

        g = new ScenePrimitive(ScenePrimitive::TYPE_BOX,50,.1,width); 
        g->setPosition(Vector3(-1*position,0,0));
        g->setColor(.51,.43,1.0,1.0);

        scene->addCollisionChild(rw);
        scene->addCollisionChild(lw);
        scene->addCollisionChild(g);
    }

    //Transition Piece
    //w is left-right, h is forward-back
    //scale is of previous section, pos is end of the prev section
    //w is the width of next section, h is 10 for now, or doesnt work
    Tunnel(const Number &pos, CollisionScene *scene,const Number &w1,const Number &w2, const Number &length)
        :position(pos),width(w2)
    {
   
        Number w = w1 - w2;
        Number angle = atan(w/length) * 180 / PI;
        Number len = sqrt(length * length + w * w);
	Number d =w2/2;
        rw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,len,5,.1);
        rw->setPosition(Vector3(-1*position, 2.5, 0 ));
        rw->setColor(.71,.63,1.0,1.0);

        if(w1 > w2){
	    rw->Translate(Vector3(0,0,d));
            rw->setYaw(-1*angle);
        }
        else{ 
	    rw->Translate(Vector3(0,0,-d));
            rw->setYaw(angle);

        }

        lw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,len,5,.1);
        lw->setPosition(Vector3(-1*position, 2.5, 0));
        lw->setColor(.51,.63,1.0,1.0);

        if( w1 > w2){

	    lw->Translate(Vector3(0,0,-d));
            lw->setYaw(angle);
        }
        else{

	    lw->Translate(Vector3(0,0,d));
            lw->setYaw(-1*angle);
        }
           
        Number gw;
        if(w2 > w1) gw = w2;
        else gw = w1;

        g = new ScenePrimitive(ScenePrimitive::TYPE_BOX,length,.1,gw); 
        g->setPosition(Vector3(-1*position ,0,0));
        g->setColor(.51,.43,1.0,1.0);

        scene->addCollisionChild(rw);
        scene->addCollisionChild(lw);
        scene->addCollisionChild(g);
    }

    ~Tunnel()
    {
        delete rw,lw,g;
    }

    ScenePrimitive* getLeft()
    {
        return lw;
    }

    ScenePrimitive* getRight()
    {
        return rw;
    }

    ScenePrimitive* getGround()
    {
        return g;
    }
};

#endif 
