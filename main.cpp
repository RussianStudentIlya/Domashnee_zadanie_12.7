#include <iostream>
#include <string>
using namespace std;


string generated_string(string str, int k) /// ����� generated_string ��������� ������ ��� ������
{
	if (k > str.length()) return "������ �������� k > ����� ������.";
	string result;

	for (int i = 0; i < k; ++i) result += str[i];

	return result;
};

string IsKPeriodic(const string& text, int k)
{
	if (text.length() % k == 0) // �������� ����� �� ��������� ������ �� ������ �����
	{
		string substring = generated_string(text, k);
		string line = "", result = "";
		int count = 0, count_repeat = 0;

		for (int i = 0; i < text.length(); ++i)
		{
			line += text[i]; /// ����������� ������������ ������, ����� ������ ����� K
			++count;

			if (count == k)
			{
				if (line == substring) ++count_repeat; // ��������� ���������� �����
				line.clear();
				count = 0;
			}
		}
;
		
		if (count_repeat == text.length() / k) // �������� ��������� ����� ���������� ���������� ����� �����
		{
			result = "������ " + text + " ������ ����� � = " + to_string(k) + ", ������� �� ��������� = " + substring;
			return result;
		}
		else
		{
			result = "������ " + text + " �� ������ ����� � = " + to_string(k);
			return result;
		}
	}
	else
	{
		return "������, ������� ������ �� ������� �� ������ �����, K > ����� ������� ������.";
	}
};

int main()
{
	setlocale(LC_ALL, "rus");


	string text = "abcabcabcabc";

	cout << IsKPeriodic(text, 3) << endl; //����������� ��������� ���������:

	cout << endl;

	cout << IsKPeriodic(text, 2) << endl; // ������ ����� ������ �� ������ ����� �

	cout << endl;

	cout << IsKPeriodic(text, 15) << endl; // ������ ����� K > ����� ������� ������


}