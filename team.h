#pragma once
#include <string>
#include <vector>
#include "teamMember.h"
#include "schedule.h"

using namespace std;

class Team
{
public:
	teamMember& getMember(int idx);  // �� ������� ����
	Schedule& getSchedule(int idx);  // �� ��ǥ���� ����
	int getMemberCnt() const;  // ���� ��� �� ��ȯ
	int getScheduleCnt() const; 

	void addMember(string name, string number, string role);
	int delMember(int idx);
	void addSchedule(string name, int year, int month, int day);
	int delSchedule(int idx);
	int delOldSchedules();
	void sortSchedule(); // �� ��ǥ���� D-Day�� ���� ������ ����

private:
	vector<teamMember> member;
	vector<Schedule> schedules;
};
