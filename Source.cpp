#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <iomanip>

using namespace std;



class Converse
{
public:
	//metoda do konwersji pliku txt na xml
	string cTXTnaXML(string linia) {
		string row = "<row>";
		string endrow = "</row>";
		string col = "<col>";
		string endcol = "</col>";
		string txtPo;
		string word = "";

		for (auto x : linia)
		{

			if (x == ' ')
			{
				txtPo += col;
				txtPo += word;
				txtPo += endcol;
				txtPo += '\n';
				word = "";

			}
			else
			{
				word = word + x;
			}

		}

		txtPo += col;
		txtPo += word;
		txtPo += endcol;
		txtPo += '\n';

		return txtPo;

	}

	//metoda do konwersji pliku XML na TXT
	
	string cXMLnaTXT(string line) {
		string txt = "";
		int start = 0;

		for (auto x : line) { // petla wyszukuje znakow '>' i '<' by polaczyc pojedyncze znaki w txt miedzy nimi
			if (x == '<')
				start = 0;
			if (start == 1)
				txt += x;
			if (x == '>') {
				start = 1;
				continue;
			}

		}
		return txt;
	}

public:
};

int main() {
	string line;
	int sum = 0;
	cout << "Welcome\n";
	int x;
	ifstream inFile; //Deklaruje plik do odczytu
	ofstream outFile; // deklaruje i tworzy nowy plik w floderze projektu
	string filename; // nazwa pliku do odczytu
	string outFilename;
	string ending;
	string budowaPliku, wynikXML = "";
	int y = 0;
	Converse obiekt;



	cout << "Type name of file to convert: ";
	cin >> filename; 
	cout << endl;

	inFile.open(filename);

	while (!inFile) {
		cout << "Unable to open file " << filename << "\n";
		cout << "Type file name properly: ";
		cin >> filename;
		cout << "\n";
		inFile.open(filename);
	}

	x = filename.length();
	cout << "To jest dlugosc nazwy: " << x << "\n";
	ending = filename.substr(x - 4, x - 1);
	cout << "To jest koncowka nazwy: " << ending << "\n";
	
	//Sprawdzenie koñcówki pliku
	if (ending == ".txt") {
		outFilename = filename.substr(0, x - 4) + ".xml";

		outFile.open(outFilename);

		while (getline(inFile, line)) {
			string row = "<row>";
			string endrow = "</row>";

			
			if (outFile.is_open()) {

				budowaPliku += row;
				budowaPliku += '\n';
				budowaPliku += obiekt.cTXTnaXML(line);
				budowaPliku += endrow;
				budowaPliku += '\n';
			}
			else {
				cout << "Unable to open file";
			}
		}

	}

	else if (ending == ".xml") {
		outFilename = filename.substr(0, x - 4) + ".txt";

		outFile.open(outFilename);

		while (getline(inFile, line)) { // po kazdej lini
			string endrow = "</row>";

			if (line == endrow) {
				x = budowaPliku.length();
				budowaPliku = budowaPliku.substr(0, x - 1);
				//budowaPliku -= ' ';
				budowaPliku += '\n';
			}
			budowaPliku += obiekt.cXMLnaTXT(line);

			if (line.find("</col>") != string::npos){
				budowaPliku += ' ';
			}
			
		}
		cout << budowaPliku;
		x = budowaPliku.length();
		budowaPliku = budowaPliku.substr(0, x - 1);
	}

	else {
		cout << "Brak mozliwosci wykonania konwersji na pliku tego typu.";
	}

	cout << "to jest nowy plik: " << outFilename << "\n";


	outFile << budowaPliku;  //wpisuje stworzony string do pliku

	//zamyka pliki
	outFile.close();
	inFile.close();

	if (ending == ".txt") {
		outFilename = filename.substr(0, x - 4) + ".xml";
		//ofstream outFile(outFilename);
	}


	system("pause");

	
}

