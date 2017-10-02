
#include "Player.h"
using namespace std;

Player::Player() {}
Player::~Player() {} //deconstructor

void Player::initialise(int i)
{
	m_texture.loadFromFile("Player.png"); //reset relevant vars
	m_image.setTexture(m_texture); //apply texture to image
	m_position = sf::Vector2f(200, 700); //offset each Player (formerly i* 86) CONST
	m_isAlive = false; //for test only

	maxVelo = sf::Vector2f(0, -2);
	minVelo = sf::Vector2f(0, 0);

	if (i == 0)
	{
		m_isAlive = true;
	}
}

//if enemies are alive, they should be doing stuff
void Player::update(sf::RenderWindow& window, sf::Event e)
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

	if (e.type == sf::Event::KeyPressed)
	{
		if (e.key.code == sf::Keyboard::Up)
		{
			if (m_velocity.y > maxVelo.y)
			{
				m_velocity.y -= 0.01f;
			}
		}
		else if (e.key.code == sf::Keyboard::Down)
		{
			if (m_velocity.y < 0)
			{
				m_velocity.y += 0.01f;
			}
		}
	}


	cout << std::to_string(m_velocity.y)  << endl;



	m_position += m_velocity;

	m_image.setPosition(m_position); //set position of sprite
	window.draw(m_image);
	//	}


}


float Player::getHealth()
{
	return m_health;
}

bool Player::getAlive()
{
	return m_isAlive;
}

sf::Vector2f Player::getPosition()
{
	return m_position;
}

sf::Vector2f Player::getVelocity()
{
	return m_velocity;
}

void Player::setAlive(bool alive)
{
	m_isAlive = alive;
}

void Player::setHealth(float healthChange)
{
	m_health -= healthChange;
}

void Player::setPosition(sf::Vector2f position)
{
	m_position = position;
}

void Player::setVelocity(sf::Vector2f velocity)
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