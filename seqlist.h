#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void  SeqList;
typedef void  SeqListNode;


//capacity :顺序表的容量
int seqListCreate(SeqList **list, int capacity);	//创建一个顺序表
int seqListDestroy(SeqList **list);	//销毁一个顺序表
int seqListClear(SeqList **list);		//清空一个顺序表
int getSeqListLength(SeqList *list, int *len);	//获取当前顺序表的长度
int seqListInsert(SeqList *list, SeqListNode *node, int pos);	//插入一个元素
int seqListGet(SeqList *list, SeqListNode **node, int pos);		//获取一个元素
int setListDelete(SeqList *list, SeqListNode **node, int pos);	//删除一个元素



#endif