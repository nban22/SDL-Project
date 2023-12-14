#include "Game.h"

#include "Map.h"

#include "ECS/Components.h"
#include "Vector2D.h"

SDL_Renderer* Game::g_renderer = nullptr; //static

Map *map = nullptr;

SDL_Event Game::g_event;

Manager manager;
auto& superman = manager.addEntity();

Game::Game() {
    m_isRunning = false;
    m_window    = nullptr;
    m_count     = 0;
}
Game::~Game() {

}

void Game::init(std::string title, int x, int y, int w, int h, bool isFullscreen) {
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
    Game::g_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Game::g_renderer == nullptr) {
        SDL_DestroyWindow(m_window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }
    m_isRunning = true;
    SDL_SetRenderDrawColor(Game::g_renderer, 50, 168, 158, 255);

    map = new Map();

    superman.addComponent<TransformComponent>();
    superman.addComponent<SpriteComponent>("assets/superman.png");
    superman.addComponent<KeyboardController>();
}

void Game::handleEvents() {
    SDL_PollEvent(&Game::g_event);
    switch (Game::g_event.type) {
    case SDL_QUIT:
        m_isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update() {
    manager.refresh();
    manager.update();
}

void Game::render() {
    SDL_RenderClear(Game::g_renderer);
    map->drawMap();
    manager.draw();
    SDL_RenderPresent(Game::g_renderer);
}

void Game::clean() {
    // delete map;
    // delete Game::g_renderer;

    if (m_window) {
        SDL_DestroyWindow(m_window);
    }
    if (Game::g_renderer) {
        SDL_DestroyRenderer(Game::g_renderer);
    }
    SDL_Quit();
}

bool Game::running() {
    return m_isRunning;
}