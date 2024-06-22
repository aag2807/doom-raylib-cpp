#include "Projectile.h"

Projectile::Projectile(float startX, float startY, float directionX, float directionY)
{
    posX = startX;
    posY = startY;
    dirX = directionX;
    dirY = directionY;
    active = true;
}

void Projectile::Update(float moveSpeed)
{
    posX += dirX * moveSpeed;
    posY += dirY * moveSpeed;

    // Check if the projectile is out of bounds
    if (posX < 0 || posX >= 24 || posY < 0 || posY >= 24)
    {
        active = false;
    }
}

void Projectile::Draw()
{
    if (active)
    {
        DrawCircle(posX * 10, posY * 10, 3, YELLOW);
    }
}
