#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;


int alg1(int vetor[],int t,int value){
    int count=0;
    for(int i=0;i<t;i++)
        if(vetor[i]==value)
            count++;

    return count;

}

bool alg2(int *vetor,int t){

    for(int i=0;i< t-1;i++){
        for(int j=i+1;j<t;j++){
            if(vetor[i]==vetor[j]){
                return false;
            }
        }
    }


}

void preecherVetor(int v[],int tam){

    for(int i=0;i<tam;i++){
        v[i]=rand() % 100000000000;
    }

}


int main()
{
    cout<<"teste de tempo dos algoritmos da lista 2"<<endl;

    srand(time(NULL));
    clockid_t inicio,fim;
    double tempoGasto;
    int value;
    int v1[10],v2[100],v3[1000],v4[10000],v5[100000];

    preecherVetor(v1,10);
    preecherVetor(v2,100);
    preecherVetor(v3,1000);
    preecherVetor(v4,10000);
    preecherVetor(v5,100000);

   cout<<"algoritmo 1: "<<endl;
   cout<<"QD\tTI\tTF\tTG\t"<<endl;
   value=rand() % 100000000000;

   //v1*****************************************
   inicio=clock();
   cout<<"10^"<<1<<"\t"<<inicio<<"\t";
   alg1(v1,10,value);
   fim=clock();
   tempoGasto=fim-inicio;
   cout<<fim<<"\t"<<tempoGasto<<endl;
   //*******************************************

   //v2*****************************************
   inicio=clock();
   cout<<"10^"<<2<<"\t"<<inicio<<"\t";
   alg1(v2,100,value);
   fim=clock();
   tempoGasto=fim-inicio;
   cout<<fim<<"\t"<<tempoGasto<<endl;
   //*******************************************

   //v3*****************************************
   inicio=clock();
   cout<<"10^"<<3<<"\t"<<inicio<<"\t";
   alg1(v3,1000,value);
   fim=clock();
   tempoGasto=fim-inicio;
   cout<<fim<<"\t"<<tempoGasto<<endl;
   //*******************************************

   //v4*****************************************
   inicio=clock();
   cout<<"10^"<<4<<"\t"<<inicio<<"\t";
   alg1(v4,10000,value);
   fim=clock();
   tempoGasto=fim-inicio;
   cout<<fim<<"\t"<<tempoGasto<<endl;
   //*******************************************

   //v5*****************************************
   inicio=clock();
   cout<<"10^"<<5<<"\t"<<inicio<<"\t";
   alg1(v4,100000,value);
   fim=clock();
   tempoGasto=fim-inicio;
   cout<<fim<<"\t"<<tempoGasto<<endl;
   //*******************************************



    cout<<endl<<endl<<"algoritmo 2: "<<endl;
     cout<<"QD\tTI\tTF\tTG\t"<<endl;
    //v1*****************************************
    inicio=clock();
    cout<<"10^"<<1<<"\t"<<inicio<<"\t";
    alg2(v1,10);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    //*******************************************

    //v2*****************************************
    inicio=clock();
    cout<<"10^"<<2<<"\t"<<inicio<<"\t";
    alg2(v2,100);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    //*******************************************

    //v3*****************************************
    inicio=clock();
    cout<<"10^"<<3<<"\t"<<inicio<<"\t";
    alg2(v3,1000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    //*******************************************

    //v4*****************************************
    inicio=clock();
    cout<<"10^"<<4<<"\t"<<inicio<<"\t";
    alg2(v4,10000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    //*******************************************

    //v5*****************************************
    inicio=clock();
    cout<<"10^"<<5<<"\t"<<inicio<<"\t";
    alg2(v5,100000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    //*******************************************
}
