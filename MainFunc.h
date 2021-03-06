#pragma once
#include "Structure.h"
#define FILE_NAME 30

/*
list : List 방 3개짜리 배열명
dlist : Node가 Device 구조체로 구성되어, 각 장치들의 정보를 갖는 List
rlist : Node가 Reserve 구조체로 구성되어, 각 장치들의 예약 정보를 갖는 List
slist : Node가 Status 구조체로 구성되어, 각 장치들의 상태 정보를 갖는 List
*/

void fileRead(List *list, const char *fileName);	// fileName에 해당하는 파일의 정보를 해당하는 List에 저장 
void deviceRead(List *dlist, const char *fileName);
void reserveRead(List *rlist,const char *fileName);
void statusRead(List *slist,const char *fileName);
void environRead(List *elist,const char *filName);
void fileWrite(List *list, const char *fileName);	// list의 정보를 해당 파일에 저장한다
void deviceWrite(List *dlist, const char *fileName);
void reserveWrite(List *rlist, const char *fileName);
void statusWrite(List *slist, const char *fileName);

void mainMenu();	// Main 메뉴들을 출력.
void gotoxy(int, int);
void printMain(List *slist);

void setMenu(List *list);				// 설정모드의 메뉴. 
void enrollDevice(List *dlist);		// 장치를 등록하기 위한 함수
void freeDevice(List *list);			// 장치를 해제하기 위한 함수
void infoDevice(List *dlist);			// 장치들의 정보를 출력해주는 함수
void checkRes(List *rlist);			// 장치들의 예약 정보를 출력해주는 함수
void resetAll(List *list);				// 모든 장치, 예약, 상태의 정보를 삭제하는 함수

void power(List *slist);				// cookmenu 2번, 메인메뉴함수에서 'O' 입력 시 호출
												// 장치들의 ON, OFF를 제어하는 함수
void powerCheck(List *slist, int index);

//void printStatus(List *slist);			// 현재 장치들의 상태를 출력해주는 함수

void airMenu(List *list);				// 에어컨 메뉴를 실행하는 함수
int airTemp();							// 에어컨 희망 온도 값 리턴

void temperMenu(List *slist);		// 수온 조절 메뉴를 실행하는 함수
void setTemper(List *slist, Status *scur);						// 수온 희망 온도 값 반환해주는 함수

void cookMenu(List *slist, List *rlist);			// 밥솥 관련 메뉴를 실행하는 함수
void setCook(List *slist, List *rlist);

void laundMenu(List *list, List *rlist);			// 세탁기 관련 메뉴를 실행하는 함수
int Mode(char *deviceName);	// 희망 세탁기 및 공기청정기 모드 번호 반환하는 함수
					// 에어컨의 경우 1~4번 중 하나, 세탁기의 경우 1~3번 중 하나, 공기청정기의 경우 1 or 2 중 하나 반환
void aircleanMenu(List *list);		// 공기청정기 관련 메뉴를 실행하는 함수

void timeReserve(List *rlist, char* device);		// 시간 예약을 위한 함수
												// 모든 장치 메뉴에서 모두 사용됨


void executeReserve(List *rlist, List *slist);
void reserveCheck(List *rlist, List *check);
void changeStatus(List *slist, Status *scur, Reserve *rcur);
int checkChange(List *slist);

char kbhitMenu();
int menu(const char **mList, size_t menuCnt);
void myflush();