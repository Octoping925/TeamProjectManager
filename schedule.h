#pragma once
#include <string>
#include <time.h>

using namespace std;

int* getToday();  // [����⵵, ���� ��, ���� ��]�� int�� �迭 ��ȯ
bool isLeapYear(int year);  // year�� �����̶�� true ��ȯ

class Schedule
{
private:
	string name;
	int year, month, day;

public:
	Schedule();
	Schedule(string name, int year, int month, int day);
	void setSchedule(int year, int month, int day); // �������� ��¥ ����
	void setName(string name);  // �������� �̸� ����
	string getName();  // �������� �̸� ��ȯ
	int* getSchedule();  // [��ǥ �⵵, ��ǥ ��, ��ǥ ��]�� int�� �迭 ��ȯ
	int getDDay();  // �����ٱ����� ���� ��ȯ
};
