#ifndef _LINKLIST_H_
#define _LINKLIST_H_

typedef void LinkList;
typedef struct _LinkListNode
{
	struct _LinkListNode * next;
}LinkListNode;

int linklistGreate(LinkList **list);
int linklistDestroy(LinkList **list);
int linklistClear(LinkList **list);
int getLinklistLength(LinkList *list, int *len);
int linklistInsert(LinkList *list, LinkListNode *node, int pos);
int linklistGetElem(LinkList *list, LinkListNode **node, int pos);
int linklistDelete(LinkList *list, LinkListNode **node, int pos);
#endif