//
// Created by dayub on 2026/3/11.
//
#include <iostream>
#include <cstring> // for the strlen() function
using namespace std;

void test1() {
    // 字符串是\0结尾的字符数组
    //char shirt_size = 'S'; // 存储的是ASCII码的83另一种写法
    //char shirt_size = "S"; // 错误  存储的是 S\0 字符数组
    // 拼接时第一个字符串中的\0会被第二个字符串的第一个字符代替
    cout << "I'd give my right arm to be" " a great violinist.\n";
    cout << "I'd give my right arm to be a great violinist.\n";
    cout << "I'd give my right arm to be"
    " a great violinist.\n";
}

void test2() {
    // sizeof 指出整个数组的长度
    // strlen 返回存储在数组中的字符串的长度，而不是数组本身长度 strlen只计算可见的字符，不把空字符计算在内
    // 数组长度不能短于strlen()+1
    const int SIZE = 15;
    char name1[SIZE]; // empty array
    char name2[SIZE] = "dayubetter"; // init array
    cout << "Hi,I'm " << name2;
    cout << "! What's your name?\n";
    cin>>name1;
    cout << "Well, "<<name1 << ",your name has ";
    cout << strlen(name1) << " letters and is stored\n";
    cout << "in an array of " << sizeof(name1) << "bytes.\n";
    cout << "Your initial is "<< name1[0] << ".\n";
    name2[3] = '\0'; // set to null character
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << endl;
}

void test3() {
    // cin 按照一个单词读取，例如输入hi dayu 会把hi作为第一个字符串存入数组
    // 读取一行 cin.getline(name,20) 把名字读入到一个包含20个元素的name数组中  不保存换行符，将换行符替换\0
    // cin.get(name.20)  保留回车在输入序列，不丢弃换行符
    // cin.get() 不带任何参数的调用读取下一个字符
    // cin.get(name.20).get()  处理换行符号
    // cin.getline(name1.20).getline(name2.20)  把输入中连续两行分别读入name数组
    char name[20];
    char dessert[20];

    cout << "Enter your name:\n";
    cin.get(name, 20).get(); // read string, newline
    cout << "Enter your favorite dessert:\n";
    cin.get(dessert, 20).get();
    cout << "I have some delicious "<< dessert;
    cout << " for you, " << name << "!\n";
}

int main() {
    //test1();
    //test2();
    test3();
}