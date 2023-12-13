#include "Game.h"

#include "GameObject.h"
#include "Map.h"

#include "ECS.h"
#include "Components.h"

GameObject *supermen = nullptr;
GameObject *hero = nullptr;

SDL_Renderer* Game::g_renderer = nullptr;

Map *map = nullptr;

Manager manager;
auto& newPlayer = manager.addEntity();

Game::Game() {
    m_isRunning = false;
    m_window    = nullptr;
    m_count     = 0;
}
Game::~Game() {
    delete supermen;
    delete hero;
    delete map;

    Game::clean();
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

    supermen = new GameObject("assets/supermen.png", 0, 256, 1200, 1200);
    hero = new GameObject("assets/hero.png", 0, 0, 1296, 1296);
    map = new Map();

    newPlayer.addComponent<PositionComponent>();
    newPlayer.getComponent<PositionComponent>().setPos(500, 500);
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
    supermen->update();
    hero->update();

    manager.update();
    std::cout << newPlayer.getComponent<PositionComponent>().getX() << ", " << newPlayer.getComponent<PositionComponent>().getY() << std::endl;
}

void Game::render() {
    SDL_RenderClear(Game::g_renderer);
    map->drawMap();
    supermen->render();
    hero->render();
    SDL_RenderPresent(Game::g_renderer);
}

void Game::clean() {
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