//
// Created by dayub on 2026/3/28.
//
#include <iostream>
using namespace std;
// public：共有的访问权限，在类外可以通过对象直接访问公有成员
// protected:保护的访问权限，在本类中和派生类中可以访问，在类外不能通过对象直接访问
// private：私有的访问权限，在本类之外不能访问，类定义中可以访问
// class定义的默认权限为私有
// public的成员函数也可以称为接口，该类提供给外界使用的路径，在类外可以直接通过对象访问

// 如果在头文件中采用成员函数声明和定义分离的形式，在类外部完成成员函数的实现，就会陷入多文件联合重定义错误
// 加inline==写在类的内部，声明实现文件分离

// 数据成员初始化的顺序与其声明的顺序保持一致，与它们在初始化列表中的顺序无关（但初始化列表一般保持与数据成员声明的顺序一致）
class Point {
public:
    Point() {}
    Point::Point(int x, int y) : x(x), y(y) {}
    ~Point() {}
    // 默认拷贝构造
    Point(const Point& rhs)
    :x(rhs.x)
    ,y(rhs.y)
    {}
    // 赋值运算符
    Point& operator=(const Point& rhs) {
        x = rhs.x;
        y = rhs.y;
    }

private:
    int x;
    int y;
};

void test0() {
    Point pt(10,8);
}

int main() {

}