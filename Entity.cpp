#include "Entity.hpp"
#include "Constants.hpp"


Entity::Entity() : pos(std::make_pair(0, 0)) {}


Entity::Entity(int x, int y) : pos(std::make_pair(x, y)) {}


std::pair<int, int> Entity::getPos() const {
    return this->pos;
}


void Entity::setPos(const int x, const int y) {
    if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) {
        throw OutOfBounds();
    }

    this->pos = std::make_pair(x, y);
}


void Entity::moveUp() {
    if (pos.second - 1 < 0) {
        throw OutOfBounds();
    }

    this->pos.second--;
}


void Entity::moveDown() {
    if (pos.second >= MAP_HEIGHT - 1) {
        throw OutOfBounds();
    }

    this->pos.second++;
}


void Entity::moveLeft() {
    if (pos.first - 1 < 0) {
        throw OutOfBounds();
    }

    this->pos.first--;
}


void Entity::moveRight() {
    if (pos.first >= MAP_WIDTH - 1) {
        throw OutOfBounds();
    }

    this->pos.first++;
}