#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "../raygui.h"
#include <iostream>

static const int screenWidth = 800;
static const int screenHeight = 450;

int clickScore = 0;

float clickerBoxY = 100;
float clickerBoxX = 339;

int clicksNum = 1;

static void DrawClickerGame(void);
static void UpdateClickerGame(void);
static void DoClick(void);
static void UserInterface(void);

Rectangle clickerBox = {clickerBoxX, clickerBoxY, 120, 120};

int main(void){
    InitWindow(screenWidth, screenHeight, "little clicker game");
    SetTargetFPS(60);
    while (!WindowShouldClose()){
        UpdateClickerGame();
        DrawClickerGame();
    }
    CloseWindow();
    return 0;
}

void DrawClickerGame(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangleRec(clickerBox, RED);
    DrawText(TextFormat("Score: %d", clickScore), 0, 30, 20, BLACK);
    UserInterface();
    DrawFPS(0,0);
    EndDrawing();
}

void UpdateClickerGame(void)
{
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        Vector2 mousePos = GetMousePosition();

        //CheckCollisionPointRec uses a vec2(point) and a rectangle, whereas CheckCollisionRec uses 2 rectangles.
        if(CheckCollisionPointRec(mousePos, clickerBox)) {
            DoClick();
        }
    }
}

void DoClick(void)
{
    clickScore += clicksNum;
}

void UserInterface(void)
{
    Rectangle BuyClicksRec = {100, 100, 200, 50};
    if(GuiButton(BuyClicksRec, "Buy More Clicks (100)")){
        if(clickScore >= 100){
            clicksNum += 1;
            clickScore -= 100;
        } 
    }

    Rectangle BuyMultRec = {100, 150, 200, 50};
    if(GuiButton(BuyMultRec, "Buy x2 Mult (15000)")){
        if(clickScore >= 15000){
            clicksNum += clicksNum*2;
            clickScore -= 15000;
        } 
    }
}
