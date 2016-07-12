#include <iostream>
#include <fstream>
#include <string.h>
#include <locale>
#include <vector>
#include <sstream>
#include <regex>
#include <dirent.h>

using namespace std;


class NormalizeDocum {   // класс для нормализации документов
private:

    string nameDir;
    string extNormDocum = ".norm";
    string extSearchFiles=".txt";
    vector<string> listFiles;
    vector<string> listDir;

public:

    NormalizeDocum(string );
    NormalizeDocum(){};
    int scanListFiles ();
    wchar_t cannonChar(wchar_t) ;
    int normalizeFiles();
    void setNameDir(string namedir) {nameDir = namedir;}
    int scanDir();
    vector<string> getListDir(){return listDir; }
    string getNameDir() { return nameDir;}
    vector<string> getListFiles()  {return listFiles; }
    ~NormalizeDocum(){};

};

