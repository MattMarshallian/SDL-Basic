#include "stdafx.h"
#include <stdlib.h>

// #define ponizej jest konieczny w Visual Studio
#define _USE_MATH_DEFINES
#include <cmath>
#include "Particle.h"



Particle::Particle() :m_x(0), m_y(0)
{
	m_direction = (2.0 * M_PI * rand()) / RAND_MAX;
	m_speed = (0.02 * rand()) / RAND_MAX;

	m_speed *= m_speed;
}


Particle::~Particle()
{
}


void Particle::update(int interval)
{
	m_direction += 0.0004 * interval;
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);
	m_x += xspeed * interval;
	m_y += yspeed * interval;
}