#pragma once
#include <string>

using namespace std;

class Detail
{
private:
	string context; // ���θ�ǥ�� ����
	bool cleared;  // ���θ�ǥ�� �޼� ����

public:
	Detail(string context, bool cleared);
	void setContext(string context);  // context�� ����
	void setCleared(bool cleared);  // cleared ����
	string getContext();  // context�� ��ȯ
	bool is_Cleared();  // cleared�� ��ȯ
};