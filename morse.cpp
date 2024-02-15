#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    string alfabeto, frase_iniziale, frase_finale = " ",parte_morse = " ";
    size_t pos;
    int indice = 0;
    char lettera_salvata;
    ifstream frase_input("testo.txt");
    ifstream input_file("alfabeto.txt");
    getline(frase_input, frase_iniziale);
    while (getline(input_file, alfabeto, ' '))
    {
        for (char carattere : frase_iniziale)
        {
            pos = alfabeto.find(carattere);
            while (alfabeto[pos-indice] != ' ')
            {
                parte_morse += alfabeto[pos-indice];
                indice += 1;
            }
            reverse(parte_morse.begin(), parte_morse.end());
            frase_finale += parte_morse;
        }
    }
    cout<<frase_finale;
}