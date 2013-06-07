#ifndef __TUNNEL_H__
#define __TUNNEL_H__

using namespace Polycode;

class Tunnel{
    
public:
        
    ScenePrimitive *rw;
    ScenePrimitive *lw;
    ScenePrimitive *g;
    Number scale;
    Number position;

    Tunnel(const Number &sc, const Number &pos,CollisionScene *scene)
        :scale(sc),position(pos)
    {
        rw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,50,5,5);
        rw->setPosition(Vector3(-1*position,2.5,5*sc));
        rw->setColor(.71,.63,1.0,1.0);

        lw = new ScenePrimitive(ScenePrimitive::TYPE_BOX,50,5,5);
        lw->setPosition(Vector3(-1*position,2.5,-5*sc));
        lw->setColor(.51,.63,1.0,1.0);

        g = new ScenePrimitive(ScenePrimitive::TYPE_BOX,50,.1,10*sc); 
        g->setPosition(Vector3(-1*position,0,0));
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
