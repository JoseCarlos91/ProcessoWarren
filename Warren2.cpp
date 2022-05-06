#include <iostream>
using namespace std;


int main()
{
    int iLimiteAlunos        = 0;
    int iTotalAlunos         = 0;
    int iContadorAlunos      = 0;
    int iContaAlunosCertos   = 0;
    int iContaAlunosErrados  = 0;
    int iTempoChegada[150];       //Total de alunos possiveis em uma classe 


    cout << "Digite o numero total de alunos matriculados na disciplina " << endl;
    cin  >> iTotalAlunos;    // entra com o total da classe 
    
    cout << "Digite o limite de alunos para que o professor não cancele a aula " << endl;
    cin  >> iLimiteAlunos;   // entra com o limite do professor
    
    
    cout << "Digite o tempo de chegada de cada aluno " << endl;
    
    while (iContadorAlunos < iTotalAlunos)
    {
        cin >> iTempoChegada[iContadorAlunos];  //entra com o tempo de chegada de cada aluno
        iContadorAlunos++;
    }

    for (int i = 0; i < iTotalAlunos; i++)
    {
        if(iTempoChegada[i] >= 0)       // verifica se o tempo do aluno é maior o menor que zero
            iContaAlunosCertos++;
        else
            iContaAlunosErrados++;
            
    }
    
    if (iContaAlunosCertos >= iLimiteAlunos)   // compara a quantidade de alunos certos com o limite do professor             
        cout << "Aula normal" << endl;      
    else
        cout << "Aula cancelada" << endl;
   

    return 0;
}


