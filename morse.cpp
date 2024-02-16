#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    string alfabeto, frase_iniziale, frase_finale, parte_morse;
    int pos = 0;
    int indice = 1;
    ifstream frase_input("testo.txt");
    ifstream input_file("alfabeto.txt");
    getline(frase_input, frase_iniziale);
    getline(input_file, alfabeto);
    for (char carattere : frase_iniziale)
    {
        if (carattere != ' ')
        {
            pos = 0;
            indice = 1;
            pos = alfabeto.find(carattere);
            while (alfabeto[pos+indice] != carattere)
            {
                parte_morse += alfabeto[pos+indice];
                indice += 1;
            }
        }
        else
        {
            parte_morse += '|';
        }
    }
    frase_finale += parte_morse;
    cout<<frase_finale;
}