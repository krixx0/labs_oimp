#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isBlank(string& str) {
    
    if (str.empty())
       return true;
    for (int i = 0; i < str.size(); i++) {
        
        char c = str[i];
        if (!isspace((unsigned char)c)) 
            return false;
    }
    return true;
}

int main() {
    
    string inputfile;
    string outputfile;
    cout << "Enter input file path: ";
    cin >> inputfile;
    cout << '\n';
    cout << "Enter output file path: ";
    cin >> outputfile;
    cout << '\n';

    ifstream fin(inputfile);
    if (!fin.is_open()) {
        
        cout << "ne udaloss otkryt file\n";
        return 1;
    }
    

    ofstream fout(outputfile);
    if (!fout.is_open()) {
        
        cout << "ne udaloss create file\n";
        return 1;
    }

    string line;
    int lineNum = 0;        
    int groupStartLine = 0;     
    int stringNumInGroup = 0;         
    bool inGroup = false;        
    bool foundAnyGroup = false;
    
    while (getline(fin, line)) { 
        
        lineNum++;

        if (isBlank(line)) {          
            if (!inGroup) {          
                
                inGroup = true;
                groupStartLine = lineNum;
                stringNumInGroup = 1;
            }
            else {                  
                
                stringNumInGroup++;
            }
        }
        else {                      
            if (inGroup) {            
                
                fout << "String " << groupStartLine << ": number of povtoreniy " << stringNumInGroup << '\n';
                foundAnyGroup = true;
                inGroup = false;
                stringNumInGroup = 0;
            }
        }
    }

    if (inGroup) {
        
        fout << "String " << groupStartLine << ": number of povtoreniy " << stringNumInGroup << '\n';
        foundAnyGroup = true;
    }

    fin.close();
    fout.close();

    if (!foundAnyGroup) {
        
        ofstream newfout(outputfile);
        newfout.close();
    }

    return 0;
}
