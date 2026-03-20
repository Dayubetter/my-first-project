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
// 全局参数
bool gameOver;
const int width = 25;  // 地图宽
const int height = 15; // 高度
vector<Point> snake;
Point food;
string dir;
int score;

// 随机生成食物
void GenerateFood() {
    food.x = rand() % width;
    food.y = rand() % height;
}

// 初始化
void Setup() {
    gameOver = false;
    dir = "right";
    snake.clear();
    snake.push_back(Point(width / 2, height / 2));
    score = 0;
    GenerateFood();
}

// 绘制界面
void Draw() {
    system("cls");

    // 上边框
    for (int i = 0; i < width + 2; ++i) {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j == 0) {
                cout << "#";
            }
            bool isBody = false;
            for (auto& p : snake) {
                if (p.x == j && p.y == i) {
                    cout << "O";
                    isBody = true;
                    break;
                }
            }
            if (!isBody) {
                if (i == food.y && j == food.x) {
                    cout << "F";
                }else {
                    cout << " ";
                }
            }
            if (j == width - 1) {
                cout << "#";
            }
        }
        cout << endl;
    }
    // 下边框
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    cout << " Score: " << score << endl;
    cout << " direction key ctrl! X exit" << endl;
}


int main() {
    Setup();
    Draw();
    return 0;
}