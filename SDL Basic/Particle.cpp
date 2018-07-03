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
	const double speed = 0.01;
	m_x += speed;
	m_y += speed;
}