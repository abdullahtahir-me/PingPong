# PONGPONG: A Modern Take on the Classic PONG Game

## Overview

PONGPONG is a two-player competitive game developed using the C programming language and the Raylib graphics library. This project demonstrates fundamental programming concepts such as collision detection, user input handling, and game state management.

Key achievements:
- Successfully implemented a complete game loop.
- Created multiple screens: loading, starting, and game over screens.
- Developed real-time collision detection and a scoring system.
- Introduced progressive difficulty mechanics.

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Tools Used](#tools-used)
4. [Game Screens](#game-screens)
5. [Implementation Details](#implementation-details)
6. [User Manual](#user-manual)

## Introduction

This project was developed as part of the Computer Fundamentals and Programming (CFP-101) course. The goal was to create a fully functional game that applies the concepts learned in the first semester, such as:
- Basic game development
- Graphics programming
- State management

## Features

1. Two-player competitive gameplay.
2. Multiple game screens:
   - Loading screen with an animated progress bar.
   - Main menu with start and exit options.
   - Gameplay screen with score tracking.
   - Game over screen with winner display and retry option.
3. Smooth animations and retro-style design.
4. Progressive difficulty mechanics.

## Tools Used

- **Programming Language:** C
- **Graphics Library:** Raylib
- **IDE:** Visual Studio Code
- **Version Control:** Git

## Game Screens

### Loading Screen
- Displays the game title: "PONGPONG".
- Includes an animated progress bar and developer credits.

### Main Menu
- Options to start or exit the game.
- Retro-style background.

### Gameplay Screen
- Two controllable paddles and a moving ball.
- Score display for both players.
- Tennis court background.

### Game Over Screen
- Declares the winner among the two players.
- Options to retry or exit the game.

## Implementation Details

### Core Structures
- **Paddle Structure:** Manages paddle dimensions, coordinates, and color.
- **Ball Structure:** Handles ball position, size, speed, and color.
- **Game States:** Controls various game screens.

### Functions
1. **Paddle Movement Function**
   - Handles keyboard input and updates paddle positions.
   - Implements boundary checking and speed control.

2. **Collision Detection Function**
   - Detects collisions and reverses ball direction.
   - Handles boundary interactions.

3. **Ball Physics and Scoring**
   - Implements ball movement and scoring system.
   - Increases ball velocity and ends the game after a score of 5.

## User Manual

- **Start Game:** Press `Enter`.
- **Player 1 Controls:** `W/S` keys.
- **Player 2 Controls:** `Up/Down` arrow keys.
- **Exit Game:** Press `ESC`.
- **Replay Game:** Press `Space` after the game over screen.

---

Developed by:  
Muhammad Abdullah Khan & Ali Hassan  
Under the guidance of: Dr. Nouman Shamim, DCIS PIEAS  
Fall 2024
