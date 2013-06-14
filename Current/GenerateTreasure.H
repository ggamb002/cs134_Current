#ifndef __GENERATETREASURE_H__
#define __GENERATETREASURE_H__

using namespace Polycode;

class GenerateTreasure{
public:
    GenerateTreasure(const Vector3 & pos, const Number & length, const Number & width)
    {
        
    }

    int randInt(int min, int max)
    {
        return rand() % max + min;
    }

};

#endif
