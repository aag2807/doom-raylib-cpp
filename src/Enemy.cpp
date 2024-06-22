#include "Enemy.h"
#include "Player.h"
#include "math.h"

Enemy::Enemy(float startX, float startY)
{
    posX = startX;
    posY = startY;
    active = true;
}


void Enemy::Draw(Player &player, int screenWidth, int screenHeight)
{
    if (!active) return;

    // Calculate relative position to player
    float relativeX = posX - player.posX;
    float relativeY = posY - player.posY;

    // Transform enemy position to player's camera space
    float invDet = 1.0 / (player.planeX * player.dirY -
                          player.dirX * player.planeY); // required for correct matrix multiplication

    float transformX = invDet * (player.dirY * relativeX - player.dirX * relativeY);
    float transformY = invDet * (-player.planeY * relativeX + player.planeX * relativeY); // depth inside the screen

    // Only draw enemies in front of the player and within a reasonable distance
    if (transformY > 0.1)
    {
        // Calculate screen position
        int enemyScreenX = int((screenWidth / 2) * (1 + transformX / transformY));

        // Calculate height and width of the enemy
        int enemyHeight = abs(int(screenHeight /
                                  (transformY))); // using "transformY" instead of the real distance prevents fisheye effect
        int enemyWidth = abs(int(screenHeight / (transformY)));

        // Calculate lowest and highest pixel to fill in current stripe
        int drawStartY = -enemyHeight / 2 + screenHeight / 2;
        if (drawStartY < 0) drawStartY = 0;
        int drawEndY = enemyHeight / 2 + screenHeight / 2;
        if (drawEndY >= screenHeight) drawEndY = screenHeight - 1;

        // Calculate the lowest and highest pixel to fill in the current stripe
        int drawStartX = -enemyWidth / 2 + enemyScreenX;
        if (drawStartX < 0) drawStartX = 0;
        int drawEndX = enemyWidth / 2 + enemyScreenX;
        if (drawEndX >= screenWidth) drawEndX = screenWidth - 1;

        // Ensure the enemy is within screen boundaries
        if (drawStartX < screenWidth && drawEndX >= 0 && drawStartY < screenHeight && drawEndY >= 0)
        {
            // Draw the enemy as a red rectangle
            DrawRectangle(drawStartX, drawStartY, enemyWidth, enemyHeight, GREEN);
        }
    }
}