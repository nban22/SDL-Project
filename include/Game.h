#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>
#include <iostream>

class Game
{
private:
    bool m_isRunning;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    int m_count;

    SDL_Texture* m_texture;
    
public:
    Game();
    ~Game();

    void init(std::string title, int x, int y, int w, int h, bool isFullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running();
};

Game::Game() {
    m_isRunning = false;
    m_window = nullptr;
    m_renderer = nullptr;
    m_count = 0;
}
Game::~Game() {
    Game::clean();
}

void Game::init(std::string title, int x, int y, int w, int h, bool isFullscreen)
{
    int flags = SDL_WINDOW_SHOWN;
    if (isFullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }
    m_window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
    if (m_window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (m_renderer == nullptr) {
        SDL_DestroyWindow(m_window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 234, 255);
    m_isRunning = true;

    SDL_Surface* tmpSurface = IMG_Load("../assets/hero.png");
    SDL_Texture* m_texture = SDL_CreateTextureFromSurface(m_renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            m_isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {

}

void Game::render() {
    SDL_RenderClear(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 222, 111, 234, 255);
    SDL_RenderPresent(m_renderer);
}

void Game::clean() {
    if (m_window) {
        SDL_DestroyWindow(m_window);
    }
    if (m_renderer) {
        SDL_DestroyRenderer(m_renderer);
    }
    SDL_Quit();
}

bool Game::running() {
    return m_isRunning;
}