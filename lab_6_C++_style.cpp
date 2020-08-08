#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	string text; //Строка
	string word, temp, big_glass;
	stringstream tx;
	string glass = "AaEeIiOoUuYy"; //Гласные буквы
	size_t len = 0;
	
	int c = 0; //Переменная для хранения количества слов
	
	cout << "Load text" << endl;
	
	getline(cin, text); //Ввод строки
	text = " " + text;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == ' ') {
			c++;
			if (text[i + 1] == ' ')
				c--;
		}
	} //Подсчет количества слов в строке
	
	text.erase(0, 1);
	cout << "Number of words: " << c << endl;
	tx << text;
	
	while (tx >> word) {
		temp = word;
		for (size_t i = 0; i < temp.length(); i++)
			if (glass.find(temp[i]) != std::string::npos)

				word += temp[i];
		if (word.length() - temp.length() > len) {
			len = word.length() - temp.length();
			big_glass = temp;
		}
	} //Поиск числа с наибольшим количеством гласных букв
	
	cout << "Biggest of vowels - " << big_glass << endl;
	
	int k, m;
	m = 0;
	
	for (int i = 0; i < text.length(); i++)
	{
	EX_SPACE:
		if (text[i] == ' ' && text[i + 1] == ' ')
		{
			k = i + 1;
			text.erase(k, 2);
			if (text[i + 2] == ' ')
				goto EX_SPACE;
		}
	} //Удаление лишних пробелов из текста

	cout << "Without excess spaces: " << endl;
	cout << text;
	return 0;
}