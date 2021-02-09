/*1. Para entender o valor dos registros em uma linguagem de programação, escreva
um pequeno programa em uma linguagem baseada em C que use um vetor de
estruturas que armazenem informações de estudantes, incluindo o nome, a idade,
a média das notas como um ponto-flutuante e o nível do estudante em uma
cadeia (por exemplo, “calouro” etc.). Escreva também o mesmo programa na
mesma linguagem sem usar tais estruturas.
*/


/*prog1
#include <iostream>
#include <math.h>
using namespace std;


struct Aluno
{
	private:
		string nome;
		string nivel;
		int idade;
		int media;
    public:
		string getNome()const{return this->nome;}
		string getNivel()const{return this->nivel;}
		int getIdade()const{return this->idade;}
		int getMedia()const{return this->media;}
		
		void setNome(string nome){this->nome=nome;}
		void setNivel(string nivel){this->nivel=nivel;}
		void setIdade(int idade){this->idade=idade;}
		void setMedia(int media){this->media=media;}
	
};





int main()
{
	Aluno vetor[10];
	
	for(int i=0;i<10;i++)
	{
		Aluno *aux=new Aluno();
		aux->setIdade(i*2+5);
		string p="A";
		aux->setNome(p);
		aux->setMedia(i);
		if(i%2==0)
		  aux->setNivel("calouro");
        else
		{
			aux->setNivel("veterano");
		}
	//	cout<<"ff: "<<aux->getNome()<<endl;
		vetor[i]=*aux;
		
	}
	//realiza um teste do vetor
	cout<<vetor[3].getNivel()<<endl;	
}
*/


//prog2

#include <iostream>
using namespace std;

void mostraAluno(string nome,string nivel,int idade,int media)
{
	cout<<"os dados do aluno são:\n"<<endl;
	cout<<"nome: "<<nome<<"\n"<<"idade: "<<idade<<"\n";
	cout<<"nivel: "<<nivel<<"\n"<<"media: "<<media<<"\n"<<endl;
	
}



int main ()

{
	
	//dados do aluno
	string nome;
	string nivel;
	int idade;
	int media;
	
	for(int i=0;i!=-1;)
	{
		cout<<"insira o nome do aluno"<<endl;
		cin>>nome;
		cout<<"insira o nivel do aluno"<<endl;
		cin>>nivel;
		cout<<"insira a idade do aluno"<<endl;
		cin>>idade;
		cout<<"insira a media do aluno"<<endl;
		cin>>media;
		mostraAluno(nome,nivel,idade,media);
		cout<<"\n\n\nisira 0 para continuar ou -1 para encerrar"<<endl;
		cin>>i;
			
	}
	
	
}