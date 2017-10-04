
#include "Enemy.h"
using namespace std;

Enemy::Enemy() {}
Enemy::~Enemy() {} //deconstructor

void Enemy::initialise(int i)
{
	if (i == 0) {
		m_texture.loadFromFile("ai.png"); //reset relevant vars
		m_image.setTexture(m_texture); //apply texture to image
		m_position = sf::Vector2f(436 + (128), 700); //offset each enemy (formerly i* 86) CONST
	}

	else if (i == 1) {
		m_texture.loadFromFile("enemy2.png"); //reset relevant vars
		m_image.setTexture(m_texture); //apply texture to image
		m_position = sf::Vector2f(736 + (128), 700); //offset each enemy (formerly i* 86) CONST
		m_image.setScale(0.1f,0.1f);
	}

	else if (i == 2) {
		m_texture.loadFromFile("enemy3.png"); //reset relevant vars
		m_image.setTexture(m_texture); //apply texture to image
		m_position = sf::Vector2f(1036 + (128), 700); //offset each enemy (formerly i* 86) CONST
		m_image.setScale(0.3f, 0.3f);
	}
	endDegrees = 0;
	lastDegrees = 0;
	m_isAlive = false; //for test only
	m_image.setOrigin(sf::Vector2f(m_image.getGlobalBounds().width / 2.0f, (m_image.getGlobalBounds().height / 2.0f)));
	minSpeed = 0;
	maxSpeed = 4;
	speed = 1;
	m_image.setScale(0.3f, 0.3f);
	m_image.rotate(-90); //maybe set this before the game starts with the player's respective atan blah blah

	m_isAlive = true;
	
	m_radius = 50;
	m_timeToTarget = 0;

	orient = 0;

	currentWaypoint = 0; //head to first waypoint at first.
	int hund = 100;
	m_waypoint.reserve(5);
//	cout << std::to_string(m_waypoint.size()) << endl;


	random_device rando; //rng 
	mt19937 gen(rando());
	uniform_int_distribution<> dist(0, 1);
	uniform_int_distribution<> dist2(0, 2);
	rPath = dist(gen); //select 
	m_image.setOrigin(16, 16);
	m_waypoint.clear(); //if game restarts we want a fresh vector



}

//if enemies are alive, they should be doing stuff
void Enemy::update(sf::RenderWindow& window, float i, Player target)
{

	m_velocity.x = sin((3.14 / 180)*orient) * speed;// * t.asSeconds();

	m_velocity.y = cos((3.14 / 180)*orient)* speed; //* t.asSeconds();



	

	//getOrient(orient, m_velocity);
	if (i == 0)
	{
		Seek(target);
		
	}

	else if (i == 1)
	{
		Seek(target);
	}


	//orient = ( 180/ 3.14) *orient;
	//cout << orient << endl;


	//float degrees = orient * (180.0 / 3.14);

	//if (lastDegrees == 0)
	//{
	//	
	//}



	//m_position = m_position + m_velocity; //lastly, update position with velo

	if (i == 1)
	{
		cout << "degree: " << orient << endl;
		cout << "rotation " << rotation << endl;
	}



	if (orient < 0)
	{
		rotation = 1;
		orient += 1;
	}
	else if (orient > 0)
	{
		rotation = -1;
		orient -= 1;
	}





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


	m_image.setRotation((orient));


	m_image.setPosition(m_position); //set position of sprite


	window.draw(m_image);




}

//flee Velocity = my.position - target.position

float Enemy::getOrient(float orientation, sf::Vector2f velocity, Player target)
{


	//CGPoint originPoint = CGPointMake(endingPoint.x - startingPoint.x, endingPoint.y - startingPoint.y); // get origin point to origin by subtracting end from start
	//float bearingRadians = atan2f(originPoint.y, originPoint.x); // get bearing in radians
	//float bearingDegrees = bearingRadians * (180.0 / M_PI); // convert to degrees
	//bearingDegrees = (bearingDegrees > 0.0 ? bearingDegrees : (360.0 + bearingDegrees)); // correct discontinuity
	//return bearingDegrees;


	m_velocity = target.getPosition() - m_position; //getcentresmayb
	float bearingRad = atan2f(target.getPosition().y, target.getPosition().x);
	float bearingDegrees = bearingRad * (180 / 3.14);
	 bearingDegrees = (bearingDegrees > 0.0 ? bearingDegrees : (360.0 + bearingDegrees));

	return bearingDegrees;




	//float mag = m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y;

	//
	//mag = sqrt(mag); //length of vector

	//if (mag > 0) //if valid vector, calc new ori
	//{
	//	cout << mag << endl;
	//	return atan2(target.getPosition().y, target.getPosition().x);
	//}

	//return 0; //else return same ori
}


void Enemy::Flee(Player target)
{

	m_velocity = sf::Vector2f(m_position.x+offSet, m_position.y+offSet) - sf::Vector2f(target.getPosition().x +offSet, target.getPosition().y+offSet); //getcentresmayb

	float mag = m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y;
	mag = sqrt(mag); //length of vector
	m_velocity = m_velocity / mag;
	//orient = getOrient(orient, m_velocity, target);
	//m_velocity = normalize(velocity)
	m_velocity = m_velocity * maxSpeed;

}

void Enemy::Wander(Player target)
{

}

void Enemy::Seek(Player target)
{


	m_velocity = target.getPosition() - m_position; //getcentresmayb
	//m_velocity = sf::Vector2f(target.getPosition().x + offSet, target.getPosition().y + offSet) - sf::Vector2f(m_position.x + offSet, m_position.y + offSet) ; //getcentresmayb

	float mag = m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y;

	mag = sqrt(mag); //length of vector

	m_velocity = m_velocity / mag;

	//m_velocity = normalize(velocity)
	m_velocity = m_velocity * maxSpeed;

	orient = getOrient(orient, m_velocity, target);
}


//function getNewOrientation(currentOrientation, velocity)
//If(velocity.length() > 0) then
//// Note atan2 returns an rotation in radians which you 
//// may want to convert to degrees.
//return atan2(-currentXposition, currentZposition)
//Else
//return currentOrientation


//
//
//Velocity = target.position - my.position
//Velocity = normalize(velocity)
//Velocity = velocity * maxSpeed
//Orientation = getNewOrientation(orientation, velocity)


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


/*if (rotation > 360)
{
rotation -= 360;
}
if (rotation < -360)
{
rotation += 360;
}
*/


/*function rotateOverTime(vector, angle, timespan, elapsedTimeSinceStart) :
partialAngle = elapsedTimeSinceStart / timespan * angle;
rotateZ(vector, partialAngle);*/


//if (rotation == 0)
//{
//	if (degrees < 5)
//	{
//		if (degrees > -5)
//		{
//			m_image.rotate(degrees);
//			degrees += degrees;
//		}
//		else {
//			m_image.rotate(-5);
//			degrees -= 5;
//		}
//	}
//	else if (degrees > 5)
//	{
//		if (degrees < 5)
//		{
//			m_image.rotate(degrees);
//			degrees -= degrees;
//		}
//		else {
//			m_image.rotate(5);
//			degrees -= 5;
//		}
//	}
//}
//m_image.rotate(rotation);

//lastDegrees = degrees;





//if (rotation == 0)
//{
//	rotation = degrees;
//}
//

//rotation = degrees - lastDegrees;

//if (rotation > -0.01 && rotation < 0.01)
//{
//	rotation = 0;
//}

//if (degrees == lastDegrees)
//{
//	rotation = degrees;
//}




//if (degrees != lastDegrees)
//{
//	//degrees = (std::stoi(degrees *-1)) % 360;
//	if (rotation < degrees +1)
//	{
//		if (rotation > degrees -1) //within 2 deg
//		{ 

//			m_image.rotate(1); //somehow find goal angle and only do this if we aren't at it.
//			rotation += 1;
//		
//		}

//	}
//	lastDegrees = degrees;
//}

//if (orient < -1)
//{
//	m_image.rotate((orient +1));
//}
//else {
//	
//}


