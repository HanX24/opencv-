#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define Maxsize 5//最多存放四个元素，有一个要

typedef int ELemType;
typedef struct {
	ELemType data[Maxsize];//循环队列，最多存储Maxsize-1个元素【需要留有一个元素判断队列是否满了】
	int front, near;//near入队，front出队
}SQueue;

//初始化
void InitQueue(SQueue &Q) {
	Q.front = 0;
	Q.near = 0;
}

//判断是否为空
bool isEmpty(SQueue  Q) {
	if (Q.front == Q.near) {//不需要为0，只需要两者数值相同就表示指向同一个结点。
		return true;
	}
	return false;
}

//入队过程
bool EnQueue(SQueue& Q, ELemType x) {//不需要返回  这个x输入的值 ，所以不用 引用&
	if ((Q.near + 1) % Maxsize == Q.front) {
		return false;//队列满了[就是为了整个圈，衔接起来】
	}
	Q.data[Q.near] = x;
	Q.near = (Q.near + 1) % Maxsize;//向后移动一位
	return true;
}

//出队过程
bool Dequeue(SQueue& Q, ELemType &x) {
	if (Q.front == Q.near) {
		return false;//队列为空
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % Maxsize;
	return true;
}

int main() {
	SQueue Q;
	bool ret;//接收返回值
	ELemType m;
	InitQueue(Q);
	ret = isEmpty(Q);
	if (ret) {
		printf("队列为空\n");
	}
	else
	{
		printf("队列不为空");
	}
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	EnQueue(Q, 5);
	ret=EnQueue(Q, 6);
	if (ret) {
		printf("入队成功\n");
	}
	else
	{
		printf("入队失败\n");
	}
	ret = EnQueue(Q, 7);//第五个元素，大于最大长度Maxsize
	if (ret) {
		printf("入队成功\n");
	}
	else
	{
		printf("入队失败\n");
	}

	//出队操作
	ret = Dequeue(Q, m);
	if (ret) {
		printf("出队成功\n");
		printf("%d", m);
	}
	else
	{
		printf("出队失败\n");
	}


	InitQueue(Q);
}