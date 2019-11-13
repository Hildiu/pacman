//
// Created by Maria Hilda Bermejo on 11/12/19.
//

#ifndef PACMAN_CGAME_H
#define PACMAN_CGAME_H
#include "Udefiniciones.h"
#include "CRectangulo.h"

class CGame {
private:
    sf::RenderWindow *palCanvas= nullptr;
    CRectangulo *palRectangulo= nullptr;
    bool mIsMovingUp=false;
    bool mIsMovingDown=false;
    bool mIsMovingLeft=false;
    bool mIsMovingRight=false;
private:
    void   processEvents();
    void   update();
    void   render();
    void   handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
public:
    CGame(){}
    CGame(sf::RenderWindow *_palCanvas);
    virtual ~CGame();
    void   run();
};

#endif //PACMAN_CGAME_H
