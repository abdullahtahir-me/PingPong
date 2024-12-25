/*
Credits:
Muhammad Abdullah Khan
Ali Hassan
Hashim Matloob Raja
*/

#include <raylib.h>
#include<stdio.h>

const int screen_width = 910;
const int screen_height = 578;
int player_score, cpu_score;

void playerMove(float *paddleY);
void cpuMove(float *paddleY);
void chkCollisionPlayer(float *paddleWidth, float *paddleY);
void chkCollisionCpu(float *paddleWidth, float *paddleY);
void gameLogic(bool *scored, double *delayStartTime);

typedef struct player
{
    float width;
    float height;
    float x;
    float y;
    Color color;
} Player;
typedef struct ball
{
    float x;
    float y;
    float rad;
    float speedX;
    float speedY;
    Color color;
} Ball;
typedef enum GameScreen
{
    LOGO = 0,
    MENU,
    GAMELOOP ,
    GAMEOVER
} GameScreen;



Ball ball = {screen_width / 2, screen_height / 2, 15, 5, 5, WHITE};
GameScreen currentScreen = LOGO;
float loadingProgress = 0.0f;
float loadingSpeed = 0.005f;


int main()
{
    Player cpu = {25, 130, 10, screen_height / 2 - 65, GREEN};
    Player player = {25, 130, screen_width - 35, screen_height / 2 - 65, GREEN};

    
    InitWindow(screen_width, screen_height, "PONG PONG");
    SetTargetFPS(60);
    

    bool scored = false;
    double delayStartTime = 0;


    
    Texture2D bg = LoadTexture("img/bg.jpg");
    Texture2D ball_tx = LoadTexture("img/ball.png");
    Texture2D start = LoadTexture("img/start.png");
    Texture2D end = LoadTexture("img/end.png");



    // Check if the ball texture loaded successfully
    if (ball_tx.id==0 || bg.id==0)
    {
        printf("Failed to load texture!\n");
        return 1; // Exit if texture loading fails
    }

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
            case LOGO:
                // Update loading progress
                if (loadingProgress < 1.0f) {
                    loadingProgress += loadingSpeed;
                }else{
                    currentScreen=MENU;
                }

                // Begin drawing
                BeginDrawing();
                ClearBackground(BLACK);  // Clear the background

                // Draw "PONG PONG" in the center of the screen
                const char *title = "PONG PONG";
                int textWidth = MeasureText(title, 60);
                DrawText(title,screen_width/2-textWidth/2,screen_height/2-50,60,WHITE);

                // Draw developer names in the lower-right corner
                const char *credits = "Developers:\nMuhammad Abdullah Khan\nAli Hassan\nHashim Matloob";
                DrawText(credits, screen_width - 260, screen_height - 100, 20, GRAY);

                // Draw the loading bar below "PONG PONG"
                int barWidth = 400;
                int barHeight = 20;
                int barX = screen_width / 2 - barWidth / 2;
                int barY = screen_height / 2 + 50;

                // Background of the loading bar
                DrawRectangle(barX, barY, barWidth, barHeight, DARKGRAY);
                // Loading progress (green bar)
                DrawRectangle(barX, barY, barWidth * loadingProgress, barHeight, GREEN);
                // Border of the loading bar
                DrawRectangleLines(barX, barY, barWidth, barHeight, WHITE);

                // End drawing
                EndDrawing();
                break;

            case MENU:
                BeginDrawing();
                ClearBackground(WHITE);
                DrawTexture(start,0,0,WHITE);
                if (IsKeyDown(KEY_ENTER))currentScreen=GAMELOOP;
                EndDrawing();
                break;

            case GAMELOOP:
                gameLogic(&scored,&delayStartTime);

                BeginDrawing();

                // Background
                ClearBackground(WHITE);
                DrawTextureEx(bg, (Vector2){0,0},0,1,WHITE);
                
                // Draw paddles
                DrawRectangleRounded((Rectangle){player.x,player.y,player.width,player.height},0.7,10,player.color);
                DrawRectangleRounded((Rectangle){cpu.x,cpu.y,cpu.width,cpu.height},0.7,10,cpu.color);

                // Draw ball with texture
                float scale=30.0f/ball_tx.height;
                
                DrawTexturePro(
                    ball_tx,
                    (Rectangle){0,0,ball_tx.width,ball_tx.height},
                    (Rectangle){ball.x,ball.y,ball_tx.width*scale,ball_tx.height*scale},
                    (Vector2){(ball_tx.width * scale)/2,(ball_tx.height*scale)/2},
                    0.0f,
                    WHITE
                    );

                // Events
                playerMove(&player.y);
                cpuMove(&cpu.y);
                chkCollisionCpu(&cpu.width,&cpu.y);
                chkCollisionPlayer(&player.width,&player.y);

                // Scoring
                DrawText(TextFormat("Score: %d",cpu_score),200,80,30,BLACK);
                DrawText(TextFormat("Score: %d",player_score),screen_width-200,80,30,RED);
                EndDrawing();
                break;

            case GAMEOVER:
                BeginDrawing();
                ClearBackground(WHITE);
                DrawTexture(end,0,0,WHITE);

                //Score printing
                (cpu_score > player_score)?
                DrawText(TextFormat("Player One Win!!!"),screen_width/2-150,screen_height/3-100,40,WHITE):
                DrawText(TextFormat("Player Two Win!!!"),screen_width/2-150,screen_height/4-100,40,WHITE);

                DrawText(TextFormat("GAME\nOVER"),screen_width/2-55,screen_height/4,40,WHITE);
                
                if (IsKeyDown(KEY_SPACE))
                {
                    cpu_score = 0;
                    player_score = 0;
                    currentScreen = GAMELOOP;
                }
                EndDrawing();
                break;
        }
    }

    UnloadTexture(ball_tx);
    UnloadTexture(bg);
    UnloadTexture(start);
    UnloadTexture(end);
    
    CloseWindow();
    return 0;
}



// Paddle movement Functions
void playerMove(float *paddleY)
{
    if (IsKeyDown(KEY_DOWN))
    {
        if (!((*paddleY) + 130 >= screen_height))
            (*paddleY) += 10;
    }
    else if (IsKeyDown(KEY_UP))
    {
        if (!((*paddleY) <= 0))
            (*paddleY) -= 10;
    }
}
void cpuMove(float *paddleY)
{
    if (IsKeyDown(KEY_S))
    {
        if (!((*paddleY) + 130 >= screen_height))
            (*paddleY) += 10;
    }
    else if (IsKeyDown(KEY_W))
    {
        if (!((*paddleY) <= 0))
            (*paddleY) -= 10;
    }
}



// Paddle Collisions check function
void chkCollisionCpu(float *paddleWidth, float *paddleY)
{
    if (((ball.x) - (ball.rad) <= (*paddleWidth) + 10) && (ball.y >= (*paddleY)) && (ball.y <= (*paddleY) + 130))
    {
        ball.speedX *= -1;
        ball.x = (*paddleWidth) + 10 + ball.rad;
    }
}
void chkCollisionPlayer(float *paddleWidth, float *paddleY)
{
    if ((ball.x) + (ball.rad) >= screen_width - ((*paddleWidth) + 10) && (ball.y >= (*paddleY)) && (ball.y <= (*paddleY) + 130))
    {
        ball.speedX *= -1;
        ball.x = screen_width - ((*paddleWidth) + 10) - ball.rad;
    }
}



void gameLogic(bool *scored, double *delayStartTime)
{
    // Ball Movement
    if (!*scored)
    {
        ball.x += ball.speedX;
        ball.y += ball.speedY;
    }

    // Check for scoring
    if (ball.x + ball.rad >= screen_width)
    {
        cpu_score++;
        ball.speedX = 5;
        ball.speedY = 5;
        *scored = true; // Mark scored
        *delayStartTime = GetTime();
        ball.x = screen_width / 2;
        ball.y = screen_height / 2;

        ball.speedX *= GetRandomValue(0, 1) == 0 ? 1 : -1;
        ball.speedY *= GetRandomValue(0, 1) == 0 ? 1 : -1;
    }
    else if (ball.x - ball.rad <= 0)
    {
        player_score++;
        ball.x = screen_width / 2;
        ball.y = screen_height / 2;
        ball.speedX = 5;
        ball.speedY = 5;
        *scored = true; // Mark scored
        *delayStartTime = GetTime();
        ball.speedX *= GetRandomValue(0, 1) == 0 ? 1 : -1;
        ball.speedY *= GetRandomValue(0, 1) == 0 ? 1 : -1;
    }

    // Addition of delay after scoring
    if (*scored && GetTime() - *delayStartTime >= 1.0)
    { // 1-second delay
        *scored = false; // Resume game
    }

    // Reflection on x-axis boundaries
    if (ball.y + ball.rad >= screen_height || ball.y - ball.rad <= 0)
    {
        ball.speedY *= -1;
    }

    // End game after 5 scores
    if (player_score >= 5 || cpu_score >= 5)
    {
        currentScreen = GAMEOVER;
    }

    // Increase speed up to 10
    if (!(ball.speedX <= -10 || ball.speedX >= 10 || ball.speedY <= -10 || ball.speedY >= 10))
    {
        if (ball.speedY < 0)
            ball.speedY -= 0.01;
        else
            ball.speedY += 0.01;

        if (ball.speedX < 0)
            ball.speedX -= 0.01;
        else
            ball.speedX += 0.01;
    }
}