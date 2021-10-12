#pragma once
#include "BoxCollider.h"
#include "GameObject.h"
#include "Sprite.h"

//inheritance = IS-A
//containment = HAS-A

//the animation state the player is in


class Player : public GameObject   //player is a game object
{
public:

	enum class State
	{
		Idle,
		Walk,
		Up,
		Attack,
		Death,
		TotalStates
	};
	//facing direction
	enum class Direction
	{
		Left,
		Right
	};
	
	Player(Screen& screen);
	~Player();
	State GetState();
	BoxCollider& GetCollider();
	
	void Update(Input& input);
	virtual void Render(Screen& screen);

private:

	State m_state;
	Direction m_facingDirection;
	Sprite m_images[static_cast<unsigned long long>(State::TotalStates)]; 
	BoxCollider m_collider[static_cast<unsigned long long>(State::TotalStates)];
	
	int m_velocity;

	Vector2D m_emptySpace;
	Vector2D m_direction;
};
