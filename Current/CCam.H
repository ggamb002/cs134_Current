#ifndef __CCAM_H__
#define __CCAM_H__

using namespace Polycode;

class CCam{

public:
    Camera *cam;
    ScenePrimitive *tar;
    Number speed;

    CCam(Camera *c, const Vector3 &pos):cam(c),speed(.15)
    {
        tar = new ScenePrimitive(ScenePrimitive::TYPE_BOX,1.0,1.0,1.0);
        tar->setPosition(pos);
        
        cam->setPosition(pos + Vector3(20,5,0));
        cam->lookAt(pos);
    }

    void moveForward()
    {
        tar->Translate(Vector3(-1*speed,0,0));
        cam->Translate(Vector3(-1*speed,0,0));
    }


};
#endif
