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
	LinkListNode node; //������ڵ�һλ ���ṹ��ƫ�����غϣ���̬������������ڵ�һλ�ᷢ�����󣡣���
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


int printST(Teacher t) //һ������ʵ�������������͵Ĵ�ӡ-->C++��̬�ĳ��Σ�
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

	//����һЩ�ڵ�
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
	//����һ�������б�
	if (ret = linklistGreate(&mylist) != 0)
	{
		printf("list create fail!\n");
		return ret;
	}
	//ͷ�巨����һЩҵ��ڵ�
	ret = linklistInsert(mylist, (LinkListNode *)t1, 0);
	ret = linklistInsert(mylist, (LinkListNode *)t2, 0);
	ret = linklistInsert(mylist, (LinkListNode *)t3, 0);
	ret = linklistInsert(mylist, (LinkListNode *)s1, 0);
	ret = linklistInsert(mylist, (LinkListNode *)s2, 0);
	ret = linklistInsert(mylist, (LinkListNode *)s3, 0);
	//��õ����б�ĳ���
	if (ret = getLinklistLength(mylist, &mylistlen) != 0)
	{
		printf("func getLinklistLength err!\n");
		return ret;
	}
	else
	{
		printf("thr linklist length is %d\n", mylistlen);
	}
	//����һ��Ԫ��
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

	//ɾ��һ��Ԫ��
	if (ret = linklistDelete(mylist, &tmp, 1) != 0)
	{
		printf("func linklistDelete err\n");
		return ret;
	}
	printf("thr deleted elem is :");
	printS((Student)tmp);

	//��õ����б�ĳ���
	if (ret = getLinklistLength(mylist, &mylistlen) != 0)
	{
		printf("func getLinklistLength err!\n");
		return ret;
	}
	else
	{
		printf("thr linklist length is %d\n", mylistlen);
	}
	//����һ��Ԫ��
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
	//��õ����б�ĳ���
	if (ret = getLinklistLength(mylist, &mylistlen) != 0)
	{
		printf("func getLinklistLength err!\n");
		return ret;
	}
	else
	{
		printf("thr linklist length is %d\n", mylistlen);
	}
	//����һ��Ԫ��
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