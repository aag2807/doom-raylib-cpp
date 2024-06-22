//
// Created by Dev ATL on 22/6/24.
//

#ifndef DOOM_TEST_PROJECTILE_H
#define DOOM_TEST_PROJECTILE_H

#include "raylib.h"

class Projectile
{
public:
    float posX, posY; // Projectile position
    float dirX, dirY; // Projectile direction vector
    bool active;      // Is the projectile active?

    void Update(float moveSpeed);

    void Draw();

    Projectile(float startX, float startY, float dirX, float dirY);
};


#endif //DOOM_TEST_PROJECTILE_H
