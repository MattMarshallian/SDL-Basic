#pragma once
class Particle
{
	// intentionally changed access to public
public:
	double m_x;
	double m_y;
	double m_direction;
	double m_speed;


public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

