#include "ui.h"
#include <iostream>
#include <conio.h>
#include <sstream>

using namespace std;

void set_text_color(int text_color, int background_color) {
	int color = text_color + background_color * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void cursor_view(bool show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void print_outline() {
	set_text_color(BLACK, WHITE);
	cursor_view(false);

	gotoxy(0, 0);
	cout << "��";
	for (int i = 0; i < 121; ++i)
		cout << "��";
	cout << "�� \n";

	for (int i = 0; i < 38; ++i) {
		cout << "��";
		for (int j = 0; j < 121; ++j)
			cout << " ";
		cout << "�� \n";
	}

	cout << "��";
	for (int i = 0; i < 121; ++i)
		cout << "��";
	cout << "�� ";

	gotoxy(3, 8);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "��";

	for (int i = 9; i < 38; ++i) {
		gotoxy(3, i);
		cout << "��";
		gotoxy(119, i);
		cout << "��";
	}

	gotoxy(3, 37);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "��";

	gotoxy(0, 0);
}
void print_title() {
	set_text_color(BLACK, BLACK);
	//print "T"
	gotoxy(4, 2);
	cout << "          ";
	for (int i = 3; i < 7; ++i) {
		gotoxy(8, i);
		cout << "  ";
	}
	//print "P"
	gotoxy(16, 2);
	cout << "          ";
	gotoxy(16, 3);
	cout << "  ";
	gotoxy(24, 3);
	cout << "  ";
	gotoxy(16, 4);
	cout << "          ";
	gotoxy(16, 5);
	cout << "  ";
	gotoxy(16, 6);
	cout << "  ";
	//print "M"
	for (int i = 2; i < 7; ++i) {
		gotoxy(28, i);
		cout << "  ";
	}
	for (int i = 2; i < 7; ++i) {
		gotoxy(36, i);
		cout << "  ";
	}
	gotoxy(30, 3);
	cout << "  ";
	gotoxy(34, 3);
	cout << "  ";
	gotoxy(32, 4);
	cout << "  ";
	//print "Team Project Manager"
	set_text_color(DARK_GRAY, WHITE);
	gotoxy(40, 6);
	cout << "Team Project Manager";
}
void clear_box() {
	set_text_color(BLACK, WHITE);

	gotoxy(3, 8);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "��";

	for (int i = 9; i < 37; ++i) {
		gotoxy(3, i);
		cout << "��";
		for (int j = 0; j < 115; ++j)
			cout << " ";
		cout << "��";
	}

	gotoxy(3, 37);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "��";

	gotoxy(0, 0);
}
void print_graph(const Team& t) {
	clear_box();

	set_text_color(BLACK, WHITE);
	gotoxy(3, 18);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "�� ";

	gotoxy(98, 20);
	set_text_color(RED, RED);
	cout << "  ";
	set_text_color(BLACK, WHITE);
	cout << " ��ǥġ";

	gotoxy(109, 20);
	set_text_color(BLUE, BLUE);
	cout << "  ";
	set_text_color(BLACK, WHITE);
	cout << " �޼���";

	// UI ������ ���� ���������� �׷����� �׷��־���.
	// ���� �ڵ����� �޼����� ����Ͽ� �׷����� ��Ÿ���� �Լ� ���� ����
	gotoxy(9, 23);
	cout << "��� 1 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 100; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(18, 24);
	cout << "100% �޼� (10/10)";

	set_text_color(BLACK, WHITE);
	gotoxy(9, 26);
	cout << "��� 2 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 100; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(18, 27);
	cout << "100% �޼� (10/10)";

	set_text_color(BLACK, WHITE);
	gotoxy(9, 29);
	cout << "��� 3 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 100; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(18, 30);
	cout << "100% �޼� (10/10)";

	set_text_color(BLACK, WHITE);
	gotoxy(9, 32);
	cout << "��� 4 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 100; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(18, 33);
	cout << "100% �޼� (10/10)";

	gotoxy(73, 35);
	set_text_color(BLUE, WHITE);
	cout << "<�߰����� ����>";
	set_text_color(BLACK, WHITE);
	cout << " �������� ";
	set_text_color(RED, WHITE);
	cout << "1�� ";
	set_text_color(BLACK, WHITE);
	cout << "���ҽ��ϴ�.";
}
/*void print_main_menu(const Team& t) {
	clear_box();

	set_text_color(DARK_GRAY, WHITE);

	gotoxy(7, 10);
	cout << "�� ���� ����";
	gotoxy(7, 12);
	cout << "�� ��� ����";
	gotoxy(7, 14);
	cout << "�� ���θ�ǥ ����";
	gotoxy(7, 16);
	cout << "�� ���α׷� ����";

	print_graph(t);
}*/
void print_schedule(Team& t) {
	while (true) {
		clear_box();

		set_text_color(BLACK, WHITE);
		gotoxy(3, 16);
		cout << "��";
		for (int i = 0; i < 115; ++i)
			cout << "��";
		cout << "�� ";

		if (t.getScheduleCnt() == 0) {
			set_text_color(DARK_GRAY, WHITE);
			gotoxy(48, 27);
			cout << "���� ��ϵ� ������ �����ϴ�." << endl;
		}
		else {
			t.sortSchedule();
			for (int i = 0; i < t.getScheduleCnt(); ++i) {
				if (i == 9)
					break;

				gotoxy(9, 18 + 2 * i);
				int dday = t.getSchedule(i).getDDay();
				if (dday <= 3)
					set_text_color(RED, WHITE);
				else
					set_text_color(BLUE, WHITE);
				cout << "[D-" << dday << "] ";
				set_text_color(BLACK, WHITE);
				cout << t.getSchedule(i).getName() << " (" << t.getSchedule(i).getYear() << "/" <<
					t.getSchedule(i).getMonth() << "/" << t.getSchedule(i).getDay() << ")";
			}
		}

		int menu_num = select_schedule_menu();
		int schedule_num = 0;
		switch (menu_num) {
		case -1:
			return;
		case 0:
			add_schedule(t);
			break;
		case 1:
			schedule_num = select_schedule();
			if (0 <= schedule_num && schedule_num < t.getScheduleCnt())
				t.delSchedule(schedule_num);
			break;
		case 2:
			schedule_num = select_schedule();
			if (0 <= schedule_num && schedule_num < t.getScheduleCnt())
				modify_schedule(t, schedule_num);
			break;
		}
	}
}
void print_schedule_menu() {
	clear_box();

	set_text_color(DARK_GRAY, WHITE);

	gotoxy(7, 10);
	cout << "�� ���� �߰�";
	gotoxy(7, 12);
	cout << "�� ���� ����";
	gotoxy(7, 14);
	cout << "�� ���� ����";

	set_text_color(BLACK, WHITE);
	gotoxy(3, 16);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "�� ";
}

int select_main_menu() {
	int cursor = 0;
	int key_input;

	while (true) {
		set_text_color(DARK_GRAY, WHITE);

		gotoxy(7, 10);
		cout << "�� ���� ����";
		gotoxy(7, 12);
		cout << "�� ��� ����";
		gotoxy(7, 14);
		cout << "�� ���θ�ǥ ����";
		gotoxy(7, 16);
		cout << "�� ���α׷� ����";

		set_text_color(BLACK, WHITE);
		gotoxy(7, 10 + 2 * cursor);
		switch (cursor) {
		case 0:
			cout << "�� ���� ����";
			break;
		case 1:
			cout << "�� ��� ����";
			break;
		case 2:
			cout << "�� ���θ�ǥ ����";
			break;
		case 3:
			cout << "�� ���α׷� ����";
			break;
		}

		key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 3)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ENTER)
			return cursor;
	}
}
int select_schedule_menu() {
	int cursor = 0;
	int key_input;

	while (true) {
		set_text_color(DARK_GRAY, WHITE);

		gotoxy(7, 10);
		cout << "�� ���� �߰�";
		gotoxy(7, 12);
		cout << "�� ���� ����";
		gotoxy(7, 14);
		cout << "�� ���� ����";

		set_text_color(BLACK, WHITE);
		gotoxy(7, 10 + 2 * cursor);
		switch (cursor) {
		case 0:
			cout << "�� ���� �߰�";
			break;
		case 1:
			cout << "�� ���� ����";
			break;
		case 2:
			cout << "�� ���� ����";
			break;
		}

		key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 2)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ESC)
			return -1;
		else if (key_input == Key::ENTER)
			return cursor;
	}
}
int select_schedule() {
	int cursor = 0;
	int key_input;

	set_text_color(BLACK, WHITE);

	while (true) {
		for (int i = 18; i < 35; i += 2) {
			gotoxy(6, i);
			cout << "  ";
		}

		gotoxy(6, 18 + 2 * cursor);
		cout << "��";

		key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 8)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ENTER)
			return cursor;
		else if (key_input == Key::ESC)
			return -1;
	}
}
int select_member() {
	int cursor = 0;
	int key_input;
	
	set_text_color(BLACK, WHITE);

	while (true) {
		for (int i = 23; i < 33; i += 3) {
			gotoxy(6, i);
			cout << "  ";
		}

		gotoxy(6, 23 + 3 * cursor);
		cout << "��";

		key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 3)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ENTER)
			return cursor;
	}
}

void add_schedule(Team& t) {
	while (true) {
		string name, date;
		int year = 0, month = 0, day = 0;
		char yn = 0;

		print_schedule_menu();
		set_text_color(BLACK, WHITE);
		gotoxy(7, 10);
		cout << "�� ���� �߰�";
		
		set_text_color(DARK_GRAY, WHITE);
		gotoxy(6, 21);
		cout << "�� �������� : ";
		gotoxy(7, 22);
		cout << "(�Է� ���� : 2020 11 21)";

		cursor_view(true);
		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 18);
			cout << "�� ���� :                                                                                                        ��  ��";
			gotoxy(0, 19);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 18);
			getline(cin, name);

			if (name.length() < 1) {
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (50 < name.length()) {
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "������ �ִ� 50�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 18);
		cout << "�� ";
		
		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 21);
			cout << "�� �������� :                 ";
			gotoxy(20, 21);
			getline(cin, date);

			if (!is_valid_date_input(date,&year,&month,&day)) {
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else
				break;
		}
		set_text_color(BLACK, WHITE);
		gotoxy(6, 21);
		cout << "�� ";
		gotoxy(6, 24);
		cout << "                                                                    ";

		gotoxy(6, 24);
		cout << "�� ������ �߰��Ͻðڽ��ϱ�? (Y/N) :          ";
		while (true) {
			gotoxy(6, 24);
			cout << "�� ������ �߰��Ͻðڽ��ϱ�? (Y/N) :          ";
			gotoxy(42, 24);
			cin >> yn;

			if (yn == 'Y' || yn == 'y') {
				t.addSchedule(name, year, month, day);
				cursor_view(false);
				getchar();
				return;
			}
			else if (yn == 'N' || yn == 'n') {
				cursor_view(false);
				getchar();
				return;
			}
			else
				continue;
		}
	}
}
void modify_schedule(Team& t, int idx) {
	while (true) {
		string name, date;
		int year = 0, month = 0, day = 0;
		char yn = 0;

		print_schedule_menu();
		set_text_color(BLACK, WHITE);
		gotoxy(7, 14);
		cout << "�� ���� ����";

		set_text_color(DARK_GRAY, WHITE);
		gotoxy(6, 21);
		cout << "�� �������� : ";
		gotoxy(7, 22);
		cout << "(�Է� ���� : 2020 11 21)";

		cursor_view(true);
		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 18);
			cout << "�� ���� :                                                                                                        ��  ��";
			gotoxy(0, 19);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 18);
			getline(cin, name);

			if (name.length() < 1) {
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (50 < name.length()) {
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "������ �ִ� 50�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 18);
		cout << "�� ";

		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 21);
			cout << "�� �������� :                 ";
			gotoxy(20, 21);
			getline(cin, date);

			if (!is_valid_date_input(date, &year, &month, &day)) {
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else
				break;
		}
		set_text_color(BLACK, WHITE);
		gotoxy(6, 21);
		cout << "�� ";
		gotoxy(6, 24);
		cout << "                                                                    ";

		gotoxy(6, 24);
		cout << "�� ������ �����Ͻðڽ��ϱ�? (Y/N) :          ";
		while (true) {
			gotoxy(6, 24);
			cout << "�� ������ �����Ͻðڽ��ϱ�? (Y/N) :          ";
			gotoxy(42, 24);
			cin >> yn;

			if (yn == 'Y' || yn == 'y') {
				t.getSchedule(idx).setName(name);
				t.getSchedule(idx).setSchedule(year, month, day);
				cursor_view(false);
				getchar();
				return;
			}
			else if (yn == 'N' || yn == 'n') {
				cursor_view(false);
				getchar();
				return;
			}
			else
				continue;
		}
	}
}

bool is_valid_date_input(string date, int* year, int* month, int* day) {
	vector<string> tokens;
	string token;
	stringstream ss(date);

	while (getline(ss, token, ' ')) {
		tokens.push_back(token);
	}

	if (tokens.size() != 3) return false;

	if (is_number(tokens[0]))
		*year = stoi(tokens[0]);
	else return false;

	if (is_number(tokens[1]))
		*month = stoi(tokens[1]);
	else return false;

	if (is_number(tokens[2]))
		*day = stoi(tokens[2]);
	else return false;

	return isValidDate(*year, *month, *day);
}
bool is_number(string str) {
	int i = 0;
	while (i < str.length()) {
		if (!('0' <= str[i] && str[i] <= '9'))
			return false;
		++i;
	}
	return true;
}