#include "HelloPolycodeApp.h"

HelloPolycodeApp::HelloPolycodeApp(PolycodeView *view) : EventHandler() {
    
    updateSpeed = .15;
    point = 0;
    core = new SDLCore(view, 640,480,false,false,0,0,90);	  

    CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
    CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

    Screen *screen = new Screen();
    label = new ScreenLabel("HP:XXX", 32);
    hud = new ScreenLabel("Score:0",32);
    hud->setPosition(150,0);
    screen->addChild(label);
    screen->addChild(hud);
    cscene = new CollisionScene();

    p = new Player(Vector3(0.0,2.0,0.0),cscene);

    gen = new Generator(cscene);
    for(int i = 0; i < 10; ++i)
	gen->randGenerate();
    gen->addObstacles();

    gen->addEnemies();

    gen->generateTreasure();


    cam = new CCam(cscene->getActiveCamera(),Vector3(0.0,2.0,0.0));
    cMan = new CollisionManager(cscene);

    core->getInput()->addEventListener(this, InputEvent::EVENT_KEYDOWN);
    core->getInput()->addEventListener(this, InputEvent::EVENT_KEYUP);
    srand(time(NULL));
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
			    p->l = true;
                            break;
			case KEY_RIGHT:
			    p->r = true;
                            break;
			case KEY_UP:
			    p->u = true;
			    break;
			case KEY_DOWN:
			    p->d = true;
			    break;
			case KEY_SPACE:
			    p->f = true;
			    break;
			case KEY_LSHIFT:
			    p->b = true;
			    break;
			}
		    break;
            
		case InputEvent::EVENT_KEYUP:
		    switch(inputEvent->keyCode())
			{
			case KEY_LEFT:
			    p->l = false;
                            break;
			case KEY_RIGHT:
			    p->r = false;
                            break;
			case KEY_UP:
			    p->u = false;
			    break;
			case KEY_DOWN:
			    p->d = false;
			    break;
			case KEY_SPACE:
			    p->f = false;
			    break;
			case KEY_LSHIFT:
			    p->b = false;
			    break;
			}
		    break;
		}
	}
}

bool HelloPolycodeApp::Update() {

    p->update();
    cam->moveForward();

    for(int i = 0; i<gen->active_sections.size(); ++i)
    	cMan->testCollision(cscene,gen->active_sections[i],p);

    for(int i = 0; i < gen->active_enemies.size();++i){
	gen->active_enemies[i]->Update();
    }

    

    for(int i = 0; i <gen->active_obstacles.size(); ++i)
	if(cMan->obstacleCollision(gen->active_obstacles[i],p,cscene)){
	    p->moveForward(2.5);
	    cam->moveForward(2.5);
	    cMan->moveForward(2.5);
	    std::string s = "HP:";
	    for(int i = 0; i < p->HP;++i)
		s+="X";
	    label->setText(s);

	}

    for(int i = 0; i<gen->active_sections.size(); ++i){
        updateSpeed = cMan->getSpeed(cscene,gen->active_sections[i]);
        if(updateSpeed < 0)
            continue;
        else
            break;
    }
    
    for(int i = 0; i < gen->active_coins.size(); ++i){
        bool scored = cMan->checkTreasure(cscene,p,gen->active_coins[i]); 
        if(scored){
            std::stringstream ss;
            point += 10;
            ss << point;
            std::string result;
            ss >> result;
            std::string s = "Score " + result;
            hud->setText(s);
        }
    }

    p->moveForward(updateSpeed);
    cam->moveForward(updateSpeed);
    cMan->moveForward(updateSpeed);
    return core->updateAndRender();

}
