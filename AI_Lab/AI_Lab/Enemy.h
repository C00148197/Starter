#pragma once


#ifndef Enemy_H
#define Enemy_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
//Class used for our Enemy
#include "player.h"
class Enemy
{
public:
	Enemy();
	~Enemy();

	void initialise(int i);


	void update(sf::RenderWindow& window, float i, Player target);


	sf::Vector2f getPosition();
	bool getAlive();
	float getHealth();
	sf::Vector2f getVelocity();


	void Flee(Player target);
	void Seek(Player target);
	void Wander(Player target);

	void rotateOverTime(sf::Vector2f vec, sf::Time timespan, sf::Time elapsedTimeSinceStart);


	void setPosition(sf::Vector2f position);
	void setAlive(bool alive);
	void setHealth(float healthChange);
	void setVelocity(sf::Vector2f velocity);
	float getOrient(float orientation, sf::Vector2f velocity, Player target);
private:

	sf::Sprite m_image; //enemy sprite
	sf::Texture m_texture;  //enemy texture
	int m_size;
	sf::Vector2f m_position; //position of enemy
	const float m_maxHealth = 1; //max enemy health
	float m_health = m_maxHealth; //enemy health
	bool m_isAlive = false; //is enemy alive
	std::vector<sf::Vector2f> m_waypoint; //vector of vector2s that hold the waypoints set for the enemy
	int currentWaypoint; //the current waypoint in a vector
	const int maxWaypoint = 5; //the maximum number of waypoints in a vector
	int rPath; //random path
	sf::Vector2f m_velocity; //enemy velocity
	int enemyType; //fed a random distrubution to see if enemy is type 1, 2 or 3
	float rotation;
	const int offSet = 16;

	float m_radius;
	float m_timeToTarget;

	float lastDegrees;
	float endDegrees;

	float minSpeed;
	float maxSpeed;
	float speed;
	float orient;
};

#endif
