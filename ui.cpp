#include "ui.h"
#include <iostream>
#include <conio.h>

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
void print_graph() {
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
void print_main_menu() {
	print_outline();
	print_title();
	set_text_color(DARK_GRAY, WHITE);

	gotoxy(7, 10);
	cout << "�� ���� ����";
	gotoxy(7, 12);
	cout << "�� ��� ����";
	gotoxy(7, 14);
	cout << "�� ���θ�ǥ ����";
	gotoxy(7, 16);
	cout << "�� ���α׷� ����";

	print_graph();
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