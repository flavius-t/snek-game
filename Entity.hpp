#include <utility>
#include <exception>


class OutOfBounds : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cannot move outside of map bounds";
    }
};


class Entity {
private:
    std::pair<int, int> pos;

public:
    Entity();
    Entity(int x, int y);
    std::pair<int, int> getPos() const;
    void setPos(const int x, const int y);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
};