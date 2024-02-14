#include <vector>
#include <map>

#include "raylib.h"

enum class Scene {
    MAIN_MENU,
    SCENE_1,
    SCENE_2,
    SCENE_3,
    SCENE_4,
    SCENE_5,
    SCENE_6,
    SCENE_7,
    SCENE_8,
    SCENE_9,
    SCENE_10,
    SCENE_11,
    SCENE_12
    // add more scenes as needed
    // MINIGAME_1,
    // MINIGAME_2
};


// a struct to hold all scene data (assets, click boxes, etc.)
struct ClickBox {
    Rectangle originalBounds;
    Scene targetScene;
    Sound soundEffect;
    bool isMiniGameStart;
    Rectangle bounds;
};

// a struct to represent a sprite
struct Sprite {
    Texture2D texture;
    Vector2 position;       // vector containing x and y coordinates
    // other things like animations can go here
};

struct SceneData {
    Texture2D image = LoadTexture("assets/testRenders/fish.png");
    std::vector<ClickBox> clickBoxes;
    Music song = LoadMusicStream("assets/sounds/weird synth dums.mp3");
    std::vector<Sprite> sprites;
    // more scene-specific data as needed
};

void StartMiniGame();
void LoadSceneData(std::map<const Scene, SceneData> & sceneData);
