

#include "include.h"
using namespace std;


sf::Sprite testSprite; //sprite used
sf::Texture testTexture; //texture used


sf::Time inputTime; //timer for controller input repeat to be implemented.
sf::Int32 msec = 0; //holds time for cont input


int main()
{

	sf::RenderWindow window(sf::VideoMode(1080, 960), "zippy zoo" /*, sf::Style::Fullscreen*/);
	window.setVerticalSyncEnabled(true);
	//Screens Setup
	
	sf::Clock clock;
	const float FPS = 1.0f / 60;
	sf::Time elapsedTime;

	//Loops
	while (window.isOpen())
	{
		//INPUT LOOP
		sf::Event e;
		while (window.pollEvent(e))
		{
			//If the X button on the window is press, close the window
			if (e.type == sf::Event::Closed)
			{
				window.close();
			}
			//Send input to the current screen
			
		}
	
			inputTime += clock.getElapsedTime(); //########
			msec = inputTime.asSeconds();

		//GAME LOOP
		elapsedTime += clock.restart();	//Add time since last update
		if (elapsedTime.asSeconds() > FPS)	//If it's been long enough...
		{
			//window 
			window.clear();

			//UPDATE CALL###
			//call methods
		
			elapsedTime = sf::Time::Zero;
			//Display current frame
			window.display();
			elapsedTime = elapsedTime.Zero;
		}
	}
	return 0;
}


//
//
//void checkGameStates(sf::RenderWindow& window)
//{
//
//
//	if (gameState == GameState::Upgrade)
//	{
//		if (tiles.getTowerManager()->getTowers()->size() > 0) //if there are towers to upgrade, and there are towers at all, upgrade the tower
//		{
//			tiles.getTowerManager()->upgrade(player);
//		}
//		gameState = GameState::Play; //back to play once upgrade is complete.
//	}
//
//	if (gameState == GameState::Help)
//	{
//		testTexture.loadFromFile("help.png"); //load the help screen
//		testSprite.setTexture(testTexture);
//		window.draw(testSprite); //draw help screen
//	}
//
//	if (gameState == GameState::GameOver)
//	{
//		testTexture.loadFromFile("gameover.png"); //load and draw gameover screen
//		testSprite.setTexture(testTexture);
//		window.draw(testSprite);
//		retry.initialize(0, true, player, gameState); //update retry button
//		retry.update(0, 0, 0, gameState, window, player, 0);
//
//		if (sf::Joystick::isButtonPressed(0, 0)) //if retry is pressed.
//		{
//			runOnce = false;
//			gameState = retry.pressed(0, gameState);
//
//			for (size_t i = 0; i < noOfEnemies; i++)  //reinitialise game objects.
//			{
//				enemy[i].initialise(i);
//			}
//
//			hudHealth.Initialise();
//
//			for (size_t i = 0; i < noOfHudButtons; i++)
//			{
//				hudButton[i].initialize(0, false, player, gameState);
//			}
//			player.setScore(0);
//			player.setMoney(100);
//			tiles.getTowerManager()->getTowers()->clear(); ///clear towers for restart
//		}
//	}
//

//}