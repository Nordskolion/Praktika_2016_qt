#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <sstream>
#include "NormalizeDocum.h"
using namespace std;
typedef map <wstring,int> CountWords; // обьявление мэпов
typedef map <wstring,double> DfIdf;
typedef map <string,CountWords> FileCountWords;
typedef map <string,wstring> HelpToCountITF;
class ClassifyDocum
{
private:
	NormalizeDocum  * normalize; // сылка на класс нормалайза
	vector<CountWords> classCountWords; // считает слова в классе
	string nameDirClass; // дириктория класса
	string nameClass; // имя класса
	CountWords countWordsClass; // ассоциативный слово - кол-во в классе
	CountWords countWordsDocum; // ассоциативный слово - кол-во в документе
	FileCountWords fileCountWords;
	int countAllWords; // все слова в классе
	int countAllFiles; // все слова в файле
	vector<string> listFiles; // список файлов в классе
	DfIdf weightWordsClass;  //веса дф идф для КНН  заготовочка
	HelpToCountITF TermInDoc;
public:
	ClassifyDocum(string , string);
	ClassifyDocum(string , string , string);
	//~ClassifyDocum();
	void calculateWords(); // считает кол-во слова в классе , кол-во слов  , и записывает в мэп
	void calculateWeight(); // считает вес ( будут разные алгоритмы )
	double calculateDistance(ClassifyDocum );
	void whileCalculate(vector<ClassifyDocum *>);

	DfIdf  getWeightWordsClass(){return weightWordsClass;}
	string getName(){return nameClass;}


};
