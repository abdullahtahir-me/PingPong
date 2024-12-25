# PONG PONG Game Project
## Programming Fundamentals Project Report
### Fall 2024

-----------------------------------

### Submitted by:
Muhammad Abdullah Khan  
Ali Hassan

### Submitted to:
Dr. Nouman Shamim  
Department of Computer Science  
Pakistan Institute of Engineering and Applied Sciences (PIEAS)

-----------------------------------

## Table of Contents
1. [Executive Summary](#1-executive-summary)
2. [Introduction](#2-introduction)
3. [Project Overview](#3-project-overview)
4. [Game Development](#4-game-development)
5. [Implementation Details](#5-implementation-details)
6. [Testing and Results](#6-testing-and-results)
7. [Challenges and Solutions](#7-challenges-and-solutions)
8. [Conclusion](#8-conclusion)
9. [References](#9-references)
10. [Appendix](#10-appendix)

-----------------------------------

## 1. Executive Summary

Our project is a modern implementation of the classic PONG game, developed using C programming language and the Raylib graphics library. This project demonstrates our understanding of fundamental programming concepts learned during the first semester. We created a fully functional two-player game featuring multiple screens, score tracking, and progressive difficulty.

Key achievements:
- Successfully implemented a complete game loop
- Created interactive user interfaces
- Developed real-time collision detection
- Implemented score tracking system
- Added progressive difficulty mechanics

## 2. Introduction

### 2.1 Project Scope
For our first semester programming project, we chose to create a PONG game because it helped us learn:
- Basic game development concepts
- Graphics programming
- User input handling
- Collision detection
- State management

### 2.2 Development Environment
We used the following tools:
- Programming Language: C
- Graphics Library: Raylib
- IDE: Visual Studio Code
- Version Control: Git

## 3. Project Overview

### 3.1 Game Features
Our PONG game includes:
1. Two-player competitive gameplay
2. Multiple game screens:
   - Loading screen with progress bar
   - Main menu
   - Gameplay screen
   - Game over screen
3. Score tracking system
4. Progressive difficulty
5. Smooth animations

### 3.2 Game Screens

#### Loading Screen
![Loading Screen](image2)
The loading screen features:
- Game title "PONG PONG"
- Animated progress bar
- Developer credits

#### Main Menu
![Main Menu](image3)
The main menu includes:
- Start game prompt
- Exit game option
- Stylized background

#### Gameplay Screen
![Gameplay](image4)
During gameplay, players see:
- Two controllable paddles
- Moving ball
- Current score display
- Game court background

#### Game Over Screen
![Game Over](image1)
The game over screen shows:
- Winner announcement
- Replay option
- Exit option

## 4. Game Development

### 4.1 Core Data Structures

#### Player Structure
```c
typedef struct player
{
    float width;
    float height;
    float x;
    float y;
    Color color;
} Player;
```
This structure manages:
- Paddle dimensions
- Position coordinates
- Paddle color

#### Ball Structure
```c
typedef struct ball
{
    float x;
    float y;
    float rad;
    float speedX;
    float speedY;
    Color color;
} Ball;
```
The ball structure handles:
- Ball position
- Movement speed
- Ball size
- Ball color

### 4.2 Game States
```c
typedef enum GameScreen
{
    LOGO = 0,
    MENU,
    GAMELOOP,
    GAMEOVER
} GameScreen;
```
Game states control:
- Screen transitions
- Game flow
- User interactions

## 5. Implementation Details

### 5.1 Player Movement System
```c
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
```
This function:
- Handles keyboard input
- Updates paddle position
- Implements boundary checking
- Controls movement speed

### 5.2 Collision Detection
```c
void chkCollisionPlayer(float *paddleWidth, float *paddleY)
{
    if ((ball.x) + (ball.rad) >= screen_width - ((*paddleWidth) + 10) && 
        (ball.y >= (*paddleY)) && (ball.y <= (*paddleY) + 130))
    {
        ball.speedX *= -1;
        ball.x = screen_width - ((*paddleWidth) + 10) - ball.rad;
    }
}
```
Collision system features:
- Precise hit detection
- Ball direction reversal
- Position adjustment
- Boundary handling

### 5.3 Ball Physics and Movement
```c
void gameLogic(bool *scored, double *delayStartTime)
{
    if (!*scored)
    {
        ball.x += ball.speedX;
        ball.y += ball.speedY;
    }

    if (ball.y + ball.rad >= screen_height || ball.y - ball.rad <= 0)
    {
        ball.speedY *= -1;
    }

    // Speed increase logic
    if (!(ball.speedX <= -10 || ball.speedX >= 10 || 
        ball.speedY <= -10 || ball.speedY >= 10))
    {
        if (ball.speedY < 0)
            ball.speedY -= 0.01;
        else
            ball.speedY += 0.01;
    }
}
```
Ball physics implementation:
- Basic velocity calculations
- Wall bouncing
- Progressive speed increase
- Maximum speed cap

### 5.4 Scoring System
```c
if (ball.x + ball.rad >= screen_width)
{
    cpu_score++;
    ball.speedX = 5;
    ball.speedY = 5;
    *scored = true;
    *delayStartTime = GetTime();
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
}
```
Score tracking features:
- Point allocation
- Ball reset
- Speed reset
- Position reset
- Delay implementation

## 6. Testing and Results

### 6.1 Testing Methodology
We tested our game for:
1. Collision accuracy
2. Score counting
3. Speed progression
4. Input responsiveness
5. Screen transitions

### 6.2 Bug Fixes
Major fixes included:
- Ball sticking to paddles
- Score display glitches
- Screen transition issues
- Texture loading problems

## 7. Challenges and Solutions

### 7.1 Technical Challenges
1. Ball Physics
   - Challenge: Implementing realistic ball movement
   - Solution: Used velocity vectors and bounce mechanics

2. Collision Detection
   - Challenge: Accurate paddle hits
   - Solution: Improved boundary calculations

3. Game State Management
   - Challenge: Smooth transitions
   - Solution: Implemented state enum system

### 7.2 Learning Curve
1. Graphics Programming
   - Learning Raylib library
   - Understanding texture loading
   - Managing screen rendering

2. Game Development Concepts
   - Game loop implementation
   - State management
   - User input handling

## 8. Conclusion

### 8.1 Project Achievements
We successfully:
1. Created a functional game
2. Implemented all planned features
3. Learned valuable programming concepts
4. Gained practical experience

### 8.2 Future Improvements
Potential enhancements:
1. Sound effects
2. Power-up system
3. AI opponent
4. Enhanced graphics
5. Menu options

### 8.3 Learning Outcomes
This project helped us understand:
- C programming fundamentals
- Game development basics
- Problem-solving skills
- Project management

## 9. References

1. Raylib Documentation (https://www.raylib.com/cheatsheet/cheatsheet.html)
2. C Programming Language Reference
3. Game Programming Patterns
4. Online C Programming Resources

## 10. Appendix

### A. Complete Source Code
[Main game code provided in previous sections]

### B. Build Instructions
1. Install Raylib library
2. Clone project repository
3. Compile using provided makefile
4. Run the executable

### C. User Manual
1. Start game: Press Enter
2. Player 1 Controls: W/S keys
3. Player 2 Controls: Up/Down arrows
4. Exit game: ESC key
5. Replay: Space key (after game over)

-----------------------------------



