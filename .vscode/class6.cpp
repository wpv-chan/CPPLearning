#include <bits/stdc++.h>
using namespace std;

/*
 * 结构体的定义
 *   是一种抽象的数据类型
 *
 * struct <结构体的类型名> {
 *     <成员列表>
 * }
 *
 * 同类型的结构体可以可以相互赋值（初始化）
 *
 * 注意：
 * 1. 不能将结构体变量作为一个整体进行输入输出
 * 2. 结构体变量可以用作函数参数，属于按值传递
 * 3. 函数可以返回一个结构体变量
 *
 * */

//注意
struct student{
    string name;
};

student *ps;
student John;

ps = &John;//John.name <=> ps->name <=> (*ps).name

/*
 * 当指针作为函数参数的时候，访问成员变量应该使用->代替. 来实现
 * */

/*
 * 链表的引入
 *    数组空间是连续的
 * 存在的问题
 * 1. 实际应用无法确定数组的大小
 * 2. 定义过大会造成空间浪费
 * */

#define LEN sizeof(NODE)

typedef struct node {
    int data;//数据部分
    node *next;//指针部分
}NODE;

//创建带头结点的链表
NODE *initlist() {
    NODE *head;
    head = new NODE;
    head -> next = NULL;
};

//创建无序链表
NODE *create() {
    NODE *p1, *p2, *head;
    int input;
    p2 = head = initlist();
    cin>>input;

    while(input != -1) {
        p1 = new NODE;
        p1 -> data = input;
        p2 -> next = p1;
        p2 = p1;

        cin>>input;
    }
    p2 -> next = NULL;
    return(head);
}

//遍历链表
void print (NODE *head) {
    NODE *p;
    p = head -> next;
    if(p != NULL) {
        while(p != NULL) {
            cout<<setw(5)<<p -> data;
            p = p -> next;
        }
    }
}

//链表查询
NODE *search (NODE *head, int x) {
    NODE *p;
    p = head -> next;
    while(p != NULL) {
        if(p -> data == x) {
            return p;
        }
        p = p -> next;
    }
    return NULL;
}

//链表插入（有序链表）
NODE *insert (NODE *head, NODE *s) {
    NODE* p;
    p = head;
    while(p -> next != NULL && p -> next -> data < s -> data)
        p = p -> next;
    s -> next = p -> next;
    p -> next = s;
    return head;
}

//创建有序链表
NODE *create_sort() {
    NODE* p, *head = NULL;
    int a;
    head = initlist();
    cin>>a;
    while(a != -1) {
        p = new NODE;
        p -> data = a;
        head = insert(head, p);
        cin>>a;
    }
    return head;
}

//结点的删除
NODE *delete_one_node(NODE *head, int num) {
    NODE* p, *temp;
    p = head;
    while(p -> next != NULL && p -> next -> data != num)
        p = p -> next;
    temp = p -> next;
    if(p -> next != NULL) {
        p -> next = temp -> next;
        delete temp;
    }
    else cout<<"NOT found";
    return head;
}

//链表的释放
void free_list(NODE *head) {
    NODE *p;
    while(head) {
        p=head;//p指向头节点
        head=head->next;//head指向下一个节点
        delete p;//删除p
    }
}