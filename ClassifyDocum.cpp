#include "ClassifyDocum.h"
#include <math.h>


ClassifyDocum::ClassifyDocum(string nameclass ,string namedirclass) // конструктор , сразу нормализует документы
{
	countAllWords = 0;
	nameClass=nameclass;
	nameDirClass = namedirclass;
	normalize = new NormalizeDocum(nameDirClass);
	normalize->scanListFiles();
	normalize->normalizeFiles();
	listFiles = normalize->getListFiles();
	countAllFiles = listFiles.size();
	calculateWords();
	calculateWeight();
	cout<<listFiles.size()<<endl;

}

ClassifyDocum::ClassifyDocum(string nameclass ,string namedirclass , string namedoc ) // конструктор , сразу нормализует документы
{
	countAllWords = 0;
	nameClass=nameclass;
	nameDirClass = namedirclass;
	normalize = new NormalizeDocum(nameDirClass);
	normalize->scanListFiles();
	normalize->normalizeFiles();
	listFiles.push_back(namedoc);
	countAllFiles = listFiles.size();
	calculateWords();
	calculateWeight();
	cout<<listFiles.size()<<endl;

}





void ClassifyDocum::calculateWords() //читать класс
{
	cout<<getName()<<"  "<<listFiles.size()<<endl;
	 for(size_t i=0; i<listFiles.size();i++)
	{
      	wifstream fileId(nameDirClass+listFiles[i]+".norm");
        wstring strInput;
        while(fileId>>strInput)
        {
        	++fileCountWords[listFiles[i]][strInput];
             ++countWordsClass[strInput];
             countAllWords++;
			 // TermInDoc.insert(pair<string,wstring>(listFiles[i].c_str(),strInput.c_str()));         
         }
         fileId.close();
         classCountWords.push_back(countWordsClass);
         // fileCountWords.
    }

    for (CountWords::iterator p = countWordsClass.begin(); p != countWordsClass.end(); ++p) {
                      // wcout << p->first << ": " << p->second << '\n';
         }
}

void ClassifyDocum::calculateWeight()//Вес
{
	cout.precision(17);
	double j;
	for(CountWords::iterator p = countWordsClass.begin(); p != countWordsClass.end(); ++p)
	{
		// cout << j<< "  " << p->second <<endl;
	
		j = (double)p->second/countAllWords;
		 // j = p->second;
		weightWordsClass.insert(pair<wstring,double>(p->first,j));

	}
	 for (DfIdf::iterator p = weightWordsClass.begin(); p != weightWordsClass.end(); ++p) {
                      	 wcout << p->first << ": " << p->second << '\n' ;
         }
}
double ClassifyDocum::calculateDistance(ClassifyDocum theme)
{
	double x = 0;
	double y = 0;
	int countCondition = 0;
	DfIdf weight1 = theme.getWeightWordsClass();

	for (DfIdf::iterator k = weightWordsClass.begin(); k != weightWordsClass.end(); ++k) {
            			if(weight1[k->first])
                      	{                        
                        	x = (double)(x+(double)((k->second)+weight1[k->first]));
                        	// y = (double)(y+(double)((k->second)-(weight1[k->first]))*(double)(((k->second)-(weight1[k->first]))	));
                        	countCondition++;
                        	// wcout << theme.getName().c_str() << "  "<< p->first <<  " ======= "<< p->second << '\n' ;
                        	// wcout <<  weight1[k->first] << "  "<< k->first <<" ======= "<<k->second << '\n' ;
                        }
					}
	x = (double)x/2;
	// y = (double)sqrt(y);
	 wcout << "========================================X::"   << x << "   " << theme.getName().c_str() << "    " << nameClass.c_str() <<endl;
	 // wcout << "========================================Y::"   << y << "   " << theme.getName().c_str() << "    " << nameClass.c_str() <<endl;
	
	return x;
}

// void whileCalculate(string rootDirDocum,string rootDirEdu )
// {
// 	NormalizeDocum dirEdu(rootDirEdu);
//     NormalizeDocum dirDocum(rootDirDocum);
//     dirDocum.scanListFiles();
//     vector<string> listFiles=dirDocum.getListFiles();
//     dirEdu.scanDir();

//     vector<string> files = dirEdu.getListDir();
//     vector<ClassifyDocum *> classEdu;
//      for(size_t i=0; i < files.size(); i++)
//     {
//      classEdu.push_back(new ClassifyDocum(files[i],rootDirEdu+files[i]+"/"));
//     } 

//     for (size_t i = 0; i<listFiles.size(); i++)
//     {
//     	ClassifyDocum docum(listFiles[i] , rootDirDocum+listFiles[i]);
    
//     ClassifyDocum classDocum("Docum",rootDirDocum); 

//     for(size_t i=0; i < classEdu.size(); i++)
//     {
//      docum.calculateDistance(*classEdu[i]);
//     }
// 	}

   
