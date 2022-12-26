#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main() {

	vector<string> allElements;
	vector<string> allElementsSplited;

	map<string, int> wordMap;
	multimap<int, string> wordMapSorted;

	cout << "Write the adress of file..." << endl;
	string adres;
	cin >> adres;

	std::ifstream fin;
	fin.open(adres);

	if (!fin.is_open())
		std::cout << "Error from open the file" << std::endl;
	else {

		std::string line;
		while (!fin.eof()) {
			const size_t MAXLEN = 1000;
			getline(fin, line);
			char* text = _strdup(line.c_str());
			char* substr = strtok(text, ".,:!;? ");
			while (substr != 0)
			{
				string word = substr;
				// преобразование всех символов строки к нижнему регистру
				transform(word.begin(), word.end(), word.begin(), ::tolower);

				if (word.length() > 3) {
					auto it = wordMap.find(word);

					if (it != wordMap.end())
						wordMap[word] = it->second + 1;
					else
						wordMap.emplace(word, 1);
				}

				substr = std::strtok(NULL, ".,:!;? ");
			}
			allElements.push_back(line);
		}

	}

	fin.close();

	for (map<string, int>::iterator it = wordMap.begin(); it != wordMap.end(); it++) wordMapSorted.emplace(it->second, it->first);


	for (auto& i : wordMapSorted) if (i.first > 7) std::cout << i.second << " " << i.first << std::endl;

	return 0;
}