#include <iostream>
using namespace std;
#include "fun.h"

// 餐馆信息结构体
struct Restaurant {
    int id;
    char name[50];
    char type[20];
    float price;
    float rating;
    int total_tables;
    int remaining_tables;
};

// 手动实现顺序表
struct SeqList {
    Restaurant *data;  // 指向动态分配的数组
    int length;        // 当前存储的记录数
    int capacity;      // 顺序表最大容量
};

int main() {
    showmenu();
    SeqList *restaurantList = new SeqList;
    InitList(*restaurantList);
    LoadFromFile(*restaurantList);
    ShowAll(*restaurantList);
    system("pause");
    return 0;
}
