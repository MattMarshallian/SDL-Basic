#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>


Particle::Particle()
{
	m_x = 2.0 * rand() / RAND_MAX - 1.0;
	m_y = 2.0 * rand() / RAND_MAX - 1.0;
}


Particle::~Particle()
{
}


void Particle::update()
{
	const double xspeed = 0.003 * (((2.0 * rand()) / RAND_MAX) - 1);
	const double yspeed = 0.004 * (((2.0 * rand()) / RAND_MAX) - 1);
	m_x += xspeed;
	m_y += yspeed;
}