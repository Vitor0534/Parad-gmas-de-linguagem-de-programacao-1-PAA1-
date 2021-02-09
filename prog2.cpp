/*2. Para entender o valor da recursão em uma linguagem de programação, escreva
um programa que implemente o algoritmo quicksort, primeiro usando recursão e
então sem usar recursão.*/


#include <iostream>
using namespace std;

/*
int partition(long double *aux, long long p, long long r){
    long double x=aux[r];
    long long int i=p-1;
    long double num;
    for(int j=p;j<=r-1;j++){
        if(aux[j]<=x){
            i=i+1;
            num=aux[j];
            aux[j]=aux[i];
            aux[i]=num;
        }
    }
    num=aux[i+1];
    aux[i+1]=aux[r];
    aux[r]=num;
    return i+1;
}


void quickSort(long double *aux, long long p, long long r){
    long long int q;
    if(p<r){
        q=partition(aux,p,r);
        quickSort(aux,p,q-1);
        quickSort(aux,q+1,r);
    }
}


int main()
{
	int tam;
	cout<<"qual o tamanho do vetor? "<<endl;
	cin>>tam;
	long double vetor[tam];
	
	cout<<"insira os elementod do vetor:\n"<<endl;
	for(int i=0;i<=tam;i++)
	{
		cout<<"vetor["<<i<<"]: "<<endl;
		cin>>vetor[i];
	}
	
	quickSort(vetor,0,tam);
	
	cout<<"imprimindo elementos ordenados: "<<endl;
	for(int i=0;i<=tam;i++)
	{
		
		cout<<"vetor["<<i<<"]: "<<vetor[i]<<endl;
	}
	
}*/

//prog sem recursão

int partition(long double *aux, long long p, long long r){
    long double x=aux[r];
    long long int i=p-1;
    long double num;
    for(int j=p;j<=r-1;j++){
        if(aux[j]<=x){
            i=i+1;
            num=aux[j];
            aux[j]=aux[i];
            aux[i]=num;
        }
    }
    num=aux[i+1];
    aux[i+1]=aux[r];
    aux[r]=num;
    return i+1;
}

void quickSort(long double *aux, long long p, long long r){
    long long int q;
    if(p<r){
        q=partition(aux,p,r);
        quickSort(aux,p,q-1);
        quickSort(aux,q+1,r);
    }
}

int main(int argc, char** argv)
{
	int tam;
	cout<<"qual o tamanho do vetor? "<<endl;
	cin>>tam;
	long double vetor[tam];
	
	cout<<"insira os elementod do vetor:\n"<<endl;
	for(int i=0;i<=tam;i++)
	{
		cout<<"vetor["<<i<<"]: "<<endl;
		cin>>vetor[i];
	}
	int p=0;
	int r=tam;

	for(int i=0;i<=tam;i++)
	{	
        if(p<r)
		{
         partition(vetor,p,r);
        }
        p++;
        r--;
		
	}
	
	cout<<"imprimindo elementos ordenados: "<<endl;
	for(int i=0;i<=tam;i++)
	{
		
		cout<<"vetor["<<i<<"]: "<<vetor[i]<<endl;
	}
	
	return 0;
}
