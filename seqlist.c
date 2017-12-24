#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

typedef struct _tag_SqList
{
	int length;
	int capacity;
	unsigned int **node;
	//unsigned int *node[];
	//unsigned int *node;

}SqList;

//capacity :˳��������
int seqListCreate(SeqList **list, int capacity)
{
	int ret = 0;
	SqList *tlist = NULL;
	if (list == NULL) //�жϴ���Ĳ����Ƿ�Ϸ�
	{
		printf("func seqlistCreate err: %d", ret);
		return ret;
	}
	tlist = (SqList *)malloc(sizeof(SqList)); //�����б�Ŀռ�
	memset(tlist, 0, sizeof(SqList));

	tlist->node = (unsigned int **)malloc(sizeof(unsigned int) * capacity);//������������ڵ�ռ�
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
	*len = ((SqList *)list)->length;//�Ƚ��б�ת��Ϊһ������֪��������
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
	//�ж��ǲ�������
	if (tlist->length >= tlist->capacity)
	{
		ret = -2;
		printf("fun SeqList_Insert() (tlist->length >= tlist->capacity) err:%d \n", ret);
		return ret;
	}

	//�ݴ�����  6������ ����20;�û�pos10λ�ò���..
	if (pos >= tlist->length)
	{
		pos = tlist->length; //
	}
	
	for (i = tlist->length; i > pos; i--)//�ƶ�Ԫ�أ��Ӻ���ǰ�ƶ������⸲��
	{
		//tlist->node[i + 1] = tlist->node[i];
		tlist->node[i] = tlist->node[i - 1]; //�ر�ע���±����������
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