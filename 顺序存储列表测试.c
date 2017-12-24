#include <stdio.h> 
#include <stdlib.h>

#include "seqlist.h"

/*
typedef void  SeqList;
typedef void  SeqListNode;


int seqListCreate(SeqList **list, int capacity);	//创建一个顺序表 ok
int seqListDestroy(SeqList **list);	//销毁一个顺序表 ok
int seqListClear(SeqList **list);		//清空一个顺序表 ok
int getSeqListLength(SeqList *list, int *len);	//获取当前顺序表的长度 ok
int seqListInsert(SeqList *list, SeqListNode *node, int pos);	//插入一个元素 ok
int seqListGet(SeqList *list, SeqListNode **node, int pos);		//获取一个元素 ok
int setListDelete(SeqList *list, SeqListNode **node, int pos);	//删除一个元素 ok
*/

/*
typedef struct
{
	char name[64];
	int age;
}*Teacher; */  //这种方式与下面的异同

typedef struct
{
	char *name;
	int age;
}*Teacher, Teacher1; //注意了，不是Teacher* 而是 *Teacher

int printT(Teacher t)
{
	if (t == NULL)
	{
		printf("func printT err,the elem is NULL\n");
		return -1;
	}
	printf("teacher'name : %s  and teacher'age : %d \n", t->name, t->age);
}

int main(int argc, char *argv[])
{
	int ret = 0;
	int i = 0;
	SeqList *mylist = NULL; //使用指针必须初始化
	int mylistlen = 0;  //获取顺序表的长度
	Teacher tmp = NULL;

//	Teacher* t1 ,t2, t3, t4, t5 = NULL; 这样定义还不可以哦！干脆吧Teacher typedef为一个结构体指针
	Teacher  t1 = (Teacher)malloc(sizeof(Teacher1)); //指针类型的复杂数据类型必须初始化！
	Teacher  t2 = (Teacher)malloc(sizeof(Teacher1));
	Teacher  t3 = (Teacher)malloc(sizeof(Teacher1));
	Teacher  t4 = (Teacher)malloc(sizeof(Teacher1));
	Teacher  t5 = (Teacher)malloc(sizeof(Teacher1));

	t1->name = "jack";
	t1->age = 31;

	t2->name = "bob";
	t2->age = 32;

	t3->name = "lucy";
	t3->age = 33;

	t4->name = "tom";
	t4->age = 34;

	t5->name = "mike";
	t5->age = 35;
//测试我们编写的顺序表函数
	//创建一个表
	ret = seqListCreate(&mylist, 10);
	if (ret != 0)
	{
		printf("function seqListCreate err %d ", ret);
		return ret;
	}
	//使用头插法插入5个节点
	ret = seqListInsert(mylist, t1, 0);//头插法
	ret = seqListInsert(mylist, t2, 0);//头插法
	ret = seqListInsert(mylist, t3, 0);//头插法
	ret = seqListInsert(mylist, t4, 0);//头插法
	ret = seqListInsert(mylist, t5, 0);//头插法

	//获取一下插入后的长度
	ret = getSeqListLength(mylist, &mylistlen);
	if (ret != 0)
	{
		printf("function getSeqListLength err %d ", ret);
		return ret;
	}
	printf("the length of the list is : %d\n", mylistlen);

	//遍历插入后的数据
	for (i = 0; i <mylistlen; i++) //遍历之前最好获取一下长度！
	{
		ret = seqListGet(mylist, &tmp, i);
		if (ret != 0)
		{
			printf("function seqListCet err %d ", ret);
			return ret;
		}
		printT((Teacher)tmp); //记得类型转换
	}
	printf("----------------------------------------------------\n");

	//删除一个节点
	ret = setListDelete(mylist, &tmp, 1);
	if (ret != 0)
	{
		printf("function setListDelete err %d ", ret);
		return ret;
	}
	printf("the deleted elem is : \n");
	printT(tmp); //打印删除的节点
	free(tmp);//释放掉删除的节点

	//再获取一下删除后的长度
	ret = getSeqListLength(mylist, &mylistlen);
	if (ret != 0)
	{
		printf("function getSeqListLength err %d ", ret);
		return ret;
	}
	printf("now length of the list is : %d\n", mylistlen);
	//遍历删除后的数据
	for (i = 0; i <mylistlen + 1; i++) //制造一点错误
	{
		ret = seqListGet(mylist, &tmp, i);
		if (ret != 0)
		{
			printf("function seqListCet err %d ", ret);
			return ret;
		}
		printT((Teacher)tmp); //记得类型转换
	}
	printf("----------------------------------------------------\n");

	//清空顺序表
	ret = seqListClear(&mylist);
	if (ret != 0)
	{
		printf("function seqListClear err %d ", ret);
		return ret;
	}
	//再获取一下清空后的长度
	ret = getSeqListLength(mylist, &mylistlen);
	if (ret != 0)
	{
		printf("function getSeqListLength err %d ", ret);
		return ret;
	}
	printf("now length of the list is : %d\n", mylistlen);
	//尝试取一下节点数据
	for (i = 0; i <5; i++) 
	{
		ret = seqListGet(mylist, &tmp, i);
		if (ret != 0)
		{
			printf("function seqListCet err %d ", ret);
			return ret;
		}
		printT((Teacher)tmp); //记得类型转换
	}
	printf("----------------------------------------------------\n");
	
	//销毁一个顺序表
	ret = seqListDestroy(&mylist);
	if (ret != 0)
	{
		printf("function seqListClear err %d ", ret);
		return ret;
	}

	printf("hello ,the program has been excuted!\n");
	system("pause");
	return ret;
}