//
// Created by dayub on 2026/3/21.
//
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;

    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};

void move(vector<Point>& snake, string direction, Point foodPosition) {
    // 1. 获取当前蛇头
    Point head = snake[0];
    int newX = head.x;
    int newY = head.y;

    // 2. 根据方向计算新蛇头
    if (direction == "left") {
        newX--;
    }else if (direction == "right") {
        newX++;
    }else if (direction == "up") {
        newY++;
    }else if (direction == "down") {
        newY--;
    }

    // 3.把新蛇头插入最前面
    snake.insert(snake.begin(), Point(newX, newY));

    // 4.如果没吃到食物，删除尾部
    bool eatFood = (newX == foodPosition.x && newY == foodPosition.y);
    if (!eatFood) {
        snake.pop_back();
    }
}