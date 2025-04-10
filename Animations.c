#include "raylib.h"
 
typedef struct Animations {
    Texture2D player_idle;
    Texture2D player_run;
    Texture2D player_jump;
 
    Texture2D enemy1_idle;
    Texture2D enemy1_run;
 
    Texture2D enemy2_idle;
    Texture2D enemy2_run;
 
    Rectangle player_idle_src;
    Rectangle player_run_src;
    Rectangle player_jump_src;
 
    Rectangle enemy1_idle_src;
    Rectangle enemy1_run_src;
 
    Rectangle enemy2_idle_src;
    Rectangle enemy2_run_src;
 
    Rectangle player_disp;
    Rectangle enemy1_disp;
    Rectangle enemy2_disp;
 
    Vector2 origin;
 
    int player_timer;
    int enemy1_timer;
    int enemy2_timer;
} Animations;
 
void player_idle(Animations* anim);
void player_run(Animations* anim);
void player_jump(Animations* anim);
 
void enemy1_run(Animations* anim);
void enemy2_run(Animations* anim);
 
void player_idle(Animations* anim) {
    if (anim->player_timer % 6 == 0)
        anim->player_idle_src.x += 48;
    DrawTexturePro(anim->player_idle, anim->player_idle_src, anim->player_disp, anim->origin, 0, RAYWHITE);
    anim->player_timer++;
    if (anim->player_timer == 30)
        anim->player_timer = 0;
}
 
void player_run(Animations* anim) {
    if (anim->player_timer % 6 == 0)
        anim->player_run_src.x += 48;
    DrawTexturePro(anim->player_run, anim->player_run_src, anim->player_disp, anim->origin, 0, RAYWHITE);
    anim->player_timer++;
    if (anim->player_timer == 30)
        anim->player_timer = 0;
}
 
void player_jump(Animations* anim) {
    DrawTexturePro(anim->player_jump, anim->player_jump_src, anim->player_disp, anim->origin, 0, RAYWHITE);
}
 
void enemy1_run(Animations* anim) {
    if (anim->enemy1_timer % 8 == 0)
        anim->enemy1_run_src.x += 64;
    DrawTexturePro(anim->enemy1_run, anim->enemy1_run_src, anim->enemy1_disp, anim->origin, 0, RAYWHITE);
    anim->enemy1_timer++;
    if (anim->enemy1_timer == 40)
        anim->enemy1_timer = 0;
}
 
void enemy2_run(Animations* anim) {
    if (anim->enemy2_timer % 8 == 0)
        anim->enemy2_run_src.x += 64;
    DrawTexturePro(anim->enemy2_run, anim->enemy2_run_src, anim->enemy2_disp, anim->origin, 0, RAYWHITE);
    anim->enemy2_timer++;
    if (anim->enemy2_timer == 40)
        anim->enemy2_timer = 0;
}
 
int main(void) {
    InitWindow(800, 600, "Player and Enemy Animations");
    Animations anim = { 0 };
    anim.player_idle = LoadTexture("resources/graphics/player_idle.png");
    anim.player_run = LoadTexture("resources/graphics/player_run.png");
    anim.player_jump = LoadTexture("resources/graphics/player_jump.png");
 
    anim.enemy1_idle = LoadTexture("resources/graphics/enemy1_idle.png");
    anim.enemy1_run = LoadTexture("resources/graphics/enemy1_run.png");
 
    anim.enemy2_idle = LoadTexture("resources/graphics/enemy2_idle.png");
    anim.enemy2_run = LoadTexture("resources/graphics/enemy2_run.png");
 
    anim.player_idle_src = (Rectangle){0, 0, 48, 48};
    anim.player_run_src = (Rectangle){0, 0, 48, 48};
    anim.player_jump_src = (Rectangle){0, 0, 48, 48};
 
    anim.enemy1_idle_src = (Rectangle){0, 0, 64, 64};
    anim.enemy1_run_src = (Rectangle){0, 0, 64, 64};
 
    anim.enemy2_idle_src = (Rectangle){0, 0, 64, 64};
    anim.enemy2_run_src = (Rectangle){0, 0, 64, 64};
 
    anim.player_disp = (Rectangle){100, 400, 48, 48};
    anim.enemy1_disp = (Rectangle){300, 400, 64, 64};
    anim.enemy2_disp = (Rectangle){500, 400, 64, 64};
 
    anim.origin = (Vector2){0, 0};
 
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
 
        player_idle(&anim);
        player_run(&anim);
        player_jump(&anim);
 
        enemy1_idle(&anim);
        enemy1_run(&anim);
 
        enemy2_idle(&anim);
        enemy2_run(&anim);
 
        EndDrawing();
    }
 
    UnloadTexture(anim.player_idle);
    UnloadTexture(anim.player_run);
    UnloadTexture(anim.player_jump);
    UnloadTexture(anim.enemy1_idle);
    UnloadTexture(anim.enemy1_run);
    UnloadTexture(anim.enemy2_idle);
    UnloadTexture(anim.enemy2_run);
 
    CloseWindow();
    return 0;
}
