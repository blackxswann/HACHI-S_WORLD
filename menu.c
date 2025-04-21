#include "raylib.h"
#include <stdbool.h>
 
typedef struct {
    // Para sa animation (tentative)
    int state;
    int framesCounter;
    int topSideRecWidth;
    int leftSideRecHeight;
    int bottomSideRecWidth;
    int rightSideRecHeight;
    int lettersCount;
    float alpha;
    bool init;
    int logoPositionX;
    int logoPositionY;
 
    // Graphics sa menu
    Vector2 mouse_pos;
    Texture2D menu_background1;
    Texture2D menu_background2;
    Texture2D logo;
    Rectangle background_src;
    Rectangle background_disp;
    Rectangle logo_src;
    Rectangle logo_disp;
    Vector2 origin;
    Rectangle start_button;
    Rectangle keybindings_button;
    Rectangle exit_button;
    Font font;
    Vector2 start_game_pos;
    Vector2 keybindings_pos;
    Vector2 exit_pos;
 
    // Graphics para sa keybindings
    Rectangle return_button;
    Rectangle keybindings_background;
    Vector2 return_pos;
    Vector2 movement_pos;
    Vector2 sprint_pos;
    Vector2 jump_pos;
} Menu;
 
//Initialization sa graphics sa menu
void InitMenu(Menu* menu) {
    menu->state = 0;
    menu->framesCounter = 0;
    menu->topSideRecWidth = 0;
    menu->leftSideRecHeight = 0;
    menu->bottomSideRecWidth = 0;
    menu->rightSideRecHeight = 0;
    menu->lettersCount = 0;
    menu->alpha = 1.0f;
    menu->init = true;
    menu->logoPositionX = 0; 
    menu->logoPositionY = 0; 
}
 
//Animation sa menu (tentative)
void MenuInitAnimation(Menu* menu) {
    if (menu->state == 0) {
        menu->framesCounter++;
        if (menu->framesCounter == 120) {
            menu->state = 1;
            menu->framesCounter = 0;
        }
    }
    else if (menu->state == 1) {
        menu->topSideRecWidth += 4;
        menu->leftSideRecHeight += 4;
        if (menu->topSideRecWidth == 256)
            menu->state = 2;
    }
    else if (menu->state == 2) {
        menu->bottomSideRecWidth += 4;
        menu->rightSideRecHeight += 4;
        if (menu->bottomSideRecWidth == 256)
            menu->state = 3;
    }
    else if (menu->state == 3) {
        menu->framesCounter++;
        if (menu->framesCounter / 12) {
            menu->lettersCount++;
            menu->framesCounter = 0;
        }
 
        if (menu->lettersCount >= 10) {
            menu->alpha -= 0.02f;
            if (menu->alpha <= 0.0f) {
                menu->alpha = 0.0f;
                menu->state = 4;
            }
        }
    }
    else if (menu->state == 4)
        menu->init = false;
 
    BeginDrawing();
    ClearBackground(RAYWHITE);
 
    if (menu->state == 0) {
        if ((menu->framesCounter / 15) % 2)
            DrawRectangle(menu->logoPositionX, menu->logoPositionY, 16, 16, BLACK);
    }
    else if (menu->state == 1) {
        DrawRectangle(menu->logoPositionX, menu->logoPositionY, menu->topSideRecWidth, 16, BLACK);
        DrawRectangle(menu->logoPositionX, menu->logoPositionY, 16, menu->leftSideRecHeight, BLACK);
    }
    else if (menu->state == 2) {
        DrawRectangle(menu->logoPositionX, menu->logoPositionY, menu->topSideRecWidth, 16, BLACK);
        DrawRectangle(menu->logoPositionX, menu->logoPositionY, 16, menu->leftSideRecHeight, BLACK);
        DrawRectangle(menu->logoPositionX + 240, menu->logoPositionY, 16, menu->rightSideRecHeight, BLACK);
        DrawRectangle(menu->logoPositionX, menu->logoPositionY + 240, menu->bottomSideRecWidth, 16, BLACK);
    }
    else if (menu->state == 3) {
        DrawRectangle(menu->logoPositionX, menu->logoPositionY, menu->topSideRecWidth, 16, Fade(BLACK, menu->alpha));
        DrawRectangle(menu->logoPositionX, menu->logoPositionY + 16, 16, menu->leftSideRecHeight - 32, Fade(BLACK, menu->alpha));
        DrawRectangle(menu->logoPositionX + 240, menu->logoPositionY + 16, 16, menu->rightSideRecHeight - 32, Fade(BLACK, menu->alpha));
        DrawRectangle(menu->logoPositionX, menu->logoPositionY + 240, menu->bottomSideRecWidth, 16, Fade(BLACK, menu->alpha));
        DrawRectangle(GetScreenWidth() / 2 - 112, GetScreenHeight() / 2 - 112, 224, 224, Fade(RAYWHITE, menu->alpha));
        DrawText(TextSubtext("raylib", 0, menu->lettersCount), GetScreenWidth() / 2 - 44, GetScreenHeight() / 2 + 48, 50, Fade(BLACK, menu->alpha));
    }
 
    EndDrawing();
}
 
//Method to draw the graphics sa menu
void MenuDraw(Menu* menu) {
    menu->mouse_pos = GetMousePosition();
 
    ClearBackground(SKYBLUE);
    DrawTexturePro(menu->menu_background1, menu->background_src, menu->background_disp, menu->origin, 0, RAYWHITE);
    DrawTexturePro(menu->menu_background2, menu->background_src, menu->background_disp, menu->origin, 0, RAYWHITE);
    DrawTexturePro(menu->logo, menu->logo_src, menu->logo_disp, menu->origin, 0, RAYWHITE);
 
    DrawRectangleRounded(menu->start_button, 0.3, 0, RAYWHITE);
    DrawRectangleRounded(menu->keybindings_button, 0.3, 0, RAYWHITE);
    DrawRectangleRounded(menu->exit_button, 0.3, 0, RAYWHITE);
 
    DrawRectangleRoundedLines(menu->start_button, 0.3, 0, 6, BLACK);
    DrawRectangleRoundedLines(menu->keybindings_button, 0.3, 0, 6, BLACK);
    DrawRectangleRoundedLines(menu->exit_button, 0.3, 0, 6, BLACK);
 
    DrawTextEx(menu->font, "Start game", menu->start_game_pos, 50, 5, BLACK);
    DrawTextEx(menu->font, "keybindings", menu->keybindings_pos, 50, 5, BLACK);
    DrawTextEx(menu->font, "Exit game", menu->exit_pos, 50, 5, BLACK);
}
 
//Method to draw the graphics sa keybindings
void MenuDrawKeybindings(Menu* menu) {
    menu->mouse_pos = GetMousePosition();
 
    ClearBackground(SKYBLUE);
    DrawTexturePro(menu->menu_background1, menu->background_src, menu->background_disp, menu->origin, 0, RAYWHITE);
    DrawTexturePro(menu->menu_background2, menu->background_src, menu->background_disp, menu->origin, 0, RAYWHITE);
    DrawTexturePro(menu->logo, menu->logo_src, menu->logo_disp, menu->origin, 0, RAYWHITE);
 
    DrawRectangleRounded(menu->return_button, 0.3, 0, RAYWHITE);
    DrawRectangleRoundedLines(menu->return_button, 0.3, 0, 6, BLACK);
 
    DrawRectangleRounded(menu->keybindings_background, 0.3, 0, RAYWHITE);
    DrawRectangleRoundedLines(menu->keybindings_background, 0.3, 0, 6, BLACK);
 
    DrawTextEx(menu->font, "Return to menu", menu->return_pos, 50, 5, BLACK);
    DrawTextEx(menu->font, "movement", menu->movement_pos, 30, 3, BLACK);
    DrawTextEx(menu->font, "sprint", menu->sprint_pos, 30, 3, BLACK);
    DrawTextEx(menu->font, "jump", menu->jump_pos, 30, 3, BLACK);
}
