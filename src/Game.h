//
// Created by leo on 10/06/23.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "DebugB2Draw.h"
#include "Enemy.h"
#include <vector>

class Game {
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1920, 1080), "projet cpp", sf::Style::Fullscreen);
    std::unique_ptr<Player> player = std::unique_ptr<Player>(new Player());
    std::unique_ptr<Enemy> enemy = std::unique_ptr<Enemy>(new Enemy(*player));
    DebugB2Draw debugB2Draw;

    sf::RectangleShape hBarBG = sf::RectangleShape(sf::Vector2f(500, 50));
    sf::RectangleShape hBar = sf::RectangleShape(sf::Vector2f(500, 50));;
    sf::Text coinsText;
    sf::Font font;

    void update(sf::Time deltaTime);

    void render();
    void renderUI();

    void handleEvent();

public:
    void run();

    Game();
};
