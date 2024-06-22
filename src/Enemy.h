#ifndef DOOM_TEST_ENEMY_H
#define DOOM_TEST_ENEMY_H

#include <raylib.h>
#include "Player.h"

class Enemy
{
public:
    float posX, posY; // Enemy position
    bool active{};

    Enemy(float startX, float startY);

    void Draw(Player &player, int screenWidth, int screenHeight);
};


#endif //DOOM_TEST_ENEMY_H
