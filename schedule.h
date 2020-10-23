#pragma once

class Schedule
{
private:
	int year, month, day;

public:
	Schedule(int year, int month, int day);
	void setSchedule(int year, int month, int day); // �������� ��¥ ����
	int* getSchedule();  // [��ǥ �⵵, ��ǥ ��, ��ǥ ��]�� int�� �迭 ��ȯ
	int getDDay();  // �����ٱ����� ���� ��ȯ
	int* getToday();  // [����⵵, ���� ��, ���� ��]�� int�� �迭 ��ȯ
};

