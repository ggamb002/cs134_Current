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
    gen = new Generator(cscene);
    for(int i = 0; i < 6; ++i)
	gen->generate();

    Obstacle * o = new Obstacle(Vector3(-25.0, 5.0,-1.0),cscene);
    Obstacle * o2 = new Obstacle(Vector3(-40.0, 2.5,1.0),cscene);
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
    //    for(int i = 0; gen->active_sections.size(); ++i)
    //	cMan->testCollision(cscene,gen->active_sections[i],p);
    return core->updateAndRender();

}
