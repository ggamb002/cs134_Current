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
    Tunnel(const Number &w, const Number &pos, CollisionScene *scene, const Number &nw, const Number &h)
        :position(pos),width(w)
    {
   
        Number w2 = abs(w-nw)/2.0;
        Number angle = atan(w2/h) * 180 / PI;
        Number len = h/cos(angle * PI / 180 );

        rw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,len,5,.1);
        rw->setPosition(Vector3(-1*position * .60, 2.5, w/2));
        rw->setColor(.71,.63,1.0,1.0);

        if(w > nw){
            rw->setYaw(-1*angle);
            rw->Translate(Vector3(0,0,abs(w2)/-2));
        }
        else{ 
            rw->setYaw(angle);
            rw->Translate(Vector3(0,0,abs(w2)/2));
        }

        lw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,len,5,.1);
        lw->setPosition(Vector3(-1*position * .60, 2.5, w/-2));
        lw->setColor(.51,.63,1.0,1.0);

        if( w > nw){
            lw->setYaw(angle);
            lw->Translate(Vector3(0,0,abs(w2)/2));
        }
        else{
            lw->setYaw(-1*angle);
            lw->Translate(Vector3(0,0,abs(w2)/-2));
        }
           
        Number gw;
        if(w > nw) gw = w;
        else gw = nw;

        g = new ScenePrimitive(ScenePrimitive::TYPE_BOX,h,.1,gw); 
        g->setPosition(Vector3(-1*position * .60,0,0));
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
