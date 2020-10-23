#include "ui.h"
#include <iostream>

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
	for (int i = 0; i < 118; ++i)
		cout << "��";
	cout << "�� \n";

	for (int i = 0; i < 38; ++i) {
		cout << "��";
		for (int j = 0; j < 118; ++j)
			cout << " ";
		cout << "�� \n";
	}

	cout << "��";
	for (int i = 0; i < 118; ++i)
		cout << "��";
	cout << "�� ";

	gotoxy(3, 8);
	cout << "��";
	for (int i = 0; i < 112; ++i)
		cout << "��";
	cout << "��";

	for (int i = 9; i < 37; ++i) {
		gotoxy(3, i);
		cout << "��";
		gotoxy(116, i);
		cout << "��";
	}

	gotoxy(3, 37);
	cout << "��";
	for (int i = 0; i < 112; ++i)
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
	gotoxy(3, 16);
	cout << "��";
	for (int i = 0; i < 112; ++i)
		cout << "��";
	cout << "�� ";

	gotoxy(95, 17);
	set_text_color(RED, RED);
	cout << "  ";
	set_text_color(BLACK, WHITE);
	cout << " ��ǥġ";

	gotoxy(106, 17);
	set_text_color(BLUE, BLUE);
	cout << "  ";
	set_text_color(BLACK, WHITE);
	cout << " �޼���";

	// UI ������ ���� ���������� �׷����� �׷��־���.
	// ���� �ڵ����� �޼����� ����Ͽ� �׷����� ��Ÿ���� �Լ� ���� ����
	gotoxy(6, 20);
	cout << "��� 1 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 70; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(15, 21);
	cout << "70% �޼� (7/10)";

	gotoxy(6, 24);
	set_text_color(BLACK, WHITE);
	cout << "��� 2 : ";
	set_text_color(RED, RED);
	for (int i = 0; i < 60; ++i)
		cout << " ";
	gotoxy(15, 24);
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 40; ++i)
		cout << " ";
	gotoxy(15, 25);
	set_text_color(RED, WHITE);
	cout << "40% �޼� (4/10)";

	gotoxy(6, 28);
	set_text_color(BLACK, WHITE);
	cout << "��� 3 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 50; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(15, 29);
	cout << "50% �޼� (5/10)";

	gotoxy(6, 32);
	set_text_color(BLACK, WHITE);
	cout << "��� 4 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 80; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(15, 33);
	cout << "80% �޼� (8/10)";

	gotoxy(70, 35);
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
	cout << "�� ���θ�ǥ ����";
	gotoxy(7, 14);
	cout << "�� ���α׷� ����";

	print_graph();
}