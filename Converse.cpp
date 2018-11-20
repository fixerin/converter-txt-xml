#include <string>
using namespace std;
class Converse
{
	string doKonwersji;
	string poKonwersji;

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
		//cout << col << word << endcol << endl;
		txtPo += col;
		txtPo += word;
		txtPo += endcol;
		txtPo += '\n';

		return txtPo;
		
	}


	string convert2txt(string line) {
		string wynik = "";
		int start = 0;

		for (auto x : line) {
			if (x == '<') 
				start = 0;
			if (start == 1)
				wynik += x;
			if (x == '>'){
				start = 1;
				continue;
			}
				
		}
		return wynik;
	}

	string cXMLnaTXT(string line) {
		string row = "<row>";
		string endrow = "</row>";
		string col = "<col>";
		string endcol = "</col>";
		string txtPo;
		string word = "";
		int y;

		for (auto x : line) { // po kazdym znaku
			

			//if (word.substr(0, == '>') {
			//	word = word + x;
			//}
			if (word == row || word == col) {
				word = "";
				//txtPo = word;
				//txtPo += ' ';
				
			}
			else if (x == '<') {
				//word = word.substr(x - 2, x - 1);
				txtPo += word;
				//txtPo += ' ';
			}
			else if (word == endcol) {
				word += ' ';
			}
			else if (word == endrow) {
				word += '\n';
			}
			else {
				word = word + x;
			}
			

		}

		for (auto x : line) {

			if (word == row || word == col) {
				word = "";
				//txtPo = word;
				//txtPo += ' ';

			}

			if (x == '>') {
				while (x != '<') {
					word = word + x;
				}
			}



		}
		return txtPo;
	}

public:

	// Gettery i Settery
	string getDoKonwersji(){
		return doKonwersji;
	}

	string getPoKonwersji() {
		return poKonwersji;
	}

	void setDoKonwersji(string text) {
		doKonwersji = text;
	}

	void setPoKonwersji(string text) {
		poKonwersji = text;
	}
};

