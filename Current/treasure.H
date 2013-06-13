#ifndef __treasure_H__
#define __treasure_H__

using namespace Polycode;

class Treasure{
public:
    ScenePrimitive *t;
    Vector3 pos;
    Number scale;

    Treasure(const Vector3 & pos, CollisionScene * cscene, Number scale = 1.0)
    {
        t = new ScenePrimitive(ScenePrimitive::TYPE_TORUS, 
                scale * 1.0,scale * .3 ,10.0, 10.0);
        t->setRoll(90.0);
        t->setPosition(pos);
        t->setColor(1.0,1.0,0.0,1.0);

        cscene->addCollisionChild(t);
    }

   void collectTreasure(CollisionScene * c)
   {
        c->removeEntity(t);
   }

   ScenePrimitive* getEntity()
   {
        return t;
   }

};

#endif
