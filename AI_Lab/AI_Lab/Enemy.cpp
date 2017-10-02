
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
	m_image.setOrigin(sf::Vector2f(m_image.getGlobalBounds().width / 2.0f, (m_image.getGlobalBounds().height / 2.0f)));
	minSpeed = 0;
	maxSpeed = 4;
	speed = 3;
	m_image.setScale(0.3f, 0.3f);
	m_image.rotate(180);
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
}

//if enemies are alive, they should be doing stuff
void Enemy::update(sf::RenderWindow& window, float i)
{

	m_velocity.x = sin((3.14 / 180)*angle) * speed;// * t.asSeconds();

	m_velocity.y = cos((3.14 / 180)*angle)* speed; //* t.asSeconds();


	m_position = m_position + m_velocity;


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

	//if (e.type == sf::Event::KeyPressed)
	//{
	//	if (e.key.code == sf::Keyboard::Up)
	//	{
		//	if (speed < maxSpeed)
		//	{
		//		speed += 0.1;
		//	}
		//	/*	if (m_velocity.y > maxVelo.y)
		//	{
		//	m_velocity.y -= 0.01f;
		//	}*/
		//}
		//else if (e.key.code == sf::Keyboard::Down)
		//{
		//	/*	if (m_velocity.y < 0)
		//	{
		//	m_velocity.y += 0.01f;
		//	}*/
		//	if (speed > minSpeed)
		//	{
		//		speed -= 0.1;
		//	}
		//}

		//if (e.key.code == sf::Keyboard::Left)
		//{
		//	angle += 5;
		//	m_image.rotate(-5);
		//}
		//else if (e.key.code == sf::Keyboard::Right)
		//{
		//	angle -= 5;
		//	m_image.rotate(5);
		//}

	if (angle > 360)
	{
		angle -= 360;
	}
	if (angle < -360)
	{
		angle += 360;
	}

	m_image.setPosition(m_position); //set position of sprite
	window.draw(m_image);

	

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