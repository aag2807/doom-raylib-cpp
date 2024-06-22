//
// Created by Dev ATL on 22/6/24.
//

#ifndef DOOM_TEST_GAME_H
#define DOOM_TEST_GAME_H

#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "Projectile.h"
#include "raylib.h"

class Game
{
public:
    const int screenWidth = 800;
    const int screenHeight = 600;
    int **worldMap;
    Player player;
    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;

    Game();

    ~Game();

    void Run();

    void DrawWorld();

    void SpawnEnemies(int numberOfEnemies);

    void Shoot();

    void CheckCollisions();

};


#endif //DOOM_TEST_GAME_H
