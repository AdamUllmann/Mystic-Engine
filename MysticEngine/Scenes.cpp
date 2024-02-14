#include "Scenes.h"

/*
!!!
All of your scene definitions should go down below. As a demo, you can use this template:
!!!
*/

void StartMiniGame() {

}

void LoadSceneData(std::map<const Scene, SceneData>& sceneData) {

    // Main Menu
    sceneData[Scene::MAIN_MENU] = {
        LoadTexture("assets/testRenders/fish.png"),
        {
            {
                Rectangle{ 0, 0, 0, 0 }, // defines click boxes
                Scene::MAIN_MENU,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            }
        },
        LoadMusicStream("assets/sounds/weird synth dums.mp3")
        // add other assets and data for scene 1, such as sound effects, animations, etc.
    };

    // Scene 1
    sceneData[Scene::SCENE_1] = {
        LoadTexture("assets/testRenders/first.png"),
        {
            {
                Rectangle{ 0.1f, 0.1f, 0.7f, 0.7f }, // defines click boxes
                Scene::SCENE_2,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            }
        }
        // add other assets and data for scene 1, such as sound effects, animations, etc.
    };

    // Scene 2
    sceneData[Scene::SCENE_2] = {
        LoadTexture("assets/testRenders/03.png"),
        {
            {
                Rectangle{ 0.1f, 0.2f, 0.35f, 0.5f }, // defines click boxes
                Scene::SCENE_7,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            },
            {
                Rectangle{ 0.5f, 0.2f, 0.35f, 0.5f }, // defines click boxes
                Scene::SCENE_8,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            }
        }
        // add other assets and data for scene 2, such as sound effects, animations, etc.
    };

    // Scene 3
    sceneData[Scene::SCENE_3] = {
        LoadTexture("assets/testRenders/03.png"),
        {
            {
                Rectangle{ 0.15f, 0.2f, 0.35f, 0.6f }, // defines click boxes
                Scene::MAIN_MENU,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            }
        }
        // add other assets and data for scene 2, such as sound effects, animations, etc.
    };

    // Scene 4
    sceneData[Scene::SCENE_4] = {
        LoadTexture("assets/testRenders/04.png"),
        {
            {
                Rectangle{ 0.3f, 0.2f, 0.35f, 0.6f }, // defines click boxes
                Scene::SCENE_4,                         //  clicking here leads to a target scene
                LoadSound("assets/sounds/lags.mp3"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            },
            {
                Rectangle{ 0.0f, 0.0f, 1.0f, 1.0f }, // defines click boxes
                Scene::SCENE_2,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            }
        }
        // add other assets and data for scene 2, such as sound effects, animations, etc.
    };

    // Scene 5
    sceneData[Scene::SCENE_5] = {
        LoadTexture("assets/testRenders/05.png"),
        {
            {
                Rectangle{ 0.3f, 0.3f, 0.3f, 0.34f }, // defines click boxes
                Scene::SCENE_4,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            },
            {
                Rectangle{ 0.0f, 0.0f, 1.0f , 1.0f }, // defines click boxes
                Scene::SCENE_8,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            }
        }
        // add other assets and data for scene 2, such as sound effects, animations, etc.
    };

    // Scene 6
    sceneData[Scene::SCENE_6] = {
        LoadTexture("assets/testRenders/03.png"),
        {
            {
                Rectangle{ 0.15f, 0.2f, 0.35f, 0.6f }, // defines click boxes
                Scene::MAIN_MENU,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            }
        }
        // add other assets and data for scene 2, such as sound effects, animations, etc.
    };

    // Scene 7
    sceneData[Scene::SCENE_7] = {
        LoadTexture("assets/testRenders/07.png"),
        {
            {
                Rectangle{ 0.36f, 0.36f, 0.29f, 0.34f }, // defines click boxes
                Scene::SCENE_7,                         //  clicking here leads to a target scene
                LoadSound("assets/sounds/fillin"),  //  clicking here plays a sound
                false,                                  //  is it a minigame scene?
            },
            {
                Rectangle{ 0.0f, 0.0f , 1.0f, 1.0f }, // defines click boxes
                Scene::SCENE_2,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            }
        }
        // add other assets and data for scene 2, such as sound effects, animations, etc.
    };

    // Scene 8
    sceneData[Scene::SCENE_8] = {
        LoadTexture("assets/testRenders/08.png"),
        {
            {
                Rectangle{ 0.3f, 0.3f, 0.3f, 0.34f }, // defines click boxes
                Scene::SCENE_8,                         //  clicking here leads to a target scene
                LoadSound("assets/sounds/spain.mp3"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            },
            {
                Rectangle{ 0.0f, 0.0f , 1.0f, 1.0f }, // defines click boxes
                Scene::SCENE_5,                         //  clicking here leads to a target scene
                LoadSound("path/to/sound_effect.wav"),  //  clicking here plays a sound
                false                                   //  is it a minigame scene?
            }
        }
        // add other assets and data for scene 2, such as sound effects, animations, etc.
    };
}