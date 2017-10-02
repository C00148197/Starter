
#include "Enemy.h"
using namespace std;

Enemy::Enemy() {}
Enemy::~Enemy() {} //deconstructor

void Enemy::initialise(int i)
{
	m_texture.loadFromFile("ai.png"); //reset relevant vars
	m_image.setTexture(m_texture); //apply texture to image
	m_position = sf::Vector2f(436 + (128), 700); //offset each enemy (formerly i* 86) CONST
	m_isAlive = false; //for test only


	m_image.setScale(0.3f, 0.3f);

	if (i == 0)
	{
		m_isAlive = true;
	}
	currentWaypoint = 0; //head to first waypoint at first.
	int hund = 100;
	m_waypoint.reserve(5);
	cout << std::to_string(m_waypoint.size()) << endl;


	random_device rando; //rng 
	mt19937 gen(rando());
	uniform_int_distribution<> dist(0, 1);
	uniform_int_distribution<> dist2(0, 2);
	rPath = dist(gen); //select 
	m_image.setOrigin(16, 16);
	m_waypoint.clear(); //if game restarts we want a fresh vector


	//					//if level is one.....#######
	//enemyType = dist2(gen);

	//if (enemyType == 0)
	//{
	//	//default enemy
	//}
	//else if (enemyType == 1)
	//{
	//	m_health = 3.0; //tank enemy
	//					//different sprite
	//}
	//else if (enemyType == 2)
	//{
	//	//fast enemy
	//	//different sprite
	//	m_velocity.x = 2;
	//	m_velocity.y = 2;
	//}

	//for (size_t i = 0; i < maxWaypoint; i++) //set up waypoint size
	//{
	//	m_waypoint.push_back(m_position);
	//}
	//if (rPath == 1)
	//{
	//	m_waypoint.at(0) = sf::Vector2f(m_position.x, 270);
	//	m_waypoint.at(1) = sf::Vector2f(330, 330);
	//	m_waypoint.at(2) = sf::Vector2f(360, 450);
	//	m_waypoint.at(3) = sf::Vector2f(335, 750);
	//	m_waypoint.at(4) = sf::Vector2f(350, 1000);
	//}
	//else
	//{
	//	m_waypoint.at(0) = sf::Vector2f(m_position.x, 270);
	//	m_waypoint.at(1) = sf::Vector2f(330, 430);
	//	m_waypoint.at(2) = sf::Vector2f(760, 550);
	//	m_waypoint.at(3) = sf::Vector2f(735, 750);
	//	m_waypoint.at(4) = sf::Vector2f(750, 1000);
	//}

}

//if enemies are alive, they should be doing stuff
void Enemy::update(sf::RenderWindow& window, float i)
{

	if (m_position.y > 1180)
	{
		m_position.y = 0;
	}
	else if (m_position.y < -100)
	{
		m_position.y = 1080;
	}
	if (m_position.x > 2020)
	{
		m_position.x = 0;
	}
	else if (m_position.x < -100)
	{
		m_position.x = 1920;
	}


	//atan stuff goes in here

	m_velocity.y = -1;

	m_position += m_velocity;

	//for (int i2 = 0; i2 < m_velocity.x; i2++) //while we havent moved our entire movement value
	//{
	//	m_position.x++; //move some more
	//	//if (m_position.x >= m_waypoint.at(currentWaypoint).x) //if we're already at the goal
	//	//{
	//	//	break;
	//	//}
	//}


	m_image.setPosition(m_position); //set position of sprite

	//if (m_health < 0.1)
	//{
	//	m_isAlive = false;
	//}
	//else if (m_health <= 0.5) //debug  value
	//{

	//	window.draw(m_image); //draw texture with  
	//}
	//else
	//{
		window.draw(m_image);
//	}



	//if (m_isAlive == true)
	//{
	//	if (i == 0)
	//	{
	//		cout << "XPOS: " + std::to_string(m_position.x) << endl;
	//		cout << "XWAY: " + std::to_string(m_waypoint.at(currentWaypoint).x) << endl;
	//	}


	//	if (m_position.x < m_waypoint.at(currentWaypoint).x) //enemies path towards their current waypoint.
	//	{
	//		if (enemyType != 2)
	//		{
	//			m_velocity.x = 1;
	//		}
	//		else
	//		{
	//			m_velocity.x = 2;
	//		}
	//		for (int i2 = 0; i2 < m_velocity.x; i2++) //while we havent moved our entire movement value
	//		{
	//			m_position.x++; //move some more
	//			if (m_position.x >= m_waypoint.at(currentWaypoint).x) //if we're already at the goal
	//			{
	//				break;
	//			}
	//		}

	//	}

	//	else if (m_position.x > m_waypoint.at(currentWaypoint).x) //enemies path towards their current waypoint.
	//	{
	//		if (enemyType != 2)
	//		{
	//			m_velocity.x = -1;
	//		}
	//		else
	//		{
	//			m_velocity.x = -2;
	//		}
	//		for (int i2 = 0; i2 < (m_velocity.x *-1); i2++) //while we havent moved our entire movement value
	//		{
	//			m_position.x--; //move some more
	//			if (m_position.x >= m_waypoint.at(currentWaypoint).x) //if we're already at the goal
	//			{
	//				break;
	//			}
	//		}

	//	}

	//	if (m_position.y < m_waypoint.at(currentWaypoint).y) //enemies path towards their current waypoint.
	//	{
	//		if (enemyType != 2)
	//		{
	//			m_velocity.y = 1;
	//		}
	//		else
	//		{
	//			m_velocity.y = 2;
	//		}
	//		for (int i2 = 0; i2 < m_velocity.y; i2++) //while we havent moved our entire movement value
	//		{
	//			m_position.y++; //move some more
	//			if (m_position.y >= m_waypoint.at(currentWaypoint).y) //if we're already at the goal
	//			{
	//				break;
	//			}
	//		}

	//	}
	//	else if (m_position.y > m_waypoint.at(currentWaypoint).y) //enemies path towards their current waypoint.
	//	{
	//		if (enemyType != 2)
	//		{
	//			m_velocity.y = -1;
	//		}
	//		else
	//		{
	//			m_velocity.y = -2;
	//		}
	//		for (int i2 = 0; i2 < (m_velocity.y *-1); i2++) //while we havent moved our entire movement value
	//		{
	//			m_position.y--; //move some more
	//			if (m_position.y >= m_waypoint.at(currentWaypoint).y) //if we're already at the goal
	//			{
	//				break;
	//			}
	//		}
	//	}

	//	if (m_position == m_waypoint.at(currentWaypoint)) //if we have reached the waypoint
	//	{
	//		if (currentWaypoint < maxWaypoint - 1) //if there's another waypoint after the one we're on top of
	//		{
	//			currentWaypoint++;
	//		}
	//	}

	

	//}
}


float Enemy::getHealth()
{
	return m_health;
}

bool Enemy::getAlive()
{
	return m_isAlive;
}

sf::Vector2f Enemy::getPosition()
{
	return m_position;
}

sf::Vector2f Enemy::getVelocity()
{
	return m_velocity;
}

void Enemy::setAlive(bool alive)
{
	m_isAlive = alive;
}

void Enemy::setHealth(float healthChange)
{
	m_health -= healthChange;
}

void Enemy::setPosition(sf::Vector2f position)
{
	m_position = position;
}

void Enemy::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

//
//int rPath;
//random_device rando; //rng 
//mt19937 gen(rando());
//uniform_int_distribution<> dist(0, 1);
//uniform_int_distribution<> dist2(0, 2);
//rPath = dist(gen); //select 