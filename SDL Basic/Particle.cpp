#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>


Particle::Particle()
{
	m_x = 2.0 * rand() / RAND_MAX - 1.0;
	m_y = 2.0 * rand() / RAND_MAX - 1.0;
	m_xspeed = 0.003 * (((2.0 * rand()) / RAND_MAX) - 1);
	m_yspeed = 0.004 * (((2.0 * rand()) / RAND_MAX) - 1);
}


Particle::~Particle()
{
}


void Particle::update()
{
	m_x += m_xspeed;
	m_y += m_yspeed;
}