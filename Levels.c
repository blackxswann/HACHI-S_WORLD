#include "Levels.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>  

Levels* CreateLevel(int id) {
    Levels* level = malloc(sizeof(Levels));
    if (!level) return NULL;
    memset(level, 0, sizeof(Levels));
    level->id = id;
    level->skyLevelOne = LoadTexture("Resources/Sky.png");
    level->platformLevelOne = LoadTexture("Resources/LevelOnePlatform.png");
    level->mapRows = 15;
    level->mapCols = 40;
    level->map = malloc(level->mapRows * sizeof(char*));
    level->map_background = malloc(level->mapRows * sizeof(char*));
    // Map initialization
    for (int i = 0; i < level->mapRows; i++) {
        level->map[i] = malloc(level->mapCols * sizeof(char));
        level->map_background[i] = malloc(level->mapCols * sizeof(char));
        memset(level->map[i], ' ', level->mapCols);
        memset(level->map_background[i], ' ', level->mapCols);
    }
    char filename_bg[100];
    char filename_fg[100];
    snprintf(filename_bg, sizeof(filename_bg), "Resources/Maps/Level%d_Background.txt", id);
    snprintf(filename_fg, sizeof(filename_fg), "Resources/Maps/Level%d_Map.txt", id);
    FILE* bg_file = fopen(filename_bg, "r");
    FILE* fg_file = fopen(filename_fg, "r");
    if (bg_file && fg_file) {
        for (int i = 0; i < level->mapRows; i++) {
            fgets(level->map_background[i], level->mapCols + 1, bg_file);
            fgets(level->map[i], level->mapCols + 1, fg_file);
        }
        fclose(bg_file);
        fclose(fg_file);
    }
    else {
        printf("Error loading map files for level %d\n", id);
    }
    return level;
}

// Free the memory for a completed or unplayed level
void DestroyLevel(Levels* level) {
    if (!level) return;
    // Unload textures and music
    UnloadMusicStream(level->levelOneMusic);
    UnloadTexture(level->skyLevelOne);
    UnloadTexture(level->platformLevelOne);
    // Free map memory
    for (int i = 0; i < level->mapRows; i++) {
        free(level->map[i]);
        free(level->map_background[i]);
    }
    free(level->map);
    free(level->map_background);
    free(level);
}

void LevelInitialization(Levels* level) {
    level->startLevel = true;
    level->startPlay = false;
    level->completed = false;
    level->restart = false;
}

void DrawTiles(Levels* level) {
    const int tileSize = 32;
    for (int y = 0; y < level->mapRows; y++) {
        for (int x = 0; x < level->mapCols; x++) {
            if (level->map_background[y][x] == 'S') {
                DrawTexture(level->skyLevelOne, x * tileSize, y * tileSize, WHITE);
            }
        }
    }

    for (int y = 0; y < level->mapRows; y++) {
        for (int x = 0; x < level->mapCols; x++) {
            if (level->map[y][x] == '#') {
                DrawTexture(level->platformLevelOne, x * tileSize, y * tileSize, WHITE);
            }
            else if (level->map_background[y][x] == 'S') {
                DrawTexture(level->skyLevelOne, x * tileSize, y * tileSize, WHITE);
            }
        }
    }
}


bool CheckRectCollisions(Rectangle rec1, Rectangle rec2, Vector2 origin) {
    return CheckCollisionRecs(rec1, rec2);
}