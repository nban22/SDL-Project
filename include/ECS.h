#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;



inline std::size_t getComponentTypeID() {
    static std::size_t lastID = 0;
    return lastID++;
}

template <typename T>
inline size_t getComponentTypeID() noexcept {
    static size_t typeID = getComponentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

class Component {
public:
    Entity* m_entity;
    
    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual ~Component() {}
};

class Entity {
private:
    bool m_active = true;
    std::vector<std::unique_ptr<Component>> m_components;
    std::array<Component*, maxComponents> m_componentArray;
    std::bitset<maxComponents> m_componentBitset;

public:
    void update() {
        for (auto& c : m_components) c->update();
    }
    void draw() {
        for (auto& c : m_components) c->draw();
    }
    bool isActive() {
        return m_active;
    }
    void destroy() {
        m_active = false;
    }

    template <typename T>
    bool hasComponent() const {
        return m_componentBitset[getComponentTypeID<T>()];
    }

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... mAgrs) {
        T* c = new T(std::forward<TArgs>(mAgrs)...);
        c->m_entity = this;
        std::unique_ptr<Component> uPtr { c };
        m_components.emplace_back(std::move(uPtr));

        m_componentArray[getComponentTypeID<T>()] = c;
        m_componentBitset[getComponentTypeID<T>()] = true;

        c->init();
        return *c;
    }

    template <typename T>
    T& getComponent() const {
        auto ptr = m_componentArray[getComponentTypeID<T>()];
        return *static_cast<T*>(ptr);
    }
};

class Manager {
private:
    std::vector<std::unique_ptr<Entity>> m_entities;

public:
    void update() {
        for (auto& e : m_entities) e->update();
    }
    void draw() {
        for (auto& e : m_entities) e->draw();
    }
    void refresh() {
        m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(),
            [](const std::unique_ptr<Entity>& mEntity) 
            {
                return !mEntity->isActive();
            }
        ), m_entities.end());
    }
    
    Entity& addEntity() {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr { e };
        m_entities.emplace_back(std::move(uPtr));
        return *e;
    }
};
