#include "NormalizeDocum.h"



NormalizeDocum::NormalizeDocum(string namedir) { // конструктор  . Сразу нормализует все файлы в дириктории
    nameDir = namedir;
    extSearchFiles = ".txt";

}

int NormalizeDocum::scanListFiles () // функция открывает дерикторию и считывает в лист(вектор)
{
    DIR *dp;
    struct dirent *dirp;

    if((dp  = opendir(nameDir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << nameDir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        if(!strcmp( dirp->d_name, "." )) continue;
        if(!strcmp( dirp->d_name, ".." )) continue;
        if ( strstr( dirp->d_name, ".norm" )) continue;
        // cout<<dirp->d_name<<endl;

        if ( strstr( dirp->d_name, extSearchFiles.c_str() ))
        {

            listFiles.push_back(string(dirp->d_name));
        }
    }
    closedir(dp);
    return 0;
}

int NormalizeDocum::scanDir () // функция открывает дерикторию и считывает в лист(вектор)
{
    DIR *dp;
    struct dirent *dirp;

    if((dp  = opendir(nameDir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << nameDir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        if(!strcmp( dirp->d_name, "." )) continue;
        if(!strcmp( dirp->d_name, ".." )) continue;
        listDir.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}



int NormalizeDocum::normalizeFiles() // функция нормализация файла
{

    for (unsigned int i = 0;i < listFiles.size();i++)
    {

        string fullPathIn =  nameDir + listFiles[i];
        string fullPathOut =  nameDir + listFiles[i] + extNormDocum;
        wofstream fileIdWrite(fullPathOut);
        wifstream fileIdRead(fullPathIn);

        // cout<<fullPathIn<<"      "<<fullPathOut<<endl;
    wstring strInput;
    if (!fileIdRead)
    {
        // Ошибка октрытия файла
        cerr << "Файл : " << fullPathIn<< " не возможно октрыть !" << endl;
        exit(1);
    }
    if (!fileIdWrite)
    {
        // Ошибка октрытия файла
        cerr << "Файл : " << fullPathOut << " не возможно октрыть !" << endl;
        exit(1);
    }

    while (!fileIdRead.eof())
    {


        //getline(inf, strInput);
        fileIdRead>>strInput;
        wstring strChange;
        if(strInput.size() < 7) continue;           ///    отбрасываем слова меньше 4ех букв  ( чар = 2 байта   6=3 буквы )
        for(size_t i=0;i< strInput.size();i++) {
            if(cannonChar(strInput[i]) != '\0') {     //  пропускаем этот символ или нет
                strChange += cannonChar(strInput[i]);

            }
        }
        strChange += L' ';
        fileIdWrite<<strChange;
        // wcout <<"==========================="<<endl;
        // wcout <<strChange<<endl;



    }



    fileIdRead.close();
    fileIdWrite.close();



    }

    return 0;
}





wchar_t NormalizeDocum::cannonChar( wchar_t r) // функция замены и проверки букв на каноничность
{
 wchar_t res;
 switch (r)
 {
    //case L'А': res=L'а'; break;
    case L'Б': res=L'б'; break;
    case L'В': res=L'в'; break;
    case L'Г': res=L'г'; break;
    case L'Д': res=L'д'; break;
    //case L'Е': res=L'е'; break;
    case L'Ж': res=L'ж'; break;
    case L'З': res=L'з'; break;
    //case L'И': res=L'и'; break;
    ///case L'Й': res=L'й'; break;
    case L'К': res=L'к'; break;
    case L'Л': res=L'л'; break;
    case L'М': res=L'м'; break;
    case L'Н': res=L'н'; break;
    //case L'О': res=L'о'; break;
    case L'П': res=L'п'; break;
    case L'Р': res=L'р'; break;
    case L'С': res=L'с'; break;
    case L'Т': res=L'т'; break;
    //case L'У': res=L'у'; break;
    case L'Ф': res=L'ф'; break;
    case L'Х': res=L'х'; break;
    case L'Ц': res=L'ц'; break;
    case L'Ч': res=L'ч'; break;
    case L'Ш': res=L'ш'; break;
    case L'Щ': res=L'щ'; break;
    //case L'Ъ': res=L'ъ'; break;
    //case L'Ы': res=L'ы'; break;
    //case L'Ь': res=L'ь'; break;
    //case L'Э': res=L'э'; break;
    //case L'Ю': res=L'ю'; break;
    //case L'Я': res=L'я'; break;

    //case L'а': res=L'а'; break;
    case L'б': res=L'б'; break;
    case L'в': res=L'в'; break;
    case L'г': res=L'г'; break;
    case L'д': res=L'д'; break;
    //case L'е': res=L'е'; break;
    case L'ж': res=L'ж'; break;
    case L'з': res=L'з'; break;
    //case L'и': res=L'и'; break;
    //case L'й': res=L'й'; break;
    case L'к': res=L'к'; break;
    case L'л': res=L'л'; break;
    case L'м': res=L'м'; break;
    case L'н': res=L'н'; break;
    //case L'о': res=L'о'; break;
    case L'п': res=L'п'; break;
    case L'р': res=L'р'; break;
    case L'с': res=L'с'; break;
    case L'т': res=L'т'; break;
    //case L'у': res=L'у'; break;
    case L'ф': res=L'ф'; break;
    case L'х': res=L'х'; break;
    case L'ц': res=L'ц'; break;
    case L'ч': res=L'ч'; break;
    case L'ш': res=L'ш'; break;
    case L'щ': res=L'щ'; break;
    case L'ъ': res=L'ъ'; break;
    //case L'ы': res=L'ы'; break;
    //case L'ь': res=L'ь'; break;
    //case L'э': res=L'э'; break;
    //case L'ю': res=L'ю'; break;
    //case L'я': res=L'я'; break;

    //case L'A': res=L'a'; break;
    //case L'Q': res=L'q'; break;
    case L'W': res=L'w'; break;
    //case L'E': res=L'e'; break;
    case L'R': res=L'r'; break;
    case L'T': res=L't'; break;
    //case L'Y': res=L'y'; break;
    //case L'U': res=L'u'; break;
    //case L'I': res=L'i'; break;
    //case L'O': res=L'o'; break;
    case L'P': res=L'p'; break;
    case L'S': res=L's'; break;
    case L'D': res=L'd'; break;
    case L'F': res=L'f'; break;
    case L'G': res=L'g'; break;
    case L'H': res=L'h'; break;
    //case L'J': res=L'j'; break;
    case L'K': res=L'k'; break;
    case L'L': res=L'l'; break;
    case L'Z': res=L'z'; break;
    case L'X': res=L'x'; break;
    case L'C': res=L'c'; break;
    case L'V': res=L'v'; break;
    case L'B': res=L'b'; break;
    case L'N': res=L'n'; break;
    case L'M': res=L'm'; break;

    //case L'a': res=L'a'; break;
    //case L'q': res=L'q'; break;
    case L'w': res=L'w'; break;
    //case L'e': res=L'e'; break;
    case L'r': res=L'r'; break;
    case L't': res=L't'; break;
    //case L'y': res=L'y'; break;
    //case L'u': res=L'u'; break;
    //case L'i': res=L'i'; break;
    //case L'o': res=L'o'; break;
    case L'p': res=L'p'; break;
    case L's': res=L's'; break;
    case L'd': res=L'd'; break;
    case L'f': res=L'f'; break;
    case L'g': res=L'g'; break;
    case L'h': res=L'h'; break;
    //case L'j': res=L'j'; break;
    case L'k': res=L'k'; break;
    case L'l': res=L'l'; break;
    case L'z': res=L'z'; break;
    case L'x': res=L'x'; break;
    case L'c': res=L'c'; break;
    case L'v': res=L'v'; break;
    case L'b': res=L'b'; break;
    case L'n': res=L'n'; break;
    case L'm': res=L'm'; break;

    case L'-': res=L' '; break;
    default: res='\0';
 }

 return (res);
}
