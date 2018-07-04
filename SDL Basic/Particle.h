#pragma once
class Particle
{
	// intentionally changed access to public
public:
	double m_x = 0;
	double m_y = 0;


public:
	Particle();
	virtual ~Particle();
	void update(int interval);

private:
	double m_direction;
	double m_speed;
	void init();
};

