#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode3DPhysics.h"
#include <vector>
#include "Player.H"
#include "Tunnel.H"
#include "CCam.H"
#include "CollisionManager.H"
#include "obstacle.H"
using namespace Polycode;

class HelloPolycodeApp : public EventHandler {
public:
    HelloPolycodeApp(PolycodeView *view);
    ~HelloPolycodeApp();

    void handleEvent(Event *e);
    bool Update();
    
private:
    Core *core;
    CollisionScene *cscene;
    CollisionManager *cMan;
    Player *p;
    Tunnel *t;
    Tunnel *t2;
    Tunnel *tr;
    Tunnel *tr2;
    std::vector<Obstacle *> obstacles;
    CCam *cam;

};
