// Dz_str.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

char* func(char* destination, const char* source1, const char* source2);

int main()
{
	std::ifstream in;    //поток для чтения
	std::ifstream outin; //
	std::ofstream out;   // поток для записи

	std::string path_in = "";
	std::string path_out = "";

	std::cout << "Enter the path of the input file: ";
	std::cin >> path_in;

	in.open(path_in);

	try {
		if (!in.is_open()) {
			throw "The file input is deleted or does not exist, program termination.\n";
		}
	}
	catch (const char* error) {
		std::cerr << error << "\n";
		exit(-1);
	}
	std::cout << "File input opened successfully\n";

	int MAX_SIZE = 0;

	try {
		in >> MAX_SIZE;
		if (in.peek() == '.' || in.peek() == ',' || !in.good() || MAX_SIZE <= 0) {
			throw "The maximum length of the string must be set as a positive integer, program termination.\n";
		}
	}
	catch (const char* error) {
		std::cerr << error << "\n";
		exit(-1);
	}

	MAX_SIZE = MAX_SIZE * 2 + 1;

	std::cout << "Enter the path of the output file: ";
	std::cin >> path_out;

	outin.open(path_out);

	try {
		if (!outin.is_open()) {
			throw "The file output is deleted or does not exist, program termination.\n";
		}
	}
	catch (const char* error) {
		std::cerr << error << "\n";
		exit(-1);
	}
	out.open(path_out);
	std::cout << "File output opened successfully\n";

	char* string1 = new char[MAX_SIZE];
	char* string2 = new char[MAX_SIZE];
	char* answer = new char[MAX_SIZE];
	in >> string1;
	in >> string2;

	std::cout << "Result: " << func(answer, string1, string2) << "\n";
	out << "Result: " << func(answer, string1, string2);

	delete[] string1;
	delete[] string2;
	delete[] answer;
	in.close();
	out.close();
	outin.close();
	return 0;

}

char* func(char* destination, const char* source1, const char* source2)
{
	int num = 0;
	int k = 0;
	int i = 0;
	int j = 0;
	while (source1[i] != '\0')
	{
		j = 0;
		k = 0;
		while (source2[j] != '\0')
		{
			if (source1[i] == source2[j])
			{
				k += 1;
			}
			j += 1;
		}
		if (k == 0)
		{
			destination[num] = source1[i];
			num = num + 1;
		}
		i += 1;

	}

	i = 0;
	j = 0;
	k = 0;
	while (source2[i] != '\0')
	{
		j = 0;
		k = 0;
		while (source1[j] != '\0')
		{
			if (source2[i] == source1[j])
			{
				k += 1;
			}
			j += 1;
		}
		if (k == 0)
		{
			destination[num] = source2[i];
			num += 1;
		}
		i += 1;
	}
	destination[num] = '\0';
	return destination;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
