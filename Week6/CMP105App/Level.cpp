#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballSprite.loadFromFile("gfx/Beach_Ball.png");
	ball.setTexture(&ballSprite);
	ball.setSize(sf::Vector2f(100, 100));
	ball.setPosition(0, 0);
	ball.setInput(input);	
	
	movingTexture.loadFromFile("gfx/mushroomTrans.png");
	moving.setTexture(&movingTexture);
	moving.setSize(sf::Vector2f(100, 100));
	moving.setPosition(0, 0);
	moving.setInput(input);

	shootSprite.loadFromFile("gfx/goomba.png");
	shoot.setTexture(&shootSprite);
	shoot.setSize(sf::Vector2f(75, 75));
	shoot.setPosition(0, 600);
	shoot.setInput(input);



}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.handleInput(dt);
	moving.handleInput(dt);
	shoot.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
	moving.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);
	window->draw(moving);
	window->draw(shoot);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}