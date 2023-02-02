#include <iostream>
#include <string>
using namespace std;


string generated_string(string str, int k) /// Метод generated_string формирует строку для поиска
{
	if (k > str.length()) return "Ошибка значение k > длины строки.";
	string result;

	for (int i = 0; i < k; ++i) result += str[i];

	return result;
};

string IsKPeriodic(const string& text, int k)
{
	if (text.length() % k == 0) // Проверка можно ли разделить строку на равные части
	{
		string substring = generated_string(text, k);
		string line = "", result = "";
		int count = 0, count_repeat = 0;

		for (int i = 0; i < text.length(); ++i)
		{
			line += text[i]; /// Формируется сравниваемая строка, длина строки равна K
			++count;

			if (count == k)
			{
				if (line == substring) ++count_repeat; // Проверяет совподение строк
				line.clear();
				count = 0;
			}
		}
;
		
		if (count_repeat == text.length() / k) // Проверка равенства числа совподение расчетнуму числу строк
		{
			result = "Строка " + text + " кратна числу К = " + to_string(k) + ", состоит из подстроки = " + substring;
			return result;
		}
		else
		{
			result = "Строка " + text + " не кратна числу К = " + to_string(k);
			return result;
		}
	}
	else
	{
		return "Ошибка, входная строка не делится на равные части, K > длины входной строки.";
	}
};

int main()
{
	setlocale(LC_ALL, "rus");


	string text = "abcabcabcabc";

	cout << IsKPeriodic(text, 3) << endl; //Стандартное поведение программы:

	cout << endl;

	cout << IsKPeriodic(text, 2) << endl; // Случай когда строка не кратна числу К

	cout << endl;

	cout << IsKPeriodic(text, 15) << endl; // Случай когда K > длины входной строки


}