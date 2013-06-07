#include "HelloPolycodeApp.h"

HelloPolycodeApp::HelloPolycodeApp(PolycodeView *view) : EventHandler() {

    core = new SDLCore(view, 640,480,false,false,0,0,90);	  

    CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

    Screen *screen = new Screen();
    ScreenLabel *label = new ScreenLabel("Hello, ZACH!", 32);
    screen->addChild(label);

    cscene = new CollisionScene();

    p = new Player(Vector3(24.0,2.0,0.0),cscene);

    t2 = new Tunnel(15,0,cscene);
    tr = new Tunnel(15,50,cscene,10,10);
    t = new Tunnel(10,60 ,cscene);
    tr2 = new Tunnel(10,110,cscene,15,10);

    cam = new CCam(cscene->getActiveCamera(),Vector3(24.0,2.0,0.0));

    cMan = new CollisionManager();

    core->getInput()->addEventListener(this, InputEvent::EVENT_KEYDOWN);
    core->getInput()->addEventListener(this, InputEvent::EVENT_KEYUP);
}


HelloPolycodeApp::~HelloPolycodeApp() {
    delete p;
}

void HelloPolycodeApp::handleEvent(Event *e)
{
    if(e->getDispatcher() == core->getInput())
    {
        InputEvent * inputEvent = (InputEvent*)e;

        switch(e->getEventCode())
        {
            case InputEvent::EVENT_KEYDOWN:
                switch(inputEvent->keyCode())
                {
                    case KEY_LEFT:
                        p->moveLeft();
                        break;
                    case KEY_RIGHT:
                        p->moveRight();
                        break;
                }
                break;
            
            case InputEvent::EVENT_KEYUP:
                switch(inputEvent->keyCode())
                {
                    case KEY_LEFT:
                        break;
                    case KEY_RIGHT:
                        break;
                }
                break;
        }
    }
}

bool HelloPolycodeApp::Update() {

    p->update();
    cam->moveForward();

    if(cMan->testCollision(cscene,t,p)){
        p->setColor(1.0,1.0,0.0,0.5);
    }
    else{
        p->setColor(0.0,1.0,1.0,0.5);
    }

    if(cMan->testCollision(cscene,t2,p)){
        p->setColor(1.0,1.0,0.0,0.5);
    }
    else{
        p->setColor(0.0,1.0,1.0,0.5);
    }


//    if(cMan->testCollision(cscene,tr,p)){
//        p->setColor(1.0,1.0,0.0,0.5);
//    }
//    else{
//        p->setColor(0.0,1.0,1.0,0.5);
//    }
    return core->updateAndRender();

}
