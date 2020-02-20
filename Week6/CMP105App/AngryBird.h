#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class AngryBird: public GameObject
{
public:
	AngryBird();
	~AngryBird();

	void handleInput(float dt) override;

};

