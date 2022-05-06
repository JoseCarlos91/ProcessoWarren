#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <unordered_set>
#include <stdlib.h>

using namespace std;

string invertSequence(string sequence);
void printa(unordered_set<int> control, int contador);


int main()
{
	
string  sNumero;
string  sInvertida;
	
int 	iNumeroInvertido = 0;
int     iSoma            = 0;
int     contador         = 0;

 unordered_set<int> control;


for (int i = 0; i < 1000000; i++)
{
	
	sNumero = to_string(i); // transforma numero em uma string
	
	sInvertida = invertSequence(sNumero);  // chama metodo que inverte a string 
	
	iNumeroInvertido = stoi(sInvertida); // transforma a invertida em um inteiro de iNumeroInvertido
	
	iSoma = i + iNumeroInvertido;
	
	if(iSoma < 1000000 && !control.count(iNumeroInvertido) && sNumero.at(sNumero.length() - 1) != '0' && iSoma % 2 != 0)
	{
	    control.insert(i); //guarda todos os numeros validos nao repetidos 
	    contador++;        // contador apenas para contar a quantidade de numeros validas 
	}
	
}
	
	printa(control, contador);
	return 0;
}


void printa(unordered_set<int>(control), int contador)
{
     for (int const& i : control)
    {
        string sInvertida = invertSequence(to_string(i)); //trasforma i em string e inverte
        int iNumeroInvertido = stoi(sInvertida);          // pega o invertido do i e volta pra inteiro
        std::cout << i << " + " << invertSequence(to_string(i)) << " = " << i + iNumeroInvertido << endl;
         
    }
     cout << "total = " << contador << endl;
}

string invertSequence(string sequence) 
{
    reverse(sequence.begin(), sequence.end());
    return sequence;
}




