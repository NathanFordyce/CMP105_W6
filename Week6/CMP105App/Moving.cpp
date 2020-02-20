#include "Moving.h"

Moving::Moving()
{
	speed = 100.f;
	acceleration = 50.f;
	//target = sf::Vector2f(600, 300);
}

Moving::~Moving()
{

}

void Moving::handleInput(float dt)
{
	mouseX = input->getMouseX();
	mouseY = input->getMouseY();

	target = sf::Vector2f(mouseX, mouseY);
}

void Moving::update(float dt)
{
	//Calculate direction and move
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity += (direction * speed) * dt; //fixed speed
	setPosition(getPosition() + (velocity * dt));

	//if object is close enough to target
	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
	}
}