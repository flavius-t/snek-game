#include <gtest/gtest.h>
#include "../Entity.hpp"
#include "../Constants.hpp"


TEST(Entity, DefaultConstructor) {
    Entity e;
    EXPECT_EQ(e.getPos(), std::make_pair(0, 0));
}

TEST(Entity, ParamConstructor) {
    Entity e(1, 2);
    EXPECT_EQ(e.getPos(), std::make_pair(1, 2));
}

TEST(Entity, SetPos) {
    Entity e;
    e.setPos(MAP_WIDTH - 1, MAP_HEIGHT - 1);
    EXPECT_EQ(e.getPos(), std::make_pair(MAP_WIDTH - 1, MAP_HEIGHT - 1));
    e.setPos(0, 0);
    EXPECT_EQ(e.getPos(), std::make_pair(0, 0));
    e.setPos(10, 20);
    EXPECT_EQ(e.getPos(), std::make_pair(10, 20));
}

TEST(Entity, SetPosThrows) {
    Entity e;
    EXPECT_THROW(e.setPos(-1, 0), OutOfBounds);
    EXPECT_THROW(e.setPos(0, -1), OutOfBounds);
    EXPECT_THROW(e.setPos(MAP_WIDTH, 0), OutOfBounds);
    EXPECT_THROW(e.setPos(0, MAP_HEIGHT), OutOfBounds);
}

TEST(Entity, MoveUp) {
    Entity e(0, MAP_HEIGHT - 1);
    for (int i = MAP_HEIGHT - 1; i > 0; i--) {
        e.moveUp();
        EXPECT_EQ(e.getPos(), std::make_pair(0, i - 1));
    }
}

TEST(Entity, MoveUpThrows) {
    Entity e(0, 0);
    EXPECT_THROW(e.moveUp(), OutOfBounds);
}

TEST(Entity, MoveDown) {
    Entity e(0, 0);
    for (int i = 0; i < MAP_HEIGHT - 1; i++) {
        e.moveDown();
        EXPECT_EQ(e.getPos(), std::make_pair(0, i + 1));
    }
}

TEST(Entity, MoveDownThrows) {
    Entity e(0, MAP_HEIGHT - 1);
    EXPECT_THROW(e.moveDown(), OutOfBounds);
}

TEST(Entity, MoveLeft) {
    Entity e(MAP_WIDTH - 1, 0);
    for (int i = MAP_WIDTH - 1; i > 0; i--) {
        e.moveLeft();
        EXPECT_EQ(e.getPos(), std::make_pair(i - 1, 0));
    }
}

TEST(Entity, MoveLeftThrows) {
    Entity e(0, 0);
    EXPECT_THROW(e.moveLeft(), OutOfBounds);
}

TEST(Entity, MoveRight) {
    Entity e(0, 0);
    for (int i = 0; i < MAP_WIDTH - 1; i++) {
        e.moveRight();
        EXPECT_EQ(e.getPos(), std::make_pair(i + 1, 0));
    }
}

TEST(Entity, MoveRightThrows) {
    Entity e(MAP_WIDTH - 1, 0);
    EXPECT_THROW(e.moveRight(), OutOfBounds);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}