#pragma once
#include "Framework/GameObject.h"


class Ball : public GameObject
{
public:
	Ball();
	~Ball();

	void update(float dt) override;
	void handleInput(float dt) override;

	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	bool isJumping;
	float mouseX;
	float mouseY;

};

