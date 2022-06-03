#include"CS112-203-2nd-section4-20210083-20210380-20210799-A4-TextEditorFunc.h"
using namespace std;
extern string option;

int main() {
    cout << "Ahlan ya user ya habibi :)\n";
    Input_FileName();
    while (true) {
        display_menu();
        valid_option();
        if (option == "1") {
            Add();
        } else if (option == "2") {
            Display();
        } else if (option == "3") {
            Empty();
        } else if (option == "4") {
            encrypt();
        } else if (option == "5") {
            decrypt();
        } else if (option == "6") {
            merge();
        } else if (option == "7") {
            count_num_of_words();
        } else if (option == "8") {
            count_num_of_characters();
        } else if (option == "9") {
            count_num_of_lines();
        } else if (option == "10") {
            search_for_word();
        } else if (option == "11") {
            count_num_of_times_word_exist();
        } else if (option == "12") {
            upper_case();
        } else if (option == "13") {
            lower_case();
        } else if (option == "14") {
            first_caps();
        } else if (option == "15") {
            save();
        } else if (option == "16") {
            return 0;
        }
        cout << "\n_______________________________________________________________\n";
    }

}
