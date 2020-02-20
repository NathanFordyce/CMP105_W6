#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Moving: public GameObject
{
public:
	Moving();
	~Moving();

	void handleInput(float dt) override;
	void update(float dt) override;

	float speed;
	float acceleration;
	float mouseX;
	float mouseY;
	sf::Vector2f velocity;
	sf::Vector2f target;
	sf::Vector2f direction;
	

};

