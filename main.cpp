#include <iostream>
#include <thread>
#include <chrono> //-- para controlar el retardo
#include "CFigura.h"
#include "CRectangulo.h"
#include "CGame.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(2200, 1200), "SFML works!");
  CGame game(&window);
  game.run();
}
