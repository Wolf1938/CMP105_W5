#include "Mario.h"

Mario::Mario()
{
	// Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);

	// Setup swim anim
	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 10.f);

	// Setup swim anim
	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	duck.setFrameSpeed(1.f / 10.f);

	setTextureRect(walk.getCurrentFrame());

}

Mario::~Mario()
{

}

void Mario::update(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		move(0, -1000 * dt);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());
	}
	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		move(0, 1000 * dt);
		swim.animate(dt);
		setTextureRect(swim.getCurrentFrame());
	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		move(1000 * dt, 0);
		duck.animate(dt);
		setTextureRect(duck.getCurrentFrame());
	}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		move(-1000 * dt, 0);
	}
}
