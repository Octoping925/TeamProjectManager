#include "teamMember.h"
#include "Goal.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
	teamMember member;

	string name;
	string num;
	string role;

	vector<teamMember> Mem;

	int i = 0, n = 0;
	cout << "�ο� �Է�:";
	cin >> n;
	
	for (i = 0; i < n; i++) {
		cout << "�̸� �Է�: ";
		cin >> name;

		cout << "�й� �Է�: ";
		cin >> num;

		cout << "���� �Է�: ";
		cin >> role;

		teamMember Member(name, num, role);
		Mem.push_back(Member);
		cout << "Success" << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << Mem[i].get_Name() << " ";
		cout << Mem[i].get_Number() << " ";
		cout << Mem[i].get_Role() << endl;
	}
	
	return 0;
}