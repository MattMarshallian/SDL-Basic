#pragma once
class Particle
{
	// intentionally changed access to public
public:
	double m_x;
	double m_y;
	double m_xspeed;
	double m_yspeed;


public:
	Particle();
	virtual ~Particle();
	void update();
};

