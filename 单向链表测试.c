#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"
/*
typedef void LinkList;
typedef struct _LinkListNode
{
	struct _LinkListNode * next;
}LinkListNode;

int linklistGreate(LinkList **list); ok
int linklistDestroy(LinkList **list); ok
int linklistClear(LinkList **list); ok
int getLinklistLength(LinkList *list, int *len);ok
int linklistInsert(LinkList *list, LinkListNode *node, int pos);ok
int linklistGetElem(LinkList *list, LinkListNode **node, int pos);ok
int linklistDelete(LinkList *list, LinkListNode **node, int pos); ok
*/

typedef struct _Teacher
{	
	//int age;
	LinkListNode node; //必须放在第一位 ，结构体偏移量重合，多态！！！如果不在第一位会发生错误！！！
	char *name;
	int age;

}*Teacher;

typedef struct _Student
{
	LinkListNode node;
	char *name;
	int age;
	int classroom;

}*Student;


int printST(Teacher t) //一个函数实现两种数据类型的打印-->C++多态的雏形？
{
	int ret = 0;
	if (t == NULL)
	{
		printf("argument err!\n");
		return -1;
	}
	printf("name: %s  @age: %d  \n", t->name, t->age);
	return ret;
}
int printS(Student s) 
{
	int ret = 0;
	if (s == NULL)
	{
		printf("argument err!\n");
		return -1;
	}
	printf("name: %s  @age: %d  @classroom: %d \n", s->name, s->age,s->classroom);
	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int i = 0;
	LinkListNode *tmp;
	LinkList *mylist;
	int mylistlen = 0;

	//创建一些节点
	Teacher t1 = (Teacher)malloc(sizeof(struct _Teacher));
	Teacher t2 = (Teacher)malloc(sizeof(struct _Teacher));
	Teacher t3 = (Teacher)malloc(sizeof(struct _Teacher));
	t1->name = "jack";
	t1->age = 30;
	t2->name = "mike";
	t2->age = 31;
	t3->name = "tom";
	t3->age = 32;

	Student s1 = (Student)malloc(sizeof(struct _Student));
	Student s2 = (Student)malloc(sizeof(struct _Student));
	Student s3 = (Student)malloc(sizeof(struct _Student));
	s1->name = "lucy";
	s1->age = 33;
	s1->classroom = 62;
	s2->name = "lily";
	s2->age = 34;
	s2->classroom = 62;
	s3->name = "judy";
	s3->age = 35;
	s3->classroom = 62;
	//	printST(t1);
	//	printST((Teacher)s1);
	//创建一个单向列表
	if (ret = linklistGreate(&mylist) != 0)
	{
		printf("list create fail!\n");
		return ret;
	}
	//头插法插入一些业务节点
	ret = linklistInsert(mylist, (LinkListNode *)t1, 0);
	ret = linklistInsert(mylist, (LinkListNode *)t2, 0);
	ret = linklistInsert(mylist, (LinkListNode *)t3, 0);
	ret = linklistInsert(mylist, (LinkListNode *)s1, 0);
	ret = linklistInsert(mylist, (LinkListNode *)s2, 0);
	ret = linklistInsert(mylist, (LinkListNode *)s3, 0);
	//获得单向列表的长度
	if (ret = getLinklistLength(mylist, &mylistlen) != 0)
	{
		printf("func getLinklistLength err!\n");
		return ret;
	}
	else
	{
		printf("thr linklist length is %d\n", mylistlen);
	}
	//遍历一下元素
	for (i = 0; i < mylistlen; i++)
	{
		if (ret = linklistGetElem(mylist, &tmp, i) != 0)
		{
			printf("func linklistGetElem err!\n");
			return ret;
		}
		else
		{
			printST((Teacher)tmp);
		}
	}
	printf("---------------------------------------------------------\n");

	//删除一个元素
	if (ret = linklistDelete(mylist, &tmp, 1) != 0)
	{
		printf("func linklistDelete err\n");
		return ret;
	}
	printf("thr deleted elem is :");
	printS((Student)tmp);

	//获得单向列表的长度
	if (ret = getLinklistLength(mylist, &mylistlen) != 0)
	{
		printf("func getLinklistLength err!\n");
		return ret;
	}
	else
	{
		printf("thr linklist length is %d\n", mylistlen);
	}
	//遍历一下元素
	for (i = 0; i < mylistlen; i++)
	{
		if (ret = linklistGetElem(mylist, &tmp, i) != 0)
		{
			printf("func linklistGetElem err!\n");
			return ret;
		}
		else
		{
			printST((Teacher)tmp);
		}
	}
	printf("---------------------------------------------------------\n");

	if (ret = linklistClear(&mylist) != 0)
	{
		printf("func linklistClear err\n ");
	}
	printf("the lisr has been cleared!\n");
	//获得单向列表的长度
	if (ret = getLinklistLength(mylist, &mylistlen) != 0)
	{
		printf("func getLinklistLength err!\n");
		return ret;
	}
	else
	{
		printf("thr linklist length is %d\n", mylistlen);
	}
	//遍历一下元素
	tmp = NULL;
	for (i = 0; i < 6; i++)
	{
		if (ret = linklistGetElem(mylist, &tmp, i) != 0)
		{
			printf("func linklistGetElem err!\n");
			return ret;
		}
		else
		{
			printST((Teacher)tmp);
		}
	}
	if (ret = linklistDestroy(&mylist) != 0)
	{
		printf("func linklistDestroy err\n");
		return ret;
	}
	printf("the list hsa been destroyed ! \n");
	printf("the function has been excuted!\n");


	system("pause");
	return ret;

}