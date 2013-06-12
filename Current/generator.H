#ifndef __GENERATOR_H__
#define __TUNNEL_H__
#include "Tunnel.H"
#include "obstacle.H"
const float INITIAL_WIDTH=20.0;
const float SCALER = 2.0;
const float TUNNEL_LENGTH = 50.0;
const float TUNNEL_HEIGHT = 10.0;
class Generator{
public:
    int generated;
    CollisionScene * cscene;
    std::vector<Tunnel*> active_sections;
    std::vector<Obstacle*> active_obstacles;
    void generate()
    {
	float width = INITIAL_WIDTH - (generated * SCALER);
	float next_width = INITIAL_WIDTH - ((generated + 1) * SCALER);
	Tunnel * t = new Tunnel(width,TUNNEL_LENGTH * generated,cscene);
	Tunnel * tr = new Tunnel( TUNNEL_LENGTH * (generated+1),
				  cscene,width,next_width, TUNNEL_LENGTH);

	generated += 2;
			      
    }
    Generator()
	:generated(0),active_sections(),active_obstacles(),
	 cscene(NULL)
    {}
    Generator(CollisionScene * c)
	:generated(0),active_sections(),active_obstacles(),
	 cscene(c)
    {}
};
#endif
