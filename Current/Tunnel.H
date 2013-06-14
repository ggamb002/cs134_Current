#ifndef __TUNNEL_H__
#define __TUNNEL_H__

#include <math.h>

using namespace Polycode;

class Tunnel{
    
public:
        
    ScenePrimitive *rw;
    ScenePrimitive *lw;
    ScenePrimitive *g;
    Number position;
    Number width;
    Number speedFactor;

    //Standard Tunnel Section
    Tunnel(const Number &w, const Number &h, const Number &pos,CollisionScene *scene)
        :position(pos),width(w)
    {
        //Right Wall
        rw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,50,h,.1);
        rw->setPosition(Vector3(-1*position,h/2,width/2.0));

        //Left Wall
        lw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,50,h,.1);
        lw->setPosition(Vector3(-1*position,h/2,width/-2.0));

        //Ground
        g = new ScenePrimitive(ScenePrimitive::TYPE_BOX,50,.1,width); 
        g->setPosition(Vector3(-1*position,0,0));

        //Add Objects to the scene
        lw->loadTexture("Resources/green_texture.png");
        rw->loadTexture("Resources/green_texture.png");
        g->loadTexture("Resources/pink_texture.png");

        scene->addCollisionChild(rw);
        scene->addCollisionChild(lw);
        scene->addCollisionChild(g);
    
        speedFactor = -.11*(w)+1;
        if(speedFactor < 0) speedFactor *= -1;
        printf("Speed is %f",speedFactor);
    }

    //Transition Piece
    //w is left-right, h is forward-back
    //scale is of previous section, pos is end of the prev section
    //w is the width of next section, h is 10 for now, or doesnt work
    Tunnel(const Number & h, const Number &pos, CollisionScene *scene,const Number &w1,const Number &w2, const Number &length)
        :position(pos),width(w2)
    {
        //Math stuff
        Number w = (w1 - w2)/2;
        Number angle = atan(w/length) * 180 / PI;
        Number len = sqrt(length * length + w * w);
	//Number d = w2/2;
        //Right wall
        rw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,len,h,.1);
        rw->setPosition(Vector3(-1*position, h/2, 0 ));
        //Figure out which way to angle the wall
        if(w1 > w2){
	    rw->Translate(Vector3(0,0,w1/2 + w/-2));
            rw->setYaw(-1*angle);
        }
        else{ 
	    rw->Translate(Vector3(0,0,-1*w1/2 +w/2));
            rw->setYaw(angle);
        }

        //Left wall
        lw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,len,h,.1);
        lw->setPosition(Vector3(-1*position, h/2, 0));
        //Figure out which way to angle the wall
        if( w1 > w2){
	    lw->Translate(Vector3(0,0,-1*w1/2 + w/2));
            lw->setYaw(angle);
        }
        else{

	    lw->Translate(Vector3(0,0,w1/2 + w/-2));
            lw->setYaw(-1*angle);
        }
        //Decide how wide to make the ground plane   
        Number gw;
        if(w2 > w1 && w <= 0) gw = w2;
        else gw = w1;

        //Create the ground
        g = new ScenePrimitive(ScenePrimitive::TYPE_BOX,length,.1,gw); 
        g->setPosition(Vector3(-1*position ,0,0));

        //Add to the scene
        lw->loadTexture("Resources/green_texture.png");
        rw->loadTexture("Resources/green_texture.png");
        g->loadTexture("Resources/pink_texture.png");

        scene->addCollisionChild(rw);
        scene->addCollisionChild(lw);
        scene->addCollisionChild(g);

        speedFactor = -.11*((w1+w2)/2)+1;
        if(speedFactor < 0) speedFactor *= -1;
        printf("Speed is %f",speedFactor);
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
