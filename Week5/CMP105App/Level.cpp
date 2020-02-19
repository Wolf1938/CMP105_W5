#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombieTexture.loadFromFile("gfx/animZombie.png");
	zombie.setTexture(&zombieTexture);
	zombie.setInput(input);

	mario.setSize(sf::Vector2f(60, 84));
	mario.setPosition(400, 100);
	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setTexture(&marioTexture);
	mario.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	//zombie.update(dt);
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(zombie);
	window->draw(mario);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}