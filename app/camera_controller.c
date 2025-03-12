#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>

// Camera structure
typedef struct {
    float x, y, z;   // Position
    float pitch, yaw; // Rotation (in degrees)
    float speed;      // Movement speed
} Camera;

void handle_input(Camera* camera, float deltaTime) {
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    float moveSpeed = camera->speed * deltaTime;

    // Convert yaw angle to radians
    float yawRad = camera->yaw * (M_PI / 180.0f);

    // Forward and backward movement
    if (keystate[SDL_SCANCODE_W]) {
        camera->x += cos(yawRad) * moveSpeed;
        camera->z += sin(yawRad) * moveSpeed;
    }
    if (keystate[SDL_SCANCODE_S]) {
        camera->x -= cos(yawRad) * moveSpeed;
        camera->z -= sin(yawRad) * moveSpeed;
    }

    // Left and right strafing
    if (keystate[SDL_SCANCODE_A]) {
        camera->x -= sin(yawRad) * moveSpeed;
        camera->z += cos(yawRad) * moveSpeed;
    }
    if (keystate[SDL_SCANCODE_D]) {
        camera->x += sin(yawRad) * moveSpeed;
        camera->z -= cos(yawRad) * moveSpeed;
    }
}

void handle_mouse(Camera* camera, SDL_Event* event) {
    if (event->type == SDL_MOUSEMOTION) {
        camera->yaw += event->motion.xrel * 0.1f;  // Adjust sensitivity as needed
        camera->pitch -= event->motion.yrel * 0.1f;
        
        // Limit pitch to prevent flipping
        if (camera->pitch > 89.0f) camera->pitch = 89.0f;
        if (camera->pitch < -89.0f) camera->pitch = -89.0f;
    }
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Camera Controller", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_SetRelativeMouseMode(SDL_TRUE); // Capture mouse for FPS-style movement

    Camera camera = {0, 0, 0, 0, 0, 5.0f};
    int running = 1;
    Uint32 lastTime = SDL_GetTicks();
    
    while (running) {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;
        
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;
            handle_mouse(&camera, &event);
        }
        
        handle_input(&camera, deltaTime);
        
        printf("Camera Position: (%.2f, %.2f, %.2f) | Rotation: (Pitch: %.2f, Yaw: %.2f)\n", camera.x, camera.y, camera.z, camera.pitch, camera.yaw);
        SDL_Delay(16); // Simulate frame time (~60 FPS)
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
