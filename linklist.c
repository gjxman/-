#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

typedef struct
{
	LinkListNode header; // 头结点
	int length;			//链表长度
}Llist;

int linklistGreate(LinkList **list)
{
	int ret = 0;
	Llist *tlist = (Llist *)malloc(sizeof(Llist));
	if (tlist == NULL)
	{
		printf("malloc err\n");
		return -1;
	}
	tlist->header.next = NULL;
	tlist->length = 0;

	*list = tlist; //记得将申请的地址传出
	return ret;
}
int linklistDestroy(LinkList **list)
{
	int ret = 0;
	Llist *tlist = NULL;
	if (list == NULL)
	{
		printf("func linklistDestroy err!\n");
		return -1;
	}
	tlist = (Llist *)(*list);
	free(tlist);
	//if (tlist != NULL)  //free只是让内存释放，但他指向的东西并非NULL，而是乱码。
	//{
	//	printf("free err!\n");
	//	return -2;
	//}

	*list = NULL; //
	return ret;
}
int linklistClear(LinkList **list)
{
	int ret = 0;
	Llist *tlist = NULL;
	if (list == NULL)
	{
		printf("argument err!\n");
		return -1;
	}
	tlist = (Llist *)(*list);

	tlist->header.next = NULL;
	tlist->length = 0;

	*list = tlist;

	return ret;
}
int getLinklistLength(LinkList *list,int *len)
{
	int ret = 0;
	Llist *tlist = NULL;
	if (list == NULL)
	{
		printf("argument err!\n");
		return -1;
	}
	tlist = (Llist *)list;
	*len = tlist->length;	
	return ret;
}
int linklistInsert(LinkList *list, LinkListNode *node, int pos)
{
	int ret = 0;
	int i = 0;
	Llist *tlist = NULL;
	LinkListNode *current = NULL; //引入一个辅助指针变量
	if (list == NULL || node == NULL || pos < 0)
	{
		printf("argument err!\n");
		return -1;
	}

	tlist = (Llist *)list;
	current = &tlist->header;
	for (i = 0; i < pos && current->next != NULL; i++)//i = 2
	{
		current= current->next;//
	}

	node->next = current->next;
	current->next = node;
	tlist->length++;

	return ret;
}
int linklistGetElem(LinkList *list, LinkListNode **node, int pos)
{
	int ret = 0;
	int i = 0;
	Llist *tlist = NULL;
	LinkListNode *current = NULL;
	if (list == NULL || pos < 0 )
	{
		printf("argv err\n");
		return -1;
	}

	tlist = (Llist *)list;
	current = (LinkListNode *)tlist;
	if (pos < tlist->length)
	{
		for (i = 0; i < pos &&current != NULL; i++)
		{
			current = current->next;
		}
		*node = current->next;
	}
	return ret;
}
int linklistDelete(LinkList *list, LinkListNode **node, int pos)
{
	int ret = 0;
	int i = 0;
	Llist *tlist = NULL;
	LinkListNode *current = NULL;
	LinkListNode *tmp = NULL;
	if (list == NULL || pos < 0)
	{
		printf("argv err\n");
		return -1;
	}

	tlist = (Llist *)list;
	current = (LinkListNode *)tlist;

	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}
	tmp = current->next; //记录删除的节点
	current->next = tmp->next;
	tlist->length--;
	*node = tmp;
	return ret;
}