#include <Polycode.h>
#include "PolycodeView.h"
#include "Polycode3DPhysics.h"

#include "Player.H"
#include "Tunnel.H"
#include "Camera.H"

using namespace Polycode;

class HelloPolycodeApp : public EventHandler {
public:
    HelloPolycodeApp(PolycodeView *view);
    ~HelloPolycodeApp();

    void handleEvent(Event *e);
    bool Update();
    
private:
    Core *core;
    Player *p;
    Tunnel *t;
    Tunnel *t2;
    CCam *cam;
};
