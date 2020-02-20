#include "Ball.h"

Ball::Ball()
{
	scale = 200.f;
	gravity = sf::Vector2f(0, 9.8) * scale;

	jumpVector = sf::Vector2f(0, -5.f) * scale;
	isJumping = false;
}

Ball::~Ball()
{

}

void Ball::handleInput(float dt)
{
	//Check if already jumping
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}

	if (input->isMouseLDown())
	{
		mouseX = input->getMouseX();
		mouseY = input->getMouseY();

		setPosition(mouseX, mouseY);
		
	}
}

void Ball::update(float dt)
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut + 1/2at^2
	stepVelocity += gravity * dt; // v = u + at
	setPosition(getPosition() + pos);

	//Check for collision with floor
	if (getPosition().y >= 500)
	{
		isJumping = false;
		setPosition(getPosition().x, 500);
		stepVelocity = sf::Vector2f(0, 0);
	}

}