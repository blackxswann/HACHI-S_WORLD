#include "raylib.h"
#define TILE_SIZE 60    
#define MAP_ROWS 18     
#define MAP_COLUMNS 64
 
void DrawLevel(int offsetX, Texture2D groundTexture, Texture2D skyTexture, char levelMap[MAP_ROWS][MAP_COLUMNS + 1]) {
    for (int row = 0; row < MAP_ROWS; row++) {
        for (int col = 0; col < MAP_COLUMNS; col++) {
            // Access the map element directly
            char tile = levelMap[row][col];
            int x = col * TILE_SIZE - offsetX;
 
            // Only draw tiles that are visible on screen (optimization)
            if (x < -TILE_SIZE || x > GetScreenWidth()) continue;
 
            int y = row * TILE_SIZE;
            if (tile == '#') {
                DrawTexture(groundTexture, x, y, WHITE);
            }
            else if (tile == 'S' || tile == ' ') {
                DrawTexture(skyTexture, x, y, WHITE);
            }
        }
    }
}
 
int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;
 
    // Initialize window before loading textures
    InitWindow(screenWidth, screenHeight, "Scrolling Game");
 
    //Level one map
    /*Texture2D groundTexture = LoadTexture("Resources/LevelOnePlatform.png");
    Texture2D skyTexture = LoadTexture("Resources/Sky.png");
 
    char levelOneMap[MAP_ROWS][MAP_COLUMNS + 1] = {
    "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
    "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                 ##                           #",
    "#                                    ###                       #",
    "#                               #         #                    #",
    "#           ##                                ####             #",
    "#        ## ##              #####             ####             #",
    "#      #    ##    ##        #####             ####             #",
    "#  ###      ##    ## ##     #####             ####             #",
    "################################################################",
    "################################################################",
    "################################################################",
    "################################################################"
    };*/
 
    //Level two map
    /*Texture2D groundTexture = LoadTexture("Resources/IcePlatform.png");
    Texture2D skyTexture = LoadTexture("Resources/NightSky.png");
    Texture2D bridgeTexture = LoadTexture("Resources/IceBridge.png");
 
    char levelTwoMap[MAP_ROWS][MAP_COLUMNS + 1] = {
    "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
    "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                 ======                       #",
    "#                                =      ===                    #",
    "#           ##====##            =          == ####             #",
    "#        == ##    ##        #####             #### #           #",
    "#      =    ##    ## ##=====#####             ####  #          #",
    "#  ###      ##    ## ##     #####             ####   #         #",
    "################################################################",
    "################################################################",
    "################################################################",
    "################################################################"
    };*/
 
    //Level three map
    Texture2D groundTexture = LoadTexture("Resources/UndergroundTile.png");
    Texture2D skyTexture = LoadTexture("Resources/UndergroundBG.png");
 
    char levelThreeMap[MAP_ROWS][MAP_COLUMNS + 1] = {
    "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
    "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                                              #",
    "#                                       ###                    #",
    "#             ####                ######    ##                 #",
    "#           ##    ##          ###             #### #           #",
    "#        ###   ##    ###  #####               ####   ###       #",
    "#  ### #    ##    ##      #####     ###       ####       ###   #",
    "######    ###########     ########      ########################",
    "######    ########################      ########################",
    "######    ######################################################",
    "################################################################"
    };
 
    int scrollX = 0;
    SetTargetFPS(60);
 
    while (!WindowShouldClose())
    {
        scrollX += 2;
        // Fix boundary condition to prevent going too far
        if (scrollX > (MAP_COLUMNS * TILE_SIZE - screenWidth))
            scrollX = 0;
 
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawLevel(scrollX, groundTexture, skyTexture, levelThreeMap);
        EndDrawing();
    }
 
    UnloadTexture(groundTexture);
    UnloadTexture(skyTexture);
    CloseWindow();
 
    return 0;
}
