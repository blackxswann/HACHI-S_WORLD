#include <stdio.h>
#include <raylib.h>
#include <stdbool.h>

#define BUTTON_WIDTH 384
#define BUTTON_HEIGHT 78



int main()
{
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(1920, 1080, "Login Screen");

    Texture2D background = LoadTexture("Resources/temporaryBG.png");

    Texture2D loginButtonImage = LoadTexture("Resources/login.png");
    Texture2D signupButtonImage = LoadTexture("Resources/register.png");
    Texture2D exitButtonImage = LoadTexture("Resources/exit.png");
    Texture2D loginpanelImage = LoadTexture("Resources/loginpanel.png");
    Texture2D registerpanelImage = LoadTexture("Resources/registerpanel.png");
    Texture2D loginButtonImage2 = LoadTexture("Resources/login2.png");
    Texture2D registerButtonImage2 = LoadTexture("Resources/register2.png");
    Texture2D gobackImage1 = LoadTexture("Resources/goback.png");

    Rectangle loginButton = { 737, 567, BUTTON_WIDTH, BUTTON_HEIGHT };
    Rectangle signupButton = { 737, 666, BUTTON_WIDTH, BUTTON_HEIGHT };
    Rectangle exitButton = { 737, 761, BUTTON_WIDTH, BUTTON_HEIGHT };
    Rectangle loginButton2 = { 525, 711, BUTTON_WIDTH, BUTTON_HEIGHT };
    Rectangle registerButton2 = { 525, 711, BUTTON_WIDTH, BUTTON_HEIGHT };
    Rectangle gobackButton = { 1026, 711, BUTTON_WIDTH, BUTTON_HEIGHT };

    bool showButtons = true;
    bool showLoginPanel = false;
    bool showRegisterPanel = false;

    float opacity = 0;
    int fadeSpeed = 5;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);

        Vector2 mousePoint = GetMousePosition();

        int centerX = (1920 - loginpanelImage.width) / 2;
        int centerY = (1080 - loginpanelImage.height) / 2;

        if (showLoginPanel || showRegisterPanel) {
            if (opacity < 255) {
                opacity += fadeSpeed;
                if (opacity > 255) opacity = 255;
            }
        }

        if (showLoginPanel) {
            DrawTexture(loginpanelImage, centerX, centerY, (Color) { 255, 255, 255, (unsigned char)opacity });

            Color buttonColor = (Color){ 255, 255, 255, (unsigned char)opacity };

            if (CheckCollisionPointRec(mousePoint, loginButton2))
                DrawTexture(loginButtonImage2, loginButton2.x, loginButton2.y, (Color) { buttonColor.r, buttonColor.g, buttonColor.b, (unsigned char)(opacity * 0.8) });
            else
                DrawTexture(loginButtonImage2, loginButton2.x, loginButton2.y, buttonColor);

            if (CheckCollisionPointRec(mousePoint, gobackButton))
                DrawTexture(gobackImage1, gobackButton.x, gobackButton.y, (Color) { buttonColor.r, buttonColor.g, buttonColor.b, (unsigned char)(opacity * 0.8) });
            else
                DrawTexture(gobackImage1, gobackButton.x, gobackButton.y, buttonColor);
        }

        else if (showRegisterPanel) {
            DrawTexture(registerpanelImage, centerX, centerY, (Color) { 255, 255, 255, (unsigned char)opacity });

            Color buttonColor = (Color){ 255, 255, 255, (unsigned char)opacity };

            if (CheckCollisionPointRec(mousePoint, registerButton2))
                DrawTexture(registerButtonImage2, registerButton2.x, registerButton2.y, (Color) { buttonColor.r, buttonColor.g, buttonColor.b, (unsigned char)(opacity * 0.8) });
            else
                DrawTexture(registerButtonImage2, registerButton2.x, registerButton2.y, buttonColor);

            if (CheckCollisionPointRec(mousePoint, gobackButton))
                DrawTexture(gobackImage1, gobackButton.x, gobackButton.y, (Color) { buttonColor.r, buttonColor.g, buttonColor.b, (unsigned char)(opacity * 0.8) });
            else
                DrawTexture(gobackImage1, gobackButton.x, gobackButton.y, buttonColor);
        }

        else if (showButtons) {
            if (CheckCollisionPointRec(mousePoint, loginButton))
                DrawTexture(loginButtonImage, loginButton.x, loginButton.y, GRAY);
            else
                DrawTexture(loginButtonImage, loginButton.x, loginButton.y, WHITE);

            if (CheckCollisionPointRec(mousePoint, signupButton))
                DrawTexture(signupButtonImage, signupButton.x, signupButton.y, GRAY);
            else
                DrawTexture(signupButtonImage, signupButton.x, signupButton.y, WHITE);

            if (CheckCollisionPointRec(mousePoint, exitButton))
                DrawTexture(exitButtonImage, exitButton.x, exitButton.y, GRAY);
            else
                DrawTexture(exitButtonImage, exitButton.x, exitButton.y, WHITE);
        }

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (CheckCollisionPointRec(mousePoint, loginButton)) {
                showButtons = false;
                showLoginPanel = true;
                showRegisterPanel = false;
                opacity = 0;
            }
            else if (CheckCollisionPointRec(mousePoint, signupButton)) {
                showButtons = false;
                showRegisterPanel = true;
                showLoginPanel = false;
                opacity = 0;
            }
            else if (CheckCollisionPointRec(mousePoint, exitButton)) {
                break;
            }
            else if (CheckCollisionPointRec(mousePoint, gobackButton) && (showLoginPanel || showRegisterPanel)) {
                showButtons = true;
                showLoginPanel = false;
                showRegisterPanel = false;
                opacity = 0;
            }
            else if (CheckCollisionPointRec(mousePoint, registerButton2) && showRegisterPanel) {
                showButtons = true;
                showRegisterPanel = false;
                opacity = 0;
            }
        }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(loginButtonImage);
    UnloadTexture(signupButtonImage);
    UnloadTexture(exitButtonImage);
    UnloadTexture(loginpanelImage);
    UnloadTexture(registerpanelImage);
    UnloadTexture(loginButtonImage2);
    UnloadTexture(registerButtonImage2);
    UnloadTexture(gobackImage1);

    CloseWindow();
    return 0;
}
