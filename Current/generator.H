#ifndef __GENERATOR_H__
#define __GENERATOR_H__

#include "Tunnel.H"
#include "obstacle.H"
#include "treasure.H"
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
    std::vector<Treasure*> active_coins;


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

    void addObstacles()
    {
	for(int i = 2; i < active_sections.size();++i){
	    Tunnel * t = active_sections[i];
	    float r1 = (float)rand()/(float)RAND_MAX;
	    float r2 = -.5 + (float)rand()/(float)RAND_MAX;
	    int r3  = rand()%2; 
	    float xpos = -TUNNEL_LENGTH * r1 - t->position;
	    std::cout<<"XPOS:"<<xpos<<std::endl;
	    float angle = 0;
	    float length;
	    Vector3 v;
	    if(r3 == 0){
		float zpos = t->width * r2 ;
		v = Vector3(xpos,0,zpos);
		length = TUNNEL_HEIGHT;
	    }
	    else{
		float ypos = TUNNEL_HEIGHT * r2;
		v = Vector3(xpos,ypos,0);
		angle = 90.0;
		length = t->width;
	    }
	    Obstacle * o = new Obstacle(v,cscene,length,angle);
	    active_obstacles.push_back(o);
	}
    }

    void generateTreasure()
    {
        for(int i = 2; i < active_sections.size(); i++){
            Tunnel * t = active_sections[i];
            float r1 = (float)rand()/(float)RAND_MAX;
            float r2 = .5 + (float)rand()/(float)RAND_MAX;
            int r3 = rand()%2;
            float xpos = -TUNNEL_LENGTH * r1 - t->position;
            
            Vector3 v;
            if(r3 == 0){
                float ypos = (float)randInt(1,8);
                float zpos = (float)randInt(0,t->width/2) * -1;
                v = Vector3(xpos,ypos,zpos);
            }
            else{
                float ypos = (float)randInt(1,8);
                float zpos = (float)randInt(0, t->width/2);
                v = Vector3(xpos,ypos,zpos);
            }
            Treasure *  tr = new Treasure(v,cscene);
            active_coins.push_back(tr);
        }
    }

    void randGenerate()
    {
        //float width = INITIAL_WIDTH - (random * W_SCALE);
        float width = prevWidth;
        //float height = TUNNEL_HEIGHT - (generated * H_SCALE);
        
        float next_width;
        if(generated == 0)
            next_width = INITIAL_WIDTH - (random /*0* W_SCALE*/);
        else
            next_width = random;

        //float next_height = TUNNEL_HEIGHT - ((generated + 1)*H_SCALE);

        float pos = TUNNEL_LENGTH * generated;
        float next_pos = TUNNEL_LENGTH * (generated + 1);

        Tunnel * t = new Tunnel(width, TUNNEL_HEIGHT, pos, cscene);
        Tunnel * tr = new Tunnel(TUNNEL_HEIGHT, next_pos,
                                cscene,width,next_width,TUNNEL_LENGTH);

        active_sections.push_back(t);
        active_sections.push_back(tr);
        generated += 2;
        random = randInt(10,20);
        prevWidth = next_width;
        printf("Rand = %i\n",random);
    }
    Generator()
	:generated(0),cscene(NULL)
    {
	active_sections = std::vector<Tunnel*>();
	active_obstacles = std::vector<Obstacle*>();
        active_coins  = std::vector<Treasure*>();
    }

    Generator(CollisionScene * c)
	:generated(0),cscene(c),random(2),prevWidth(5)
    {
	active_sections = std::vector<Tunnel*>();
	active_obstacles = std::vector<Obstacle*>();
        active_coins = std::vector<Treasure*>();
    }


    int randInt(int min, int max)
    {
        return rand() % max + min;
    }
};

#endif
