#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>

class Game {
private:
    bool m_isRunning;
    SDL_Window *m_window;
    int m_count;

public:
    Game();
    ~Game();

    static SDL_Renderer *g_renderer;

    void init(std::string title, int x, int y, int w, int h, bool isFullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();
};
