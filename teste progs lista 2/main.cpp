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

int alg3(int vetor[],int n){

    int sum=0,i,j;
    for(i=1;i<=n;i++)
        for(j=n;j>=1;j/=2)
            sum+=j;
    return sum;

}

int alg4(int vetor[],int n){

    int sum=0,i,j;
    for(i=n;i>=1;i/=2)
        for(j=i;j<=n;j*=2)
            sum+=j;
    return sum;

}

int alg5(int vetor[],int n){

    int sum=0,i,j;
    for(i=n;i>=1;i/=2)
        for(j=i;j<=n;j++)
            sum+=j;
    return sum;

}



void preecherVetor(int v[],int tam){

    for(int i=0;i<tam;i++){
        v[i]=rand() % 100000000000;
    }

}


int main()
{
    cout<<"teste de tempo dos algoritmos da lista 2"<<endl<<endl;
    cout<<"QD=quantidade de dados\n"
          "TI=tempo inicial\n"
          "TF=tempo final\n"
          "TG=tempo gasto\n";

    srand(time(NULL));
    clockid_t inicio,fim;
    double tempoGasto;
    int value;
    int v1[10],v2[100],v3[1000],v4[10000],v5[100000];
    double vt1[5],vt2[5],vt3[5],vt4[5],vt5[5]; //vetores para armazenar o tempo dos algs

    preecherVetor(v1,10);
    preecherVetor(v2,100);
    preecherVetor(v3,1000);
    preecherVetor(v4,10000);
    preecherVetor(v5,100000);

   cout<<endl<<endl<<"algoritmo 1: "<<endl<<endl;
   cout<<"QD\tTI\tTF\tTG\t"<<endl;
   value=rand() % 100000000000;

   //v1*****************************************
   inicio=clock();
   cout<<"10^"<<1<<"\t"<<inicio<<"\t";
   alg1(v1,10,value);
   fim=clock();
   tempoGasto=fim-inicio;
   cout<<fim<<"\t"<<tempoGasto<<endl;
   vt1[0]=tempoGasto;
   //*******************************************

   //v2*****************************************
   inicio=clock();
   cout<<"10^"<<2<<"\t"<<inicio<<"\t";
   alg1(v2,100,value);
   fim=clock();
   tempoGasto=fim-inicio;
   cout<<fim<<"\t"<<tempoGasto<<endl;
   vt1[1]=tempoGasto;
   //*******************************************

   //v3*****************************************
   inicio=clock();
   cout<<"10^"<<3<<"\t"<<inicio<<"\t";
   alg1(v3,1000,value);
   fim=clock();
   tempoGasto=fim-inicio;
   cout<<fim<<"\t"<<tempoGasto<<endl;
   vt1[2]=tempoGasto;
   //*******************************************

   //v4*****************************************
   inicio=clock();
   cout<<"10^"<<4<<"\t"<<inicio<<"\t";
   alg1(v4,10000,value);
   fim=clock();
   tempoGasto=fim-inicio;
   cout<<fim<<"\t"<<tempoGasto<<endl;
   vt1[3]=tempoGasto;
   //*******************************************

   //v5*****************************************
   inicio=clock();
   cout<<"10^"<<5<<"\t"<<inicio<<"\t";
   alg1(v4,100000,value);
   fim=clock();
   tempoGasto=fim-inicio;
   cout<<fim<<"\t"<<tempoGasto<<endl;
   vt1[4]=tempoGasto;
   //*******************************************



    cout<<endl<<endl<<"algoritmo 2: "<<endl<<endl;

     cout<<"QD\tTI\tTF\tTG\t"<<endl;
    //v1*****************************************
    inicio=clock();
    cout<<"10^"<<1<<"\t"<<inicio<<"\t";
    alg2(v1,10);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt2[0]=tempoGasto;
    //*******************************************

    //v2*****************************************
    inicio=clock();
    cout<<"10^"<<2<<"\t"<<inicio<<"\t";
    alg2(v2,100);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt2[1]=tempoGasto;
    //*******************************************

    //v3*****************************************
    inicio=clock();
    cout<<"10^"<<3<<"\t"<<inicio<<"\t";
    alg2(v3,1000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt2[2]=tempoGasto;
    //*******************************************

    //v4*****************************************
    inicio=clock();
    cout<<"10^"<<4<<"\t"<<inicio<<"\t";
    alg2(v4,10000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt2[3]=tempoGasto;
    //*******************************************

    //v5*****************************************
    inicio=clock();
    cout<<"10^"<<5<<"\t"<<inicio<<"\t";
    alg2(v5,100000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt2[4]=tempoGasto;
    //*******************************************


    cout<<endl<<endl<<"algoritmo 3: "<<endl<<endl;
    cout<<"QD\tTI\tTF\tTG\t"<<endl;

    //v1*****************************************
    inicio=clock();
    cout<<"10^"<<1<<"\t"<<inicio<<"\t";
    alg3(v1,10);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt3[0]=tempoGasto;
    //*******************************************

    //v2*****************************************
    inicio=clock();
    cout<<"10^"<<2<<"\t"<<inicio<<"\t";
    alg3(v2,100);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt3[1]=tempoGasto;
    //*******************************************

    //v3*****************************************
    inicio=clock();
    cout<<"10^"<<3<<"\t"<<inicio<<"\t";
    alg3(v3,1000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt3[2]=tempoGasto;
    //*******************************************

    //v4*****************************************
    inicio=clock();
    cout<<"10^"<<4<<"\t"<<inicio<<"\t";
    alg3(v4,10000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt3[3]=tempoGasto;
    //*******************************************

    //v5*****************************************
    inicio=clock();
    cout<<"10^"<<5<<"\t"<<inicio<<"\t";
    alg3(v5,100000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt3[4]=tempoGasto;
    //*******************************************

    cout<<endl<<endl<<"algoritmo 4: "<<endl<<endl;
    cout<<"QD\tTI\tTF\tTG\t"<<endl;

    //v1*****************************************
    inicio=clock();
    cout<<"10^"<<1<<"\t"<<inicio<<"\t";
    alg4(v1,10);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt4[0]=tempoGasto;
    //*******************************************

    //v2*****************************************
    inicio=clock();
    cout<<"10^"<<2<<"\t"<<inicio<<"\t";
    alg4(v2,100);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt4[1]=tempoGasto;
    //*******************************************

    //v3*****************************************
    inicio=clock();
    cout<<"10^"<<3<<"\t"<<inicio<<"\t";
    alg4(v3,1000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt4[2]=tempoGasto;
    //*******************************************

    //v4*****************************************
    inicio=clock();
    cout<<"10^"<<4<<"\t"<<inicio<<"\t";
    alg4(v4,10000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt4[3]=tempoGasto;
    //*******************************************

    //v5*****************************************
    inicio=clock();
    cout<<"10^"<<5<<"\t"<<inicio<<"\t";
    alg4(v5,100000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt4[4]=tempoGasto;
    //*******************************************

    cout<<endl<<endl<<"algoritmo 5: "<<endl<<endl;
    cout<<"QD\tTI\tTF\tTG\t"<<endl;

    //v1*****************************************
    inicio=clock();
    cout<<"10^"<<1<<"\t"<<inicio<<"\t";
    alg5(v1,10);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt5[0]=tempoGasto;
    //*******************************************

    //v2*****************************************
    inicio=clock();
    cout<<"10^"<<2<<"\t"<<inicio<<"\t";
    alg5(v2,100);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt5[1]=tempoGasto;
    //*******************************************

    //v3*****************************************
    inicio=clock();
    cout<<"10^"<<3<<"\t"<<inicio<<"\t";
    alg5(v3,1000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt5[2]=tempoGasto;
    //*******************************************

    //v4*****************************************
    inicio=clock();
    cout<<"10^"<<4<<"\t"<<inicio<<"\t";
    alg5(v4,10000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt5[3]=tempoGasto;
    //*******************************************

    //v5*****************************************
    inicio=clock();
    cout<<"10^"<<5<<"\t"<<inicio<<"\t";
    alg5(v5,100000);
    fim=clock();
    tempoGasto=fim-inicio;
    cout<<fim<<"\t"<<tempoGasto<<endl;
    vt5[4]=tempoGasto;
    //*******************************************

    //comparando os tempos
    cout<<endl<<endl<<"comparando os tempos gastos dos algoritmos"<<endl<<endl;


    cout<<"QTD.dados\talg1\talg2\talg3\talg4\talg5\t"<<endl;
    for(int i=0;i<5;i++)
        cout<<"10^"<<i+1<<"\t\t"<<vt1[i]<<"\t"<<vt2[i]<<"\t"<<vt3[i]<<"\t"
           <<vt4[i]<<"\t"<<vt5[i]<<"\t"<<endl;

    cout<<endl<<endl;
}
