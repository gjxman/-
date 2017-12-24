#include <stdio.h> 
#include <stdlib.h>

#include "seqlist.h"

/*
typedef void  SeqList;
typedef void  SeqListNode;


int seqListCreate(SeqList **list, int capacity);	//����һ��˳��� ok
int seqListDestroy(SeqList **list);	//����һ��˳��� ok
int seqListClear(SeqList **list);		//���һ��˳��� ok
int getSeqListLength(SeqList *list, int *len);	//��ȡ��ǰ˳���ĳ��� ok
int seqListInsert(SeqList *list, SeqListNode *node, int pos);	//����һ��Ԫ�� ok
int seqListGet(SeqList *list, SeqListNode **node, int pos);		//��ȡһ��Ԫ�� ok
int setListDelete(SeqList *list, SeqListNode **node, int pos);	//ɾ��һ��Ԫ�� ok
*/

/*
typedef struct
{
	char name[64];
	int age;
}*Teacher; */  //���ַ�ʽ���������ͬ

typedef struct
{
	char *name;
	int age;
}*Teacher, Teacher1; //ע���ˣ�����Teacher* ���� *Teacher

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
	SeqList *mylist = NULL; //ʹ��ָ������ʼ��
	int mylistlen = 0;  //��ȡ˳���ĳ���
	Teacher tmp = NULL;

//	Teacher* t1 ,t2, t3, t4, t5 = NULL; �������廹������Ŷ���ɴ��Teacher typedefΪһ���ṹ��ָ��
	Teacher  t1 = (Teacher)malloc(sizeof(Teacher1)); //ָ�����͵ĸ����������ͱ����ʼ����
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
//�������Ǳ�д��˳�����
	//����һ����
	ret = seqListCreate(&mylist, 10);
	if (ret != 0)
	{
		printf("function seqListCreate err %d ", ret);
		return ret;
	}
	//ʹ��ͷ�巨����5���ڵ�
	ret = seqListInsert(mylist, t1, 0);//ͷ�巨
	ret = seqListInsert(mylist, t2, 0);//ͷ�巨
	ret = seqListInsert(mylist, t3, 0);//ͷ�巨
	ret = seqListInsert(mylist, t4, 0);//ͷ�巨
	ret = seqListInsert(mylist, t5, 0);//ͷ�巨

	//��ȡһ�²����ĳ���
	ret = getSeqListLength(mylist, &mylistlen);
	if (ret != 0)
	{
		printf("function getSeqListLength err %d ", ret);
		return ret;
	}
	printf("the length of the list is : %d\n", mylistlen);

	//��������������
	for (i = 0; i <mylistlen; i++) //����֮ǰ��û�ȡһ�³��ȣ�
	{
		ret = seqListGet(mylist, &tmp, i);
		if (ret != 0)
		{
			printf("function seqListCet err %d ", ret);
			return ret;
		}
		printT((Teacher)tmp); //�ǵ�����ת��
	}
	printf("----------------------------------------------------\n");

	//ɾ��һ���ڵ�
	ret = setListDelete(mylist, &tmp, 1);
	if (ret != 0)
	{
		printf("function setListDelete err %d ", ret);
		return ret;
	}
	printf("the deleted elem is : \n");
	printT(tmp); //��ӡɾ���Ľڵ�
	free(tmp);//�ͷŵ�ɾ���Ľڵ�

	//�ٻ�ȡһ��ɾ����ĳ���
	ret = getSeqListLength(mylist, &mylistlen);
	if (ret != 0)
	{
		printf("function getSeqListLength err %d ", ret);
		return ret;
	}
	printf("now length of the list is : %d\n", mylistlen);
	//����ɾ���������
	for (i = 0; i <mylistlen + 1; i++) //����һ�����
	{
		ret = seqListGet(mylist, &tmp, i);
		if (ret != 0)
		{
			printf("function seqListCet err %d ", ret);
			return ret;
		}
		printT((Teacher)tmp); //�ǵ�����ת��
	}
	printf("----------------------------------------------------\n");

	//���˳���
	ret = seqListClear(&mylist);
	if (ret != 0)
	{
		printf("function seqListClear err %d ", ret);
		return ret;
	}
	//�ٻ�ȡһ����պ�ĳ���
	ret = getSeqListLength(mylist, &mylistlen);
	if (ret != 0)
	{
		printf("function getSeqListLength err %d ", ret);
		return ret;
	}
	printf("now length of the list is : %d\n", mylistlen);
	//����ȡһ�½ڵ�����
	for (i = 0; i <5; i++) 
	{
		ret = seqListGet(mylist, &tmp, i);
		if (ret != 0)
		{
			printf("function seqListCet err %d ", ret);
			return ret;
		}
		printT((Teacher)tmp); //�ǵ�����ת��
	}
	printf("----------------------------------------------------\n");
	
	//����һ��˳���
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