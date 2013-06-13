#ifndef __GENERATOR_H__
//#define __TUNNEL_H__
#include "Tunnel.H"
#include "obstacle.H"
#include <iostream>
const float INITIAL_WIDTH=20.0;
const float W_SCALE = 1.5;
const float H_SCALE = .2;
const float TUNNEL_LENGTH = 50.0;
const float TUNNEL_HEIGHT = 10.0;


class Generator{
public:
    int generated;
    //
    int random;
    float prevWidth;
    //
    CollisionScene * cscene;
    std::vector<Tunnel*> active_sections;
    std::vector<Obstacle*> active_obstacles;


    void generate()
    {
	float width = INITIAL_WIDTH - (generated * W_SCALE);
	float height = TUNNEL_HEIGHT - (generated * H_SCALE);
	float next_width = INITIAL_WIDTH - ((generated + 1) * W_SCALE);
	float next_height = TUNNEL_HEIGHT - ((generated + 1) * H_SCALE); 
	float pos = TUNNEL_LENGTH * generated;
	float next_pos = TUNNEL_LENGTH * (generated+1);
	Tunnel * t = new Tunnel(width,height,pos,cscene);
	Tunnel * tr = new Tunnel( next_height,next_pos,
				  cscene,width,next_width, TUNNEL_LENGTH);
	active_sections.push_back(t);
	active_sections.push_back(tr);
	generated += 2;
	std::cout<<"G:"<<generated<<std::endl;
    }

    void generate(int i)
    {
        //float width = INITIAL_WIDTH - (random * W_SCALE);
        float width = prevWidth;
        float height = TUNNEL_HEIGHT - (generated * H_SCALE);
        float next_width = INITIAL_WIDTH - (random /*0* W_SCALE*/);
        float next_height = TUNNEL_HEIGHT - ((generated + 1)*H_SCALE);
        float pos = TUNNEL_LENGTH * generated;
        float next_pos = TUNNEL_LENGTH * (generated + 1);
        Tunnel * t= new Tunnel(width, height, pos, cscene);
        Tunnel *tr = new Tunnel(next_height, next_pos,
                                cscene,width,next_width,TUNNEL_LENGTH);
        active_sections.push_back(t);
        active_sections.push_back(tr);
        generated += 2;
        random = randInt(1,10);
        prevWidth = next_width;
        printf("Rand = %i\n",random);
    }
    Generator()
	:generated(0),cscene(NULL)
    {
	active_sections = std::vector<Tunnel*>();
	active_obstacles = std::vector<Obstacle*>();
    }
    Generator(CollisionScene * c)
	:generated(0),cscene(c),random(2),prevWidth(5)
    {
	active_sections = std::vector<Tunnel*>();
	active_obstacles = std::vector<Obstacle*>();
    }


    int randInt(int min, int max)
    {
        return rand() % max + min;
    }
};

#endif
