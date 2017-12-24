#ifndef _SEQLIST_H_
#define _SEQLIST_H_

typedef void  SeqList;
typedef void  SeqListNode;


//capacity :˳��������
int seqListCreate(SeqList **list, int capacity);	//����һ��˳���
int seqListDestroy(SeqList **list);	//����һ��˳���
int seqListClear(SeqList **list);		//���һ��˳���
int getSeqListLength(SeqList *list, int *len);	//��ȡ��ǰ˳���ĳ���
int seqListInsert(SeqList *list, SeqListNode *node, int pos);	//����һ��Ԫ��
int seqListGet(SeqList *list, SeqListNode **node, int pos);		//��ȡһ��Ԫ��
int setListDelete(SeqList *list, SeqListNode **node, int pos);	//ɾ��һ��Ԫ��



#endif