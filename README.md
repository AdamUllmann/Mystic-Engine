# Mystic Engine

Mystic Engine is a lightweight and efficient framework designed for game developers to create click-based adventure games with ease. It provides a simple and intuitive way to handle scene transitions, manage assets, and handle user interactions. The framework is versatile and can be easily extended to create a game-making application with a user interface that translates down to game code. The Engine was heavily inspired by the classic PC games: Myst, Manhole, and Riven.

## Framework Features
- **Click-Based Interaction**: Define clickable areas (click boxes) within scenes to trigger actions, sound effects, and scene transitions.
- **Dynamic Textures**: Resize textures dynamically based on the window size for responsive design.
- **Mini-Game Support**: Define click boxes to start mini-games within scenes.
- **Audio Support**: Load and play background music and sound effects for a crafted experience.

## Getting Started
### 1. Define Scenes
   - Use the `Scene` enum in `Scenes.h` to define scenes for your game. Add more scenes as needed.
### 2. Load Scene Data
   - In `Scenes.cpp`, populate the map of scenes in the `LoadSceneData` function to load data for each scene. You can load assets, sounds, and sprites.
### 3. Customize Scenes
   - Customize the scenes by adding textures, click boxes, sounds etc in the `SceneData` struct.
### 4. Run Your Game
   - Run the game loop in `MysticEngine.cpp` to start your game.

## Project Direction
The Mystic Engine is designed with extensibility in mind. In the future, the framework can be evolved into a game-making application with a user interface for easier game development. This transformation would allow developers to visually design scenes, customize interactions, and manage assets without writing code directly.

Feel free to contribute, suggest improvements, or extend the framework to meet your game development needs.
