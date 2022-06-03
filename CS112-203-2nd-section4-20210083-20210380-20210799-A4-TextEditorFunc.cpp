#include"CS112-203-2nd-section4-20210083-20210380-20210799-A4-TextEditorFunc.h"
using namespace std;
string FileName;
fstream file;
string  option, last_option, string_encrypt, string_decrypt,
        string_merge, string_add, string_upper, string_lower, string_caps;



//_________________________________________
void valid_option(){
    cout << "Your option is: ";
    getline(cin, option, '\n');
    regex validOption("[0-9]|1[0-6]");
    while (!regex_match(option, validOption)) {
        cout << "Please enter an option from the previous list\n>>";
        getline(cin, option, '\n');
    }
    cout << '\n';
}


//---------------------------------------------
void display_menu(){
    cout << "Please select an option to apply or 16 to exit:\n"
            "1.  Add new text to the end of the file\n"
            "2.  Display the content of the file\n"
            "3.  Empty the file\n"
            "4.  Encrypt the file content\n"
            "5.  Decrypt the file content\n"
            "6.  Merge another file\n"
            "7.  Count the number of words in the file.\n"
            "8.  Count the number of characters in the file\n"
            "9.  Count the number of lines in the file\n"
            "10. Search for a word in the file\n"
            "11. Count the number of times a word exists in the file\n"
            "12. Turn the file content to upper case.\n"
            "13. Turn the file content to lower case.\n"
            "14. Turn file content to 1st caps (1st char of each word is capital)\n"
            "15. Save\n"
            "16. Exit the whole program\n";
}


//---------------------------------------------------------------------------
void Input_FileName(){
    string line, string1;
    cout << "Enter the file name :\n";
    getline(cin,FileName,'\n');
    FileName += ".txt";
    FileName.c_str();
    file.open(FileName);
    if (file.fail()) {
        cout << "The file can't be opened\n" << endl;
        file.open(FileName,ios::out);
        cout << "This is a new file. I created it for you ^_^\n";
    }
    file.close();
}

//-----------------------------------------------------------------------------

void Add(){
    string add, line;
    file.open(FileName, ios::in);
    while(getline(file, line)){
        string_add += line;
        string_add += '\n';
    }
    file.close();
    file.open(FileName,ios::app);
    cout << "Enter the text you want to add :\nEnter Ctrl+Z when you finish\n";
    getline(cin,add, '\0');
    cin.clear();
    string_add += add;
    last_option = "1";
    file.close();
}

//-------------------------------------------------------------------------
void Display(){
    string line;
    file.open(FileName.c_str(),ios::in);
    while(getline(file, line)){
        cout << line << '\n';
    }
    if(file.tellg() == 0){
        cout << "The specified file is empty";
    }
    file.close();
}

//-----------------------------------------------------------------------

void Empty(){
    if(file.tellg() == 0){
        cout << "The specified file is already empty";
    }
    file.open(FileName,ios::out);
    file.close();
}

//----------------------------------------------------------------------

void encrypt() {
    string line;
    file.close();
    file.open(FileName.c_str(), ios::in);
    while (!file.eof()) {
        getline(file, line);
        string_encrypt += line;
        string_encrypt += '\n';
    }
    last_option = "4";
    file.close();
}

//------------------------------------------------------------------------
void decrypt() {
    string line;
    file.open(FileName.c_str(), ios::in);
    while (!file.eof()) {
        getline(file, line);
        string_decrypt += line;
        string_decrypt += '\n';
    }
    last_option = "5";
    file.close();
}

//----------------------------------------------------------------------

void merge(){
    string line;
    file.open(FileName, ios::in);
    while(getline(file, line)){
        string_merge += line;
        string_merge += '\n';
    }
    file.close();
    fstream file2;
    string FN;
    cout << "Please enter the file name you want to apply merge process:";
    getline(cin,FN,'\n');
    FN += ".txt";
    FN.c_str();
    file2.open(FN, ios::in);
    if (file2.fail()) {
        cout << "Invalid File Name\n";
    }
    while(getline(file2, line)){
        string_merge += line;
        string_merge += '\n';
    }
    file2.close();
    last_option = "6";
}

//-----------------------------------------------------------
void count_num_of_words(){
    file.open(FileName, ios:: in);
    string string1, line;
    int sum=0;
    while(getline(file, line)){
        string1 += line;
        string1 += ' ';
    }
    for(int i = 0; i < string1.length(); ++i){
        if(string1[i] == ' ' && string1[i-1] != ' '){
            sum++;
        }
    }
    cout << "\nSum of words in the specified file is " << sum;
    file.close();
}


void count_num_of_characters(){
    file.open(FileName, ios::in);
    string string1, line;
    while(getline(file, line)){
        string1 += line;
    }
    cout << "\nSum of characters in the specified file is " << string1.length();
    file.close();
}

//------------------------------------------------------------------------------------

void count_num_of_lines(){
    file.open(FileName, ios::in);
    string line;
    int sum = 0;
    while(getline(file, line)){
        sum += 1;
    }
    cout << "\nSum of lines in the specified file is " << sum;
    file.close();
}

//-----------------------------------------------------------------------------------------

void search_for_word(){
    file.open(FileName, ios::in);
    string FN, line, word, string1;
    int counter = 0;
    cout << "Please enter the word to search for it: ";
    getline(cin, word, '\n');
    while(getline(file, line)){
        string1 += line;
        string1 += ' ';
    }
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    transform(string1.begin(), string1.end(), string1.begin(), ::tolower);
    for(int i = 0;i < string1.length(); i++) {
        if (word[0] == string1[i] && string1[i - 1] == ' ') {
            for (int j = 0; j < word.length(); j++) {
                if (word[j] == string1[i + j]) {
                    counter++;
                }
            }
            if (counter == word.length()) {
                cout << "Word was found in the file :)";
                break;
            }
        }
        else if (word[0] == string1[0]) {
            for (int j = 0; j < word.length(); j++) {
                if (word[j] == string1[i + j]) {
                    counter++;
                }
            }
            if (counter == word.length()) {
                cout << "Word was found in the file :)";
                break;
            }
        }
        counter = 0;
    }
    if(counter != word.length()){
        cout << "Word was not found in the file :(";
    }
    file.close();
}

//-------------------------------------------------------------------

void count_num_of_times_word_exist(){
    file.open(FileName, ios::in);
    int counter = 0, c=0;
    string word, string1, line;
    cout << "Enter the word you want to know how many times it is in the file: ";
    getline(cin, word, '\n');
    while(getline(file, line)){
        string1 += line;
        string1 += ' ';
    }
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    transform(string1.begin(), string1.end(), string1.begin(), ::tolower);
    for(int i = 0;i < string1.length(); i++) {
        if (word[0] == string1[i] && string1[i - 1] == ' ') {
            for (int j = 0; j < word.length(); j++) {
                if (word[j] == string1[i + j]) {
                    counter++;
                }
            }
            if (counter == word.length()) {
                c++;
            }
        }
        else if (word[0] == string1[0]) {
            for (int j = 0; j < word.length(); j++) {
                if (word[j] == string1[i + j]) {
                    counter++;
                }
            }
            if (counter == word.length()) {
                c++;
            }
        }
        counter = 0;
    }
    cout << "Number of times this word has been written is " << c << '\n';
    file.close();
}

//------------------------------------------------------------------------------

void upper_case() {
    file.open(FileName, ios::in);
    string line;
    while (getline(file, line)) {
        string_upper += line;
        string_upper += '\n';
    }
    transform(string_upper.begin(), string_upper.end(), string_upper.begin(), ::toupper);
    last_option = "12";
    file.close();
    cout << string_upper;
}

//------------------------------------------------------------------------------
void lower_case(){
    file.open(FileName, ios::in);
    string line;
    while (getline(file, line)){
        string_lower += line;
        string_lower += '\n';
    }
    transform(string_lower.begin(), string_lower.end(), string_lower.begin(), ::tolower);
    last_option = "13";
    file.close();
}
//------------------------------------------------------------------------------------
void first_caps(){
    file.open(FileName, ios::in);
    string line;
    last_option = "14";
    while(getline(file, line)){
        string_caps += line;
        string_caps += '\n';
    }
    transform(string_caps.begin(), string_caps.end(), string_caps.begin(), ::tolower);
    string_caps[0] = toupper(string_caps[0]);
    for(int i = 1; i < string_caps.length();++i){
        if(string_caps[i-1] == ' '){
            string_caps[i] = toupper(string_caps[i]);
        }
        else if(string_caps[i-1] == '\n'){
            string_caps[i] = toupper(string_caps[i]);
        }
    }
    file.close();
}

//---------------------------------------------------------------------------------
void save(){
    file.close();
    string choice;
    cout<< "Choose: 1-To save the contents into the same file\n2-To save the contents into another file\n3-To Exit WITHOUT saving\n";
    cout << "Enter your choice :";
    getline(cin, choice, '\n');
    while(choice != "1" && choice != "2" && choice != "3"){
        cout << "Invalid choice\n";
        cout<< "Choose: 1-To save the contents into the same file\n2-To save the contents into another file\n3-To Exit WITHOUT saving\n";
        cout << "Enter your choice :";
        getline(cin, choice, '\n');
    }
    if (choice == "1") {
        if(last_option == "1"){
            file.open(FileName, ios::out);
            file << string_add;
        }
        else if(last_option == "4"){
            file.open(FileName, ios::out);
            for (char i :string_encrypt) {
                if(i == '\n'){
                    file << '\n';
                }
                else{
                    file << (char) ((int) i + 1);
                }
            }
        }
        else if(last_option == "5"){
            file.open(FileName, ios::out);
            for (char i : string_decrypt) {
                if(i=='\n'){
                    file << '\n';
                }
                else{
                    file << (char) ((int) i - 1);
                }
            }
        }
        else if(last_option == "6"){
            file.open(FileName, ios::out);
            file << string_merge;
        }
        else if(last_option == "12") {
            file.open(FileName, ios::out);
            file << string_upper;
        }
        else if(last_option == "13") {
            file.open(FileName, ios::out);
            file << string_lower;
        }
        else if(last_option == "14"){
            file.open(FileName, ios::out);
            file << string_caps;
        }
        else{
            cout << "No Changes happened to save, output is in the terminal";
        }
    }
    else if (choice == "2") {
        if(last_option == "1"){
            fstream file2;
            string FN2;
            cout << "Please enter the file name to save: ";
            getline(cin, FN2, '\n');
            file2.open(FN2.c_str(), ios::out);
            file << string_add << endl;
        }
        else if(last_option == "4"){
            fstream file2;
            string FN2;
            cout << "Please enter the file name to save: ";
            getline(cin, FN2, '\n');
            file2.open(FN2.c_str(), ios::out);
            for (char i : string_encrypt) {
                if(i=='\n'){
                    file2 <<'\n';
                }
                else{
                    file2 << (char) ((int) i + 1);
                }
            }
        }
        else if(last_option == "5"){
            fstream file2;
            string FN2;
            cout << "Please enter the file name to save: ";
            getline(cin, FN2, '\n');
            file2.open(FN2.c_str(), ios::out);
            for (char i : string_decrypt) {
                if(i=='\n'){
                    file2 << '\n';
                }
                else{
                    file2 << (char) ((int) i - 1);
                }
            }
        }
        else if(last_option == "6"){
            fstream file2;
            string FN2;
            cout << "Please enter the file name to save: ";
            getline(cin, FN2, '\n');
            file2.open(FN2.c_str(), ios::out);
            file2 << string_merge;
        }
        else if(last_option == "12"){
            fstream file2;
            string FN2;
            cout << "Please enter the file name to save: ";
            getline(cin, FN2, '\n');
            file2.open(FN2.c_str(), ios::out);
            file2 << string_upper;
        }
        else if(last_option == "13"){
            fstream file2;
            string FN2;
            cout << "Please enter the file name to save: ";
            getline(cin, FN2, '\n');
            file2.open(FN2.c_str(), ios::out);
            file2 << string_lower;
        }
        else if(last_option == "14"){
            fstream file2;
            string FN2;
            cout << "Please enter the file name to save: ";
            getline(cin, FN2, '\n');
            file2.open(FN2.c_str(), ios::out);
            file2 << string_caps;
        }
        else{
            cout << "No Changes happened to save, output is in the terminal";
        }
    }
}
