#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;



int main() {

    int n_tc;
    scanf("%d", &n_tc);

    map<char, string> morse;

    morse['A'] = ".-";
    morse['B'] = "-...";
    morse['C'] = "-.-.";
    morse['D'] = "-..";
    morse['E'] = ".";
    morse['F'] = "..-.";
    morse['G'] = "--.";
    morse['H'] = "....";
    morse['I'] = "..";
    morse['J'] = ".---";
    morse['K'] = "-.-";
    morse['L'] = ".-..";
    morse['M'] = "--";
    morse['N'] = "-.";
    morse['O'] = "---";
    morse['P'] = ".--.";
    morse['Q'] = "--.-";
    morse['R'] = ".-.";
    morse['S'] = "...";
    morse['T'] = "-";
    morse['U'] = "..-";
    morse['V'] = "...-";
    morse['W'] = ".--";
    morse['X'] = "-..-";
    morse['Y'] = "-.--";
    morse['Z'] = "--..";


    for (int tc = 0; tc < n_tc; ++tc) {

        string phrase;
        cin >> phrase;

        int ch_l = phrase.length();

        int dict_size;
        scanf("%d", &dict_size);
        vector<string> dict;
        for (int i = 0; i < dict_size; ++i) {
            string word;
            cin >> word;
            string morse_word = "";
            for (int j = 0; j < word.length(); ++j) {
                morse_word.append(morse[word[j]]);
            }
            dict.push_back(morse_word);
        }

        int result[ch_l+1];
        result[0]=1;

        for (int i = 1; i < ch_l+1; ++i) {
            result[i] = 0;
        }

        for (int i = 1; i < ch_l+1; ++i) {
            for (unsigned int m_i = 0; m_i < dict.size(); ++m_i) {
                string word = dict[m_i];
                int l = word.length();
                if(i >= l) {
                    if(phrase.compare(i-l, l, word) == 0) {
                        result[i] += result[i-l];
                    }
                }
            }
        }

        printf("%d\n", result[ch_l]);
    }

    return 0;
}
