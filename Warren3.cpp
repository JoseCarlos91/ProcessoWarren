#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <unordered_set>

using namespace std;

void TodasAsCombinacoes (vector<int> &vArr,vector <int> &vec, vector<vector<int>> &Resultado, int iSoma, int i);

vector<vector<int>> SomaCombinada (vector<int>& vArr, int iN);

int VerificaOmenor(vector<vector<int>>& vResultado);



int main()
{

int iN 					= 0;
int iTamanhoVet 		= 0;
int iLeituraDeValores 	= 0;

vector<int> vArr;

//ler o tamanho do vetor e já preencher com valores (pedir ao usuario)

cout << "Digite o tamanho do vetor " << endl; 
cin >> iTamanhoVet;

cout << "Agora preencha o seu vetor com " << iTamanhoVet << " valores " << endl;

for(int i = 0; i < iTamanhoVet; i++)
{
	cin >> 	iLeituraDeValores;
	vArr.push_back(iLeituraDeValores);
}

cout << "Agora insira um numero N, e mostraremos as menores possiveis combinacoes dos valores do vetor que quando somadas resultem em N" << endl;
cin >> iN; 


vector<vector<int>> vResultado = SomaCombinada(vArr,iN);

int iMenorValor = 0;

iMenorValor = VerificaOmenor(vResultado);


for (int i = 0; i < vResultado.size(); i++) 
  { 
    if (!vResultado[i].empty() && vResultado[i].size() == iMenorValor) 
    { 
      cout << "[ "; 
      for (int j = 0; j < vResultado[i].size(); j++) 
      {
        cout << vResultado[i][j] << " "; 
      }
       cout << "]"; 
       cout<<endl;
    } 
   
  } 

return 0;
}

void TodasAsCombinacoes (vector<int> &vArr, vector <int> &vec, vector<vector<int>> &Resultado, int iSoma, int i)
{
    
    if (iSoma < 0 ) // se soma chegar aqui menor que zero, a soma dos elementos se tornaram maior do 
    return;         // que o N original 
    
    if(iSoma == 0)
    {
        Resultado.push_back(vec); // significa que uma possivel soma foi encontrada 
        return;                   // e sera adicionada a matriz de resultados validos
    }
    
    
    
    while(i < vArr.size() && iSoma - vArr[i] >= 0)
    {
         // adiciona todos os elementos do array ao vec começando de i
        // que adiciona/contribui para iSoma
        vec.push_back(vArr[i]);
        
        // volta a adicionar arr[i] a vec se contribui para 'soma'
        TodasAsCombinacoes(vArr,vec,Resultado,iSoma - vArr[i],i);
        
         // move para o próximo elemento caso
        // soma dos elementos se torna maior que
       // ou igual à soma necessária
        i++;
        
        // remove o último número da lista de combinações
       // para adicionar o próximo elemento (basicamente retrocedendo)
        vec.pop_back();
        
    }
    
}

vector<vector<int>> SomaCombinada (vector<int>& vArr, int iN)
{
    //Ordena o vetor
    sort(vArr.begin(), vArr.end()); 

    //Remover numeros duplicados (afinal de contas já vai ser somado ele com ele mesmo)
    //Cria um array novo pra guardar os valores unicos 
    vector<int> vArrUnicos;
    
    //unordered_set ajuda a verificar se um elemento foi incluido no array novo ou nao
    unordered_set<int> aux;
    
    
    for(auto i : vArr)
{
	 if (aux.find(i) == aux.end())
	 {
	 	aux.insert(i);
	 	vArrUnicos.push_back(i);
	 }	
}

//copia o array sem duplicados para o array original
vArr = vArrUnicos;

//declara mais um vetor auxiliar e uma matriz pra guardar todos os possiveis resultados
vector <int> vVec;
vector<vector<int>> vResultado;


//chama o metodo que vai fazer as contas
TodasAsCombinacoes(vArr,vVec,vResultado,iN,0);
    
    //retorna a matriz resultado
    return vResultado;
}


int VerificaOmenor(vector<vector<int>>& vResultado)
{
    
    //procura na matriz resultado as linhas 
    //com a menor quantidade de colunas e retorna esse valor inteiro
    //para que possamos printar apenas as somas de menor valor
    
    int ContaColunas = 0; 
   
    for (int i = 0; i < vResultado.size(); i++) 
  { 
      if (i == 0)
      ContaColunas = vResultado[i].size();
      
    if (!vResultado[i].empty()) 
    { 
     if (vResultado[i].size() < ContaColunas)
         ContaColunas = vResultado[i].size();
    } 
    
  } 
  
    return ContaColunas;
}





