#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

vector<string> cutWord(string data, int &counts){

    vector<string> arr;
    char *s = const_cast<char *> (data.c_str());
    char * pch;
    pch = strtok (s,".,:;`'/+-(){}[]<>*&^%$#@!?~/\\= \r\t\n1234567890");
    while (pch != NULL)
    {
        arr.push_back(pch);
        counts++;
        pch = strtok(NULL, ".,:;`'/+-(){}[]<>*&^%$#@!?~/\\= \r\t\n1234567890");
    }

    return arr;
}

vector<string> cutWordGramer2(string data, int &c){
    int tmpInt = 0;
    vector<string> tmp = cutWord(data, tmpInt);

    vector<string> arr;

    string _tmp;
    for(int i = 1; i < tmpInt; i++){
        _tmp += tmp[i-1] + " " + tmp[i];
        arr.push_back(_tmp);
        _tmp = "";
        c++;
    }

    return arr;
}

vector<string> cutWordGramer3(string data, int &c){
    int tmpInt = 0;
    vector<string> tmp = cutWord(data, tmpInt);

    vector<string> arr;

    string _tmp;
    for(int i = 2; i < tmpInt; i++){
        _tmp += tmp[i-2] + " " + tmp[i-1] + " " + tmp[i] ;
        arr.push_back(_tmp);
        _tmp = "";
        c++;
    }

    return arr;
}

string _readk(string name, const char* nameFile){
    fstream f;
    string str = (string)nameFile;
	f.open(str+name, ios::in);

	string data;

	string line;
	while (!f.eof())
	{
		getline(f, line);
		data += line;
	}

	f.close();

	for (int i = 0; i < (int)data.length(); i++){
        if ('A' <= data[i] && data[i] <= 'Z'){
            data[i] = (char)((int)data[i] + 32);
        }
    }

    return data;
}

vector<string> EnumerateFolders (const char* nameFile)
{
    vector<string> file;

    WIN32_FIND_DATA fd;
    char folder[MAX_PATH];
    sprintf(folder, "%s\\*.*", nameFile);

    HANDLE hFind = FindFirstFile (folder, &fd);

    if (hFind != INVALID_HANDLE_VALUE)
    {
        do {
            if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                if (strcmp(fd.cFileName, ".") && strcmp(fd.cFileName, ".."))
                {
                    printf ("%s\\%s\n", nameFile, fd.cFileName);
                    char child[MAX_PATH];

                    sprintf(child, "%s\\%s", nameFile, fd.cFileName);
                    EnumerateFolders (child);
                }
            }
            else
            {
                //printf("%s\n", fd.cFileName);
                file.push_back(fd.cFileName);
            }
        } while (FindNextFile (hFind, &fd));
        FindClose (hFind);
    }

    return file;
}

vector<bool> Denomination(int b){
    vector<bool> arr;
    for(int i = 0; i < b; i++){
        arr.push_back(true);
    }

    return arr;
}
void _CompareGamer1(string a, string b, vector<int> &c, vector<string> &d, int &v, const char* nameFile){
    int _counts = 0;
    int __counts = 0;

    vector<string> Arr = cutWord(_readk(a, nameFile), _counts);
    vector<string> Brr = cutWord(_readk(b, nameFile), __counts);

    int ___counts = 0;

    if (_counts < __counts){
        vector<bool>tmp = Denomination(_counts);

        for (int i = 0; i < __counts; i++){
            for (int j = 0; j < _counts; j++){
                if(tmp[j] == true){
                    if (Brr[i] == Arr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }
    else{
        vector<bool>tmp = Denomination(__counts);

        for (int i = 0; i < _counts; i++){
            for (int j = 0; j < __counts; j++){
                if(tmp[j] == true){
                    if (Arr[i] == Brr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }

    v++;
}

void _CompareGamer2(string a, string b, vector<int> &c, vector<string> &d, int &v, const char* nameFile){
    int _counts = 0;
    int __counts = 0;

    vector<string> Arr = cutWordGramer2(_readk(a, nameFile), _counts);
    vector<string> Brr = cutWordGramer2(_readk(b, nameFile), __counts);

    int ___counts = 0;

    if (_counts < __counts){
        vector<bool>tmp = Denomination(_counts);

        for (int i = 0; i < __counts; i++){
            for (int j = 0; j < _counts; j++){
                if(tmp[j] == true){
                    if (Brr[i] == Arr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }
    else{
        vector<bool>tmp = Denomination(__counts);

        for (int i = 0; i < _counts; i++){
            for (int j = 0; j < __counts; j++){
                if(tmp[j] == true){
                    if (Arr[i] == Brr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }

    v++;
}

void _CompareGamer3(string a, string b, vector<int> &c, vector<string> &d, int &v, const char* nameFile){
    int _counts = 0;
    int __counts = 0;

    vector<string> Arr = cutWordGramer3(_readk(a, nameFile), _counts);
    vector<string> Brr = cutWordGramer3(_readk(b, nameFile), __counts);

    int ___counts = 0;

    if (_counts < __counts){
        vector<bool>tmp = Denomination(_counts);

        for (int i = 0; i < __counts; i++){
            for (int j = 0; j < _counts; j++){
                if(tmp[j] == true){
                    if (Brr[i] == Arr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }
    else{
        vector<bool>tmp = Denomination(__counts);

        for (int i = 0; i < _counts; i++){
            for (int j = 0; j < __counts; j++){
                if(tmp[j] == true){
                    if (Arr[i] == Brr[j]){
                        ___counts++;
                        tmp[j] = false;
                        break;
                    }
                }
            }
        }

        c.push_back(___counts);
        string _tmp = a;
        _tmp += " ";
        _tmp += b;
        d.push_back(_tmp);
    }

    v++;
}

void compareGramer1(vector<int> &a, vector<string> &b, int &c, const char* nameFile){
    vector<string> fileName = EnumerateFolders(nameFile);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamer1(fileName[i], fileName[j], a, b, c, nameFile);
        }
    }
}

void compareGramer2(vector<int> &a, vector<string> &b, int &c, const char* nameFile){
    vector<string> fileName = EnumerateFolders(nameFile);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamer2(fileName[i], fileName[j], a, b, c, nameFile);
        }
    }
}

void compareGramer3(vector<int> &a, vector<string> &b, int &c, const char* nameFile){
    vector<string> fileName = EnumerateFolders(nameFile);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamer3(fileName[i], fileName[j], a, b, c, nameFile);
        }
    }
}

void CompareVector(const char* grams,const char* b, const char* nameFile){
    vector<int> _tmpCount;
    vector<string> _tmpFile;
    int number = atoi(b);

    int _countss = 0;
    if ((string)grams == "1"){
        compareGramer1(_tmpCount, _tmpFile, _countss, nameFile);
    }
    else if((string)grams  == "2"){
        compareGramer2(_tmpCount, _tmpFile, _countss, nameFile);
    }
    else if((string)grams  == "3"){
        compareGramer3(_tmpCount, _tmpFile, _countss, nameFile);
    }
    else if ((string)grams  == "1-2"){
        vector<int> _tmpCounts;
        vector<string> _tmpFiles;
        int _countsss = 0;

        compareGramer1(_tmpCount, _tmpFile, _countss, nameFile);
        compareGramer2(_tmpCounts, _tmpFiles, _countsss, nameFile);

        for (int i = 0; i < _countss; i++){
            _tmpCount[i] += _tmpCounts[i];
        }
    }
    else if ((string)grams  == "2-3"){
        vector<int> _tmpCounts;
        vector<string> _tmpFiles;
        int _countsss = 0;

        compareGramer2(_tmpCount, _tmpFile, _countss, nameFile);
        compareGramer3(_tmpCounts, _tmpFiles, _countsss, nameFile);

        for (int i = 0; i < _countss; i++){
            _tmpCount[i] += _tmpCounts[i];
        }
    }
    else if ((string)grams  == "1-3"){
        vector<int> _tmpCounts;
        vector<string> _tmpFiles;
        int _countsss = 0;

        vector<int> _tmpCountss;
        vector<string> _tmpFiless;
        int _countssss = 0;

        compareGramer1(_tmpCount, _tmpFile, _countss, nameFile);
        compareGramer2(_tmpCounts, _tmpFiles, _countsss, nameFile);
        compareGramer3(_tmpCountss, _tmpFiless, _countssss, nameFile);

        for (int i = 0; i < _countss; i++){
            _tmpCount[i] = _tmpCount[i] + _tmpCounts[i] + _tmpCountss[i];
        }
    }
    string tmpString;
    int tmpInt;

    for (int i = 0; i < _countss; i++){
        for (int j = i; j < _countss; j++){
            if (_tmpCount[i] < _tmpCount[j]){
                tmpInt = _tmpCount[i];
                _tmpCount[i] = _tmpCount[j];
                _tmpCount[j] = tmpInt;

                tmpString = _tmpFile[i];
                _tmpFile[i] = _tmpFile[j];
                _tmpFile[j] = tmpString;
            }
        }
    }

    if (number == -1){
        for (int i = 0; i < _countss; i++){
            cout << _tmpFile[i] << " " << _tmpCount[i] << endl;
        }
    }
    else{
        for (int i = 0; i < number; i++){
            cout << _tmpFile[i] << " " << _tmpCount[i] << endl;
        }
    }
}

// map

map<string,int> cutWordMap(string data, int &counts){
    map<string,int> mapa;
    map<string,int>::iterator it;
    vector<string> _tmp;

    char *s = const_cast<char *> (data.c_str());
    char * pch;
    pch = strtok(s,".,:;`'/+-(){}[]<>*&^%$#@!?~/\\= \r\t\n1234567890");

    while (pch != NULL)
    {
        mapa.insert(pair<string,int> (pch,0));
        _tmp.push_back(pch);
        counts++;
        pch = strtok(NULL, ".,:;`'/+-(){}[]<>*&^%$#@!?~/\\= \r\t\n1234567890");
    }

    for (int i = 0; i < counts; i++){
        mapa[_tmp[i]]++;
    }

    return mapa;
}

void _CompareGamerMap1(string a, string b, vector<int> &c, vector<string> &d, const char* nameFile){
    int _counts = 0;
    int __counts = 0;

    map<string,int> Arr = cutWordMap(_readk(a, nameFile),_counts);
    vector<string> Brr = cutWord(_readk(b, nameFile),__counts);

    int ___counts = 0;

    for (int i = 0; i < __counts; i++){
        if (Arr[Brr[i]] != 0){
            Arr[Brr[i]]--;
            ___counts++;
        }
    }
    c.push_back(___counts);
    d.push_back(a + " " + b);
}

void _CompareGamerMap2(string a, string b, vector<int> &c, vector<string> &d, const char* nameFile){

    int _counts = 0;
    int __counts = 0;
    vector<string> Brr = cutWord(_readk(b,nameFile), __counts);
    vector<string> brr;
    vector<string> arr = cutWord(_readk(a,nameFile),_counts);
    map<string,int> Arr;

    vector<string> tmp;
    string _tmp;
    for (int i = 1; i < _counts; i++){
        tmp.push_back(arr[i-1] + " " + arr[i]);
        _tmp = tmp[i-1];
        Arr[_tmp]++;
    }

    for (int i = 1; i < __counts; i++){
        brr.push_back(Brr[i-1] + " " + Brr[i]);
    }

    int ___counts = 0;

    for (int i = 0; i < (int)brr.size(); i++){
        if (Arr[brr[i]] != 0){
            Arr[brr[i]]--;
            ___counts++;
        }
    }

    c.push_back(___counts);
    d.push_back(a + " " + b);
}

void _CompareGamerMap3(string a, string b, vector<int> &c, vector<string> &d, const char* nameFile){

    int _counts = 0;
    int __counts = 0;
    vector<string> Brr = cutWord(_readk(b, nameFile), __counts);
    vector<string> brr;
    vector<string> arr = cutWord(_readk(a, nameFile),_counts);
    map<string,int> Arr;

    vector<string> tmp;
    string _tmp;
    for (int i = 2; i < (int)arr.size(); i++){
        tmp.push_back(arr[i-2] + " " + arr[i-1] + " " + arr[i]);
        _tmp = tmp[i-2];
        Arr[_tmp]++;
    }

    for (int i = 2; i < __counts; i++){
        brr.push_back(Brr[i-2] + " " + Brr[i-1] + " " + Brr[i]);
    }

    int ___counts = 0;

    for (int i = 0; i < (int)brr.size(); i++){
        if (Arr[brr[i]] != 0){
            Arr[brr[i]]--;
            ___counts++;
        }
    }

    c.push_back(___counts);
    d.push_back(a + " " + b);
}

void compareGramerMap1(vector<int> &Arr, vector<string> &Brr, const char* nameFile){
    vector<string> fileName = EnumerateFolders(nameFile);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamerMap1(fileName[i], fileName[j], Arr, Brr, nameFile);
        }
    }
}

void compareGramerMap2(vector<int> &Arr, vector<string> &Brr,const char* nameFile){
    vector<string> fileName = EnumerateFolders(nameFile);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamerMap2(fileName[i], fileName[j], Arr, Brr, nameFile);
        }
    }
}

void compareGramerMap3(vector<int> &Arr, vector<string> &Brr, const char* nameFile){
    vector<string> fileName = EnumerateFolders(nameFile);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamerMap3(fileName[i], fileName[j], Arr, Brr, nameFile);
        }
    }
}

void CompareMap(const char* grams, const char* b, const char* nameFile){
    vector<int> Arr;
    vector<string> Brr;

    int number = atoi(b);

    int tmp;
    string _tmp;

    if ( (string)grams == "1"){
        compareGramerMap1(Arr, Brr, nameFile);
    }
    else if ((string)grams == "2"){
        compareGramerMap2(Arr, Brr, nameFile);
    }
    else if ((string)grams == "3"){
        compareGramerMap3(Arr, Brr, nameFile);
    }
    else if ((string)grams == "1-2"){
        vector<int> _Arr;
        vector<string> _Brr;
        compareGramerMap1(Arr, Brr, nameFile);
        compareGramerMap2(_Arr, _Brr, nameFile);

        for (int i = 0; i < 300; i++){
            Arr[i] += _Arr[i];
        }
    }
    else if( (string)grams == "2-3"){
        vector<int> _Arr;
        vector<string> _Brr;
        compareGramerMap2(Arr, Brr, nameFile);
        compareGramerMap3(_Arr, _Brr, nameFile);

        for (int i = 0; i < 300; i++){
            Arr[i] += _Arr[i];
        }
    }
    else if ((string)grams == "1-3"){
        vector<int> _Arr;
        vector<string> _Brr;
        vector<int> __Arr;
        vector<string> __Brr;
        compareGramerMap2(Arr, Brr, nameFile);
        compareGramerMap2(_Arr, _Brr, nameFile);
        compareGramerMap3(__Arr, __Brr, nameFile);

        for (int i = 0; i < 300; i++){
            Arr[i] += _Arr[i] + __Arr[i];
        }
    }
    for (int i = 0; i < 300; i++){
        for (int j = i; j < 300; j++){
            if(Arr[i] < Arr[j]){
                tmp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = tmp;

                _tmp = Brr[i];
                Brr[i] = Brr[j];
                Brr[j] = _tmp;
            }
        }
    }

    if (number == -1){
        for (int i = 0; i < 300; i++){
            cout << Brr[i] << " " << Arr[i] << endl;
        }
    }
    else{
        for (int i = 0; i < number; i++){
            cout << Brr[i] << " " << Arr[i] << endl;
        }
    }
}

// tree

typedef struct nodeTree
{
    int index = 0;
    string data;
    nodeTree* left;
    nodeTree* right;
} node_t;

node_t* _insert(node_t* &r,string x)
{
    if(r == NULL)
    {
        node_t* n = new nodeTree;
        n->data = x;
        (n->index)++;
        n->left = NULL;
        n->right = NULL;
        r = n;
    }
    else
    {

        if((r->data.compare(x)) > 0)
        {
            _insert(r->left,x);
        }
        else
        {
            _insert(r->right,x);
        }
    }
}

bool Search( node_t* &root, string value )
{
    if ( root == NULL )
        return false;
    if((root->data.compare(value)) == 0 && root->index >=1)
    {
        (root->index)--;
        return true;
    }
    else if ((root->data.compare(value)) > 0)
    {
        return Search( root->left, value );
    }
    else if( (root->data.compare(value)) <= 0 )
    {
        return Search( root->right, value );
    }
}

void _CompareGamerTree1(string a, string b, vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    node_t* root = NULL;
    int score = 0;
    int s = 0;

    vector<string> arr = cutWord(_readk(a, nameFileS), s);
    vector<string> arr1 = cutWord(_readk(b, nameFileS), s);

    for (int i = 0; i < (int)arr.size(); i++){
        _insert(root, arr[i]);
    }

    for (int i = 0; i < (int)arr1.size(); i++){
        if(Search(root,arr1[i]) == true){
            score++;
        }
    }

    result.push_back(score);
    nameFile.push_back(a + " " + b);
}

void _CompareGamerTree2(string a, string b, vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    node_t* root = NULL;
    int score = 0;
    int s = 0;

    vector<string> arr = cutWordGramer2(_readk(a, nameFileS), s);
    vector<string> arr1 = cutWordGramer2(_readk(b, nameFileS), s);

    for (int i = 0; i < (int)arr.size(); i++){
        _insert(root, arr[i]);
    }

    for (int i = 0; i < (int)arr1.size(); i++){
        if(Search(root,arr1[i]) == true){
            score++;
        }
    }

    result.push_back(score);
    nameFile.push_back(a + " " + b);
}

void _CompareGamerTree3(string a, string b, vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    node_t* root = NULL;
    int score = 0;
    int s = 0;

    vector<string> arr = cutWordGramer3(_readk(a, nameFileS), s);
    vector<string> arr1 = cutWordGramer3(_readk(b, nameFileS), s);

    for (int i = 0; i < (int)arr.size(); i++){
        _insert(root, arr[i]);
    }

    for (int i = 0; i < (int)arr1.size(); i++){
        if(Search(root,arr1[i]) == true){
            score++;
        }
    }

    result.push_back(score);
    nameFile.push_back(a + " " + b);
}

void compareGramerTree1(vector<int> &result, vector<string> &nameFile , const char* nameFileS){
    vector<string> fileName = EnumerateFolders(nameFileS);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamerTree1(fileName[i], fileName[j], result, nameFile, nameFileS);
        }
    }
}

void compareGramerTree2(vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    vector<string> fileName = EnumerateFolders(nameFileS);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamerTree2(fileName[i], fileName[j], result, nameFile, nameFileS);
        }
    }
}

void compareGramerTree3(vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    vector<string> fileName = EnumerateFolders(nameFileS);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _CompareGamerTree3(fileName[i], fileName[j], result, nameFile, nameFileS);
        }
    }
}

void CompareTree(const char* grams, const char* b, const char* nameFileS){
    vector<int> result;
    vector<string> nameFile;

    int number = atoi(b);

    if( (string)grams == "1"){
        compareGramerTree1(result,nameFile, nameFileS);
    }
    else if ((string)grams == "2"){
        compareGramerTree2(result,nameFile, nameFileS);
    }
    else if((string)grams == "3"){
        compareGramerTree3(result,nameFile, nameFileS);
    }
    else if ((string)grams == "1-2"){
        vector<int> _result;
        vector<string> _nameFile;

        compareGramerTree1(result,nameFile, nameFileS);
        compareGramerTree2(_result,_nameFile, nameFileS);

        for (int i = 0; i < 300; i++){
            result[i] += _result[i];
        }
    }
    else if ((string)grams == "2-3"){
        vector<int> _result;
        vector<string> _nameFile;

        compareGramerTree2(result,nameFile, nameFileS);
        compareGramerTree3(_result,_nameFile, nameFileS);

        for (int i = 0; i < 300; i++){
            result[i] += _result[i];
        }
    }
    else if((string)grams == "1-3"){
        vector<int> _result;
        vector<string> _nameFile;
        vector<int> __result;
        vector<string> __nameFile;

        compareGramerTree1(result,nameFile, nameFileS);
        compareGramerTree2(_result,_nameFile, nameFileS);
        compareGramerTree3(__result,__nameFile, nameFileS);

        for (int i = 0; i < 300; i++){
            result[i] += _result[i] + __result[i];
        }
    }

    string tmp;
    int _tmp;

    for (int i = 0; i < 300; i++){
        for (int j = i+1; j < 300; j++){
            if (result[i] < result[j]){
                _tmp = result[i];
                result[i] = result[j];
                result[j] = _tmp;

                tmp = nameFile[i];
                nameFile[i] = nameFile[j];
                nameFile[j] = tmp;
            }
        }
    }

    if (number == -1){
        for (int i = 0; i < 300; i++){
            cout << nameFile[i] << " " << result[i] << endl;
        }
    }
    else{
        for (int i = 0; i < number ; i++){
            cout << nameFile[i] << " " << result[i] << endl;
        }
    }
}

// table

int hashTableSize=20;
int hashFunc(string s)
{
    hash<string> hash_string;
   return hash_string(s)%hashTableSize;
}
vector <string> *hashTable;
vector <int> *hashIndex;
void __insert(string s)
{
    int index = hashFunc(s);
    hashTable[index].push_back(s);
    hashIndex[index].push_back(1);
}
bool __search(string s)
{
    int index = hashFunc(s);
    for(int i = 0;i < hashTable[index].size();i++)
    {
        if(hashTable[index][i].compare(s) == 0&&hashIndex[index][i] == 1)
        {
            hashIndex[index][i] = 0;
            return true;
        }
    }
    return false;
}

void _compareGramerTable1(string a, string b, vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    hashTable = new vector<string>[hashTableSize];
    hashIndex = new vector<int>[hashTableSize];
    int score = 0;
    int s = 0;

    vector<string> arr = cutWord(_readk(a, nameFileS),s);
    vector<string> arr1 = cutWord(_readk(b, nameFileS),s);

    for (int i = 0; i < arr.size(); i++){
        __insert(arr[i]);
    }
    for (int i = 0 ; i < arr1.size(); i++)
    {
        if(__search(arr1[i]) == true)
        {
            score++;
        }
    }

    result.push_back(score);
    nameFile.push_back(a + " " + b);
}

void _compareGramerTable2(string a, string b, vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    hashTable = new vector<string>[hashTableSize];
    hashIndex = new vector<int>[hashTableSize];
    int score = 0;
    int s = 0;

    vector<string> arr = cutWordGramer2(_readk(a, nameFileS),s);
    vector<string> arr1 = cutWordGramer2(_readk(b, nameFileS),s);

    for (int i = 0; i < arr.size(); i++){
        __insert(arr[i]);
    }
    for (int i = 0 ; i < arr1.size(); i++)
    {
        if(__search(arr1[i]) == true)
        {
            score++;
        }
    }

    result.push_back(score);
    nameFile.push_back(a + " " + b);
}

void _compareGramerTable3(string a, string b, vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    hashTable = new vector<string>[hashTableSize];
    hashIndex = new vector<int>[hashTableSize];
    int score = 0;
    int s = 0;

    vector<string> arr = cutWordGramer3(_readk(a, nameFileS),s);
    vector<string> arr1 = cutWordGramer3(_readk(b, nameFileS),s);

    for (int i = 0; i < arr.size(); i++){
        __insert(arr[i]);
    }
    for (int i = 0 ; i < arr1.size(); i++)
    {
        if(__search(arr1[i]) == true)
        {
            score++;
        }
    }

    result.push_back(score);
    nameFile.push_back(a + " " + b);
}

void compareGramerTable1(vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    vector<string> fileName = EnumerateFolders(nameFileS);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _compareGramerTable1(fileName[i], fileName[j], result, nameFile, nameFileS);
        }
    }
}

void compareGramerTable2(vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    vector<string> fileName = EnumerateFolders(nameFileS);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _compareGramerTable2(fileName[i], fileName[j], result, nameFile, nameFileS);
        }
    }
}

void compareGramerTable3(vector<int> &result, vector<string> &nameFile, const char* nameFileS){
    vector<string> fileName = EnumerateFolders(nameFileS);

    for (int i = 0; i < 25; i++){
        for (int j = i+1; j < 25; j++){
            _compareGramerTable3(fileName[i], fileName[j], result, nameFile, nameFileS);
        }
    }
}

void compareTable(const char* grams, const char* numberPrint, const char* nameFileS){
    vector<int> result;
    vector<string> nameFile;

    int b = atoi(numberPrint);

    if ((string)grams == "1"){
        compareGramerTable1(result, nameFile, nameFileS);
    }
    else if ((string)grams == "2"){
        compareGramerTable2(result, nameFile, nameFileS);
    }
    else if ((string)grams == "3"){
        compareGramerTable3(result, nameFile, nameFileS);
    }
    else if ((string)grams == "1-2"){
        vector<int> _result;
        vector<string> _nameFile;

        compareGramerTable1(result, nameFile, nameFileS);
        compareGramerTable2(_result, _nameFile, nameFileS);

        for (int i = 0; i < 300; i++){
            result[i] += _result[i];
        }
    }
    else if ((string)grams == "2-3"){
        vector<int> _result;
        vector<string> _nameFile;

        compareGramerTable2(result, nameFile, nameFileS);
        compareGramerTable3(_result, _nameFile, nameFileS);

        for (int i = 0; i < 300; i++){
            result[i] += _result[i];
        }
    }
    else if ((string)grams == "1-3"){
        vector<int> _result;
        vector<string> _nameFile;
        vector<int> __result;
        vector<string> __nameFile;

        compareGramerTable1(result, nameFile, nameFileS);
        compareGramerTable2(_result, _nameFile, nameFileS);
        compareGramerTable3(__result, __nameFile, nameFileS);

        for (int i = 0; i < 300; i++){
            result[i] += _result[i] + __result[i];
        }
    }

    string tmp;
    int _tmp;

    for (int i = 0; i < 300; i++){
        for (int j = i+1; j < 300; j++){
            if (result[i] < result[j]){
                _tmp = result[i];
                result[i] = result[j];
                result[j] = _tmp;

                tmp = nameFile[i];
                nameFile[i] = nameFile[j];
                nameFile[j] = tmp;
            }
        }
    }

    if (b == -1){
        for (int i = 0; i < 300; i++){
            cout << nameFile[i] << " " << result[i] << endl;
        }
    }
    else{
        for (int i = 0; i < b; i++){
            cout << nameFile[i] << " " << result[i] << endl;
        }
    }
}

// swap

void swapCompare(const char* nameCompare, const char* grams ,const char* numberPrint, const char* nameFile){
    if ((string)nameCompare == "vector"){
        CompareVector(grams, numberPrint, nameFile);
    }
    else if ((string)nameCompare == "map"){
        CompareMap(grams, numberPrint, nameFile);
    }
    else if ((string)nameCompare == "tree"){
        CompareTree(grams, numberPrint, nameFile);
    }
    else if ((string)nameCompare == "table-map"){
        compareTable(grams, numberPrint, nameFile);
    }
}

int main(int argc, char *argv[])
{

    auto start = chrono::steady_clock::now();
    //swapCompare(argv[4], argv[6], argv[8], argv[2]);
    if (argc != 9){
        cout << "nhap sai" << endl;
    }
    else{
        swapCompare(argv[4], argv[6], argv[8], argv[2]);
    }
    auto endd = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = endd-start;
    cout << "time: " << elapsed_seconds.count() << endl;
    /*if (( string)argv[8] == ""){
        cout << "sai tham so" << endl;
    }
    else{
        swapCompare(argv[4], argv[6], argv[8], argv[2]);
    }*/
    return 0;
}
