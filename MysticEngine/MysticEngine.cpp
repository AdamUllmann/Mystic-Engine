// MystiqueEngine.cpp
// By Adam Ullmann

#include <iostream>
#include <string>
#include <map>
//#include <vector>     //included in Scenes.h
//#include "raylib.h"   //included in Scenes.h

#include "Scenes.h"

// a function to handle scene transitions
void ChangeScene(Scene& currentScene, Scene nextScene) {
    currentScene = nextScene;
}

void ResizeTextures(std::map<const Scene, SceneData>& datamap, int newWidth, int newHeight) {
    for (std::pair<const Scene, SceneData>& sceneDataPair : datamap) {      // for each scene in the map 
        SceneData& data = sceneDataPair.second; // get the scene data from the pair

        Image img = LoadImageFromTexture(data.image);   // background texture resize
        ImageResize(&img, newWidth, newHeight);
        UnloadTexture(data.image);
        data.image = LoadTextureFromImage(img);
        UnloadImage(img);

        // updates click box positions and scales based on the new window size
        for (ClickBox& clickBox : data.clickBoxes) {
            clickBox.bounds.x = clickBox.originalBounds.x * static_cast<float>(newWidth);
            clickBox.bounds.y = clickBox.originalBounds.y * static_cast<float>(newHeight);
            clickBox.bounds.width = clickBox.originalBounds.width * static_cast<float>(newWidth);
            clickBox.bounds.height = clickBox.originalBounds.height * static_cast<float>(newHeight);
        }

        // updates sprite positions and scales based on the new window size
        for (auto& sprite : data.sprites) {
            sprite.position.x *= static_cast<float>(newWidth);
            sprite.position.y *= static_cast<float>(newHeight);
            // add scaling code
        }
    }
}


int main(void)
{
    // initialization
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "MANHOLE");
    ToggleFullscreen();
    InitAudioDevice();
    SetTargetFPS(60);
    SetMouseCursor(3);
    Image img = LoadImage("assets/ICON.png");
    SetWindowIcon(img);
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    Scene currentScene = Scene::MAIN_MENU;

    // load data for other scenes here
    std::map<const Scene, SceneData> sceneData;     // all scene data is loaded into a map
    LoadSceneData(sceneData);

    ResizeTextures(sceneData, screenWidth, screenHeight);           // initial scaling

    Music music = LoadMusicStream("assets/sounds/weird synth dums.mp3");
    //UpdateMusicStream(music);
    PlayMusicStream(music);


    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        UpdateMusicStream(music);

        // input handling
        if (currentScene == Scene::MAIN_MENU) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {  // handle clicks in the main menu
                // implement logic to check if the user clicked on a button to start the game


                ChangeScene(currentScene, Scene::SCENE_1);
            }
        }
        else {

            // handle clicks and interactions for other scenes
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                SceneData& currentSceneData = sceneData[currentScene];
                for (const ClickBox& clickBox : currentSceneData.clickBoxes) {
                    if (CheckCollisionPointRec(mousePos, clickBox.bounds)) {


                        // perform actions related to the clicked box in the current scene
                        // playSound(currentSceneData.sound);
                        // changeScene(currentScene, nextScene);
                        // trigger animations or open minigames here

                        PlaySound(clickBox.soundEffect); // play sound effect, if defined for this click box

                        if (clickBox.isMiniGameStart) { // start the mini-game, if defined for this click box
                            StartMiniGame();
                        }
                        //DrawTexture(clickBox.imageEffect, 0, 0, WHITE);


                        ChangeScene(currentScene, clickBox.targetScene); // change scene to the target scene defined for this click box

                        break; // stop checking if the mouse is clicked in multiple click boxes


                    }
                }
            }
        }

        if (IsKeyPressed(KEY_SPACE)) {
            screenWidth = 1280;
            screenHeight = 720;
            ToggleFullscreen();
            SetWindowSize(screenWidth, screenHeight);
            SetWindowPosition(25, 45);
            ResizeTextures(sceneData, screenWidth, screenHeight);
        }

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);

        // draws appropriate scene based on the currentScene value
        if (currentScene != Scene::MAIN_MENU) {
            SceneData& currentSceneData = sceneData[currentScene];
            DrawTexture(currentSceneData.image, 0, 0, WHITE);

            for (const Sprite& sprite : currentSceneData.sprites) { // draw sprites in the current scene
                DrawTexture(sprite.texture, (int)sprite.position.x, (int)sprite.position.y, WHITE);
            }
        }

        else {
            SceneData& currentSceneData = sceneData[currentScene];                                  //DELETE THIS
            DrawTexture(currentSceneData.image, 0, 0, WHITE);
            for (const Sprite& sprite : currentSceneData.sprites) {
                DrawTexture(sprite.texture, (int)sprite.position.x, (int)sprite.position.y, WHITE);
            }
        }

        // misc ui elements go here

        for (const ClickBox& clickBox : sceneData[currentScene].clickBoxes) { // debugging use. to highlight bounds of click boxes
            DrawRectangleRec(clickBox.bounds, Color{ 250, 0, 0, 25 });       // debugging use. to highlight bounds of click boxes
        }

        EndDrawing();
    }
    for (auto& scene : sceneData) {             // unload & deallocate
        UnloadTexture(scene.second.image);
        // unload other scene-specific assets here
    }

    // de-initialization & end
    CloseWindow();

    return 0;
}