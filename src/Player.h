//
// Created by Dev ATL on 22/6/24.
//

#ifndef DOOM_TEST_PLAYER_H
#define DOOM_TEST_PLAYER_H

#include <raylib.h>

class Player {
public:
    float posX, posY;    // Player position
    float dirX, dirY;    // Player direction vector
    float planeX, planeY; // Camera plane

    Player(float startX, float startY);

    void Move(int **worldMap, float moveSpeed, float rotSpeed);
};


#endif //DOOM_TEST_PLAYER_H
