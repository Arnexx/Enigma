#include <iostream>
#include <fstream>
#include "Enigma.h"
using namespace std;

void incVector(vector<int> &vec)
{
	vec[2]++;
	if (vec[2] == 26)
	{
		vec[2] = 0;
		vec[1]++;
		if (vec[1] == 26)
		{
			vec[1] = 0;
			vec[0]++;
			if (vec[0] == 26)
			{
				vec[0] = vec[1] = vec[2] = 0;
			}
		}
	}
}

float countIndex(vector<int> &vec, int n) {
	vector<int> alphabet;
	alphabet.clear();
	float index = 0;
	alphabet.resize(26);
	for (int i = 0; i < 61; i++)
	{
		alphabet[vec[i]]++;
	}

	for (int i = 0; i < 26; i++)
	{
		index += float(alphabet[i] * (alphabet[i] - 1) / float(n*(n-1)));
	}
	return index;
}

int main1() {
	Enigma enigma;
	vector<int> positions(3, 0);
	string plainText = "ADHOCADLOCQUIDPROQUOSOLITTLETIMESOMUCHTOKNOW";
	string cipherText = "SWZSOFCJMDCVUGELHSMBGGNBSMQTQZIYDDXKYNEWJKZR";
	int index = 0;
	bool pass = true;
	int temp;

	while (index < 17580) {

		enigma.setPosition(positions[0], positions[1], positions[2]);

		for (int i = 0; i < plainText.length(); i++)
		{
			temp = enigma.encrypt(plainText[i]);
			if ((cipherText[i] - 65) != temp)
				pass = false;
			//cout << char(temp + 65);
			

		}
		cout << endl;
		if (pass)
		{
			cout << char(positions[0] + 65) << "  " << char(positions[1] + 65) << "  " << char(positions[2] + 65);
			break;
		}
		incVector(positions);
		index++;
		pass = true;
	}
	system("pause");
	return 0;
}

void findText() {
	vector<string> strings, words, foundWords;
	string line, word;
	ifstream enigmaOut, dictionary;
	ofstream out;
	enigmaOut.open("enigmaOut.txt");
	dictionary.open("dictionary.txt");
	out.open("out.txt");

	if (enigmaOut.is_open())
	{
		while (getline(enigmaOut, line))
		{
			strings.push_back(line);
		}
		enigmaOut.close();
	}


	if (dictionary.is_open()) 
	{
		while (dictionary >> word)
		{
			for (auto & c : word) c = toupper(c);
			words.push_back(word);
		}
		dictionary.close();
	}
	std::size_t found;
	for (string str : strings) {
		int totalFound = 0;
		foundWords.clear();
		for (string temp : words) {
			if (temp.length() < 4)
				continue;
			found = str.find(temp);
			if (found != std::string::npos)
			{
				foundWords.push_back(temp);
				totalFound++;
			}
		}

		if (totalFound > 5)
		{
			out << str << "   ";
			for (int i = 0; i < totalFound; i++)
				out << foundWords[i] << "  ";
			out << endl;
		}
	}
	out.close();
}

int main() {

	Enigma enigma;
	vector<int> positions(3, 0);
	string cipherText = "ERLORYROGGPBIMYNPRMHOUQYQETRQXTYUGGEZVBFPRIJGXRSSCJTXJBMWJRRPKRHXYMVVYGNGYMHZURYEYYXTTHCNIRYTPVHABJLBLNUZATWXEMKRIWWEZIZNBEOQDDDCJRZZTLRLGPIFYPHUSMBCAMNODVYSJWKTZEJCKPQYYNZQKKJRQQHXLFCHHFRKDHHRTYILGGXXVBLTMPGCTUWPAIXOZOPKMNRXPMOAMSUTIFOWDFBNDNLWWLNRWMPWWGEZKJNH";
	float maxIndex = 0, index = 0;
	vector<int> tempText;
	ofstream enigmaOut;
	/*enigmaOut.open("enigmaOut.txt", ios::out);

	tempText.resize(cipherText.length());
	
	for (int j = 0; j < 20580; j++)
	{
		enigma.setPosition(positions[0], positions[1], positions[2]);

		for (int i = 0; i < cipherText.length(); i++)
		{
			tempText[i] = enigma.encrypt(cipherText[i]);
		}

		enigmaOut << char(positions[0] + 65) << char(positions[1] + 65) << char(positions[2] + 65) << " " << index << " ";

		for (int i = 0; i < cipherText.length(); i++)
		{
			enigmaOut << char(tempText[i] + 65);
		}

		enigmaOut << endl;
		index = countIndex(tempText, cipherText.length());
		if (maxIndex < index)
		{
			maxIndex = index;
			
		}
		incVector(positions);

	}
	enigmaOut.close();*/

	findText();
	system("pause");
	return 0;
}