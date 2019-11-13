//
// Created by Maria Hilda Bermejo on 11/12/19.
//

#include "CGame.h"

CGame::CGame(sf::RenderWindow *_palCanvas):palCanvas(_palCanvas)
{
  palRectangulo = new CRectangulo(_palCanvas, 40, 40,_palCanvas->getSize().x/2 - 20, _palCanvas->getSize().y -40,
                  2,2,sf::Color::Cyan);
}

CGame::~CGame()
{
  delete palRectangulo;
}

void CGame::run()
{
  while (palCanvas->isOpen())
  {
    processEvents();
    update();
    render();
  }
}

void CGame::render()
{
  palCanvas->clear();
  palRectangulo->Muestrate();
  palCanvas->display();
}

void CGame::processEvents()
{
  sf::Event event{};
  while (palCanvas->pollEvent(event))
  {
    switch (event.type)
    {case sf::Event::KeyPressed:
        handlePlayerInput(event.key.code, true);
        break;
      case sf::Event::KeyReleased:
        handlePlayerInput(event.key.code, false);
        break;
      case sf::Event::Closed:
        palCanvas->close();
        break;
      default:
        break;
    }
  }
}


void CGame::handlePlayerInput(sf::Keyboard::Key key,
                             bool isPressed)
{
  if (key == sf::Keyboard::Up)
    mIsMovingUp = isPressed;
  else if (key == sf::Keyboard::Down)
    mIsMovingDown = isPressed;
  else if (key == sf::Keyboard::Left)
    mIsMovingLeft = isPressed;
  else if (key == sf::Keyboard::Right)
    mIsMovingRight = isPressed;
}

void CGame::update()
{
  sf::Vector2f movement(0.f, 0.f);
  if (mIsMovingUp)
    movement.y -= 1.f;
  if (mIsMovingDown)
    movement.y += 1.f;
  if (mIsMovingLeft)
    movement.x -= 1.f;
  if (mIsMovingRight)
    movement.x += 1.f;

  palRectangulo->mover(movement);
}
