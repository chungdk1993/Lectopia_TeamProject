#pragma once
#include "Structure.h"

void deviceMemcpy(void *p1, void *p2);
void devicePrint(void *p);
int deviceNameCmp(void *p1, void *p2);
void deviceInit(void *p);

void reserveMemcpy(void *p1, void *p2);
void reservePrint(void *p);
int reserveNameCmp(void *p1, void *p2);
int reserveTimeCmp(void *p1, void *p2);
/*
return : -1 => ���� �ð� ����
0 => ���� �ð�
1 => ���� �ð� ��
p1 : Reserve Ÿ�� ������ �ּ�
p2 : tm Ÿ�� ������ �ּ� (tm�� time.h���� ����Ǿ� �ִ� ����ü)
*/
void reserveInit(void *p);

void statusMemcpy(void *p1, void *p2);
int statusNameCmp(void *p1, void *p2);
void statusInit(void*p);
//void statusPrint(void *p);

void environMemcpy(void *p1, void *p2);
void environInit(void *p);

void infoPrint(void *p);

int createList(List *lp);					/* ���� ����Ʈ �ʱ�ȭ */
void destroyList(List *lp);
int addLast(List *lp, void *data, size_t size, void(*memcpy)(void *, void *));			/* tail node �տ� node �߰�(���� ����) */
void displayList(List *lp, void(*dataPrint)(void*));					/* ����Ʈ ���� ��� ������ ��� */
Node * searchNode(List *lp, void* data, int(*dataCompare)(void*, void*));
int removeNode(List *lp, void* data, int(*dataCompare)(void *, void *));