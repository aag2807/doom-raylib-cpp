#include "Game.h"

Game::Game() : player(22, 12)
{
    worldMap = new int *[24];
    for (int i = 0; i < 24; ++i)
    {
        worldMap[i] = new int[24];
        for (int j = 0; j < 24; ++j)
        {
            worldMap[i][j] = 1;
        }
    }

    // Initialize the map as before
    int tempMap[24][24] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    for (int i = 0; i < 24; ++i)
    {
        for (int j = 0; j < 24; ++j)
        {
            worldMap[i][j] = tempMap[i][j];
        }
    }

    // Add some enemies
    SpawnEnemies(5);
}

Game::~Game()
{
    for (int i = 0; i < 24; ++i)
    {
        delete[] worldMap[i];
    }
    delete[] worldMap;
}

void Game::Run()
{
    InitWindow(screenWidth, screenHeight, "DOOM Raylib");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        player.Move(worldMap, 0.05, 0.05);

        if (IsKeyPressed(KEY_SPACE))
        {
//            Shoot(); TODO: fix spawning point and direction of projectiles
        }

        for (Projectile &projectile: projectiles)
        {
            projectile.Update(0.1);
        }

        CheckCollisions();

        BeginDrawing();
        ClearBackground(BLACK);

        // Draw floor
        DrawRectangle(0, screenHeight / 2, screenWidth, screenHeight / 2, GRAY);

        DrawWorld();

        for (Enemy &enemy: enemies)
        {
            enemy.Draw(player, screenWidth, screenHeight);
        }

        for (Projectile &projectile: projectiles)
        {
            projectile.Draw();
        }

        // Draw gun (black rectangle in the center bottom)
        int gunWidth = 30;
        int gunHeight = 60;
        int gunPosX = screenWidth / 2 - gunWidth / 2;
        int gunPosY = screenHeight - gunHeight - 10;
        DrawRectangle(gunPosX, gunPosY, gunWidth, gunHeight, BLACK);

        EndDrawing();
    }
    CloseWindow();
}

void Game::DrawWorld()
{
    for (int x = 0; x < screenWidth; x++)
    {
        // calculate ray position and direction
        float cameraX = 2 * x / float(screenWidth) - 1; // x-coordinate in camera space
        float rayDirX = player.dirX + player.planeX * cameraX;
        float rayDirY = player.dirY + player.planeY * cameraX;

        // which box of the map we're in
        int mapX = int(player.posX);
        int mapY = int(player.posY);

        // length of ray from current position to next x or y-side
        float sideDistX;
        float sideDistY;

        // length of ray from one x or y-side to next x or y-side
        float deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        float deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        float perpWallDist;

        // what direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;

        int hit = 0; // was there a wall hit?
        int side; // was a NS or a EW wall hit?

        // calculate step and initial sideDist
        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (player.posX - mapX) * deltaDistX;
        } else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player.posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (player.posY - mapY) * deltaDistY;
        } else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player.posY) * deltaDistY;
        }

        // perform DDA
        while (hit == 0)
        {
            // jump to next map square, OR in x-direction, OR in y-direction
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            // Check if ray has hit a wall
            if (worldMap[mapX][mapY] > 0) hit = 1;
        }

        // Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
        if (side == 0) perpWallDist = (mapX - player.posX + (1 - stepX) / 2) / rayDirX;
        else perpWallDist = (mapY - player.posY + (1 - stepY) / 2) / rayDirY;

        // Calculate height of line to draw on screen
        int lineHeight = (int) (screenHeight / perpWallDist);

        // calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

        // choose wall color
        Color color;
        switch (worldMap[mapX][mapY])
        {
            case 1:
                color = RED;
                break; // red
            default:
                color = GREEN;
                break; // green
        }

        // give x and y sides different brightness
        if (side == 1)
        { color = ColorAlpha(color, 0.5f); }

        DrawLine(x, drawStart, x, drawEnd, color);
    }
}

void Game::SpawnEnemies(int numberOfEnemies)
{
    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < numberOfEnemies; ++i)
    {
        int x, y;
        do
        {
            x = rand() % 24;
            y = rand() % 24;
        } while (worldMap[x][y] != 0); // Ensure the enemy spawns in an empty space

        enemies.push_back(Enemy(x, y));
    }
}

void Game::Shoot()
{
    float projX = player.posX + player.dirX; // Spawn the projectile slightly ahead of the player
    float projY = player.posY + player.dirY;
    float dirX = player.dirX;
    float dirY = player.dirY;
    projectiles.push_back(Projectile(projX, projY, dirX, dirY));
}

void Game::CheckCollisions()
{
    for (Projectile &projectile: projectiles)
    {
        if (projectile.active)
        {
            for (Enemy &enemy: enemies)
            {
                if (enemy.active)
                {
                    float distX = projectile.posX - enemy.posX;
                    float distY = projectile.posY - enemy.posY;
                    float distance = sqrt(distX * distX + distY * distY);

                    if (distance < 0.5)
                    { // Assuming the enemy is hit if within 0.5 units
                        projectile.active = false;
                        enemy.active = false; // Set enemy inactive or remove from list
                    }
                }
            }
        }
    }
}
