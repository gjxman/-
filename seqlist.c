#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

typedef struct _tag_SqList
{
	int length;
	int capacity;
	//unsigned int **node;
	//unsigned int *node[];
	unsigned int *node;

}SqList;

//capacity :顺序表的容量
int seqListCreate(SeqList **list, int capacity)
{
	int ret = 0;
	SqList *tlist = NULL;
	if (list == NULL) //判断传入的参数是否合法
	{
		printf("func seqlistCreate err: %d", ret);
		return ret;
	}
	tlist = (SqList *)malloc(sizeof(SqList)); //分配列表的空间
	memset(tlist, 0, sizeof(SqList));

	tlist->node = (unsigned int **)malloc(sizeof(unsigned int) * capacity);//根据容量分配节点空间
	memset(tlist->node, 0, sizeof(unsigned int)* capacity);

	tlist->capacity = capacity;
	tlist->length = 0;//

	*list = tlist; // 
	return 0;
}
int seqListDestroy(SeqList **list)
{
	int ret = 0;
	SqList *tlist = NULL;
	if (list == NULL)
	{
		printf("func seqListDestroy err: %d", ret);
		return ret;
	}
	tlist = (SqList *)(*list);

	if (tlist->node != NULL)
	{
		free(tlist->node);
	}
	if (tlist != NULL)
	{
		free(tlist);
	}
	*list = tlist;
	return 0;
}

int seqListClear(SeqList **list)
{
	int ret = 0;
	SqList *tlist = NULL;
	if (list == NULL)
	{
		printf("func seqListClear err: %d", ret);
		return ret;
	}
	tlist = (SqList *)(*list);
	tlist->length = 0;
	memset(tlist->node, 0, sizeof(unsigned int)* tlist->capacity);
	return 0;
}

int getSeqListLength(SeqList *list, int *len)
{
	int ret = 0;
	if (list == NULL)
	{
		printf("func getSeqListLength err: %d", ret);
		return ret;
	}
	*len = ((SqList *)list)->length;//先将列表转换为一个我们知道的类型
	return 0;
}
int seqListInsert(SeqList *list, SeqListNode *node, int pos)
{
	int ret = 0;
	int i = 0;
	SqList *tlist = NULL;
	if (list == NULL)
	{
		printf("func getSeqListLength err: %d", ret);
		return ret;
	}
	tlist = (SqList *)list;
	//判断是不是满了
	if (tlist->length >= tlist->capacity)
	{
		ret = -2;
		printf("fun SeqList_Insert() (tlist->length >= tlist->capacity) err:%d \n", ret);
		return ret;
	}

	//容错修正  6个长度 容量20;用户pos10位置插入..
	if (pos >= tlist->length)
	{
		pos = tlist->length; //
	}
	
	for (i = tlist->length; i > pos; i--)//移动元素，从后往前移动，避免覆盖
	{
		//tlist->node[i + 1] = tlist->node[i];
		tlist->node[i] = tlist->node[i - 1]; //特别注意下标操作！！！
	}
	tlist->node[i] = node;

	tlist->length++;

	return 0;
}

int seqListGet(SeqList *list, SeqListNode **node, int pos)
{
	int ret = 0;
	int i = 0;
	SqList *tlist = NULL;
	if (list == NULL || pos < 0)
	{
		printf("func getSeqListGet err: %d", ret);
		return ret;
	}
	tlist = (SqList *)list;

	*node = (SeqListNode *)tlist->node[pos];
	return 0;
}
int setListDelete(SeqList *list, SeqListNode **node, int pos)
{
	int ret = 0;
	int i = 0;
	SqList *tlist = NULL;
	if (list == NULL || pos < 0)
	{
		printf("func getSeqListGet err: %d", ret);
		return ret;
	}
	tlist = (SqList *)list;

	*node = (SeqListNode *)(tlist->node[pos]);
	for (i = pos; i < tlist->capacity; i++)
	{
		tlist->node[i] = tlist->node[i + 1];
	}
	tlist->length--;
	return 0;
}