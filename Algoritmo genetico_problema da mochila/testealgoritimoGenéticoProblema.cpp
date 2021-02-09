#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

//Aluno: Vitor de Almeida Silva
//isto responde o problema da empresa de carros, que precisa por o maior número de carros
//em um galpão levando em conta sua área e o preço decada carro

//problema: uma pequena empresa de compra e venda de carros adiquiriu um terreno com o objetivo de 
//construir um pátio e um galpão para colocar os carros. O objetivo da empresa é realizar um evento onde 
//as pessoas poderiam ver os carros que estão dentro do galpão, ela quer colocar os carros de acordo com 
//o preço e a área ocupada, seguindo os seguintes critérios:
//             * o preço dos carros devem ser somados para se ter um preço total
//             * a soma das áreas ocupadas pelos veiculos não deve exeder o limite do galpão exedido pela empresa (60 m^2)



int verificaPeso(int peso[],int teste[],int tam)
{
	
	int soma=0;
	for(int i=0;i<tam;i++)
		soma+=peso[i]*teste[i];
	
	return soma;
	
}

void imprimeVetor(int vetor[],int tam)
{
	cout<<"[ ";
	for(int i=0;i<tam;i++)
	{
		cout<<vetor[i]<<" ";
	}
	cout<<"]"<<endl;
	
}

void imprimeVetorPesos(int vetor[],int pesos[],int tam)
{
	cout<<"[ ";
	for(int i=0;i<tam;i++)
	{
		cout<<vetor[i]*pesos[i]<<" ";
	}
	cout<<"]"<<endl;
	
}


int main()
{
    vector<int> *lista=new vector<int>();
	
	int tam=10;
	
	srand(time(NULL));
	
//	int vetorPesos[10]={5,10,5,3,7,14,8,2,3,9}; //este peso se refere a  área
    int vetorPesos[10]={7,10,9,13,11,6,9,10,10,6};
	int vetorPreco[10]={5000,10000,20000,30000,10000,1500,9000,7000,7000,1000}; //iste se refere ao preço dos carros
	
	
	int vetor1[10],vetor2[10];
	
	int maiorVetor[tam];
	
	int capacidade=60;  //representa a área do galpão

	int i=0,p;
	
	
	
	
	//pai e mãe inicial
	vetor1={1,0,1,0,1,0,1,0,1,0};
	vetor2={0,1,0,1,0,1,0,1,0,1};
	
	
	
	cout<<"vetor1"<<endl;
	   imprimeVetor(vetor1,tam);
	cout<<"peso inicial v1: "<<verificaPeso(vetorPesos,vetor1,tam)<<endl;
	
	cout<<"vetor2"<<endl;
    imprimeVetor(vetor2,tam);
    cout<<"peso inicial v2: "<<verificaPeso(vetorPesos,vetor2,tam)<<endl;
    
    imprimeVetor(vetor1,tam);
    imprimeVetor(vetor2,tam);

	//inicializa
	for(int i=0;i<tam;i++)
	   maiorVetor[i]=vetor1[i];
	
   
   int limite=100; //isso controla o número de gerações
   
	while(i<=limite)
	{
       //srand (time(NULL));
       p=rand()%tam;
       cout<<"P: "<<p<<endl;
       
       
       //realiza o crosing over   "cruzamento"
       for(int j=p;j<tam;j++)
	   {
	   	
	   	if(vetor1[j]!=vetor2[j])
		   {
		   	
		   	if(vetor1[j]==0)
		   		vetor1[j]=1;
		   	else 
		   		vetor1[j]=0;
		   	
		   	if(vetor2[j]==0)
		   		vetor2[j]=1;
		   	else 
		   		vetor2[j]=0;
		   	
		   }
	   }
	   //**************
	   
	   cout<<"vetor1"<<endl;
	   imprimeVetor(vetor1,tam);
	   cout<<"peso final v1:"<<verificaPeso(vetorPesos,vetor1,tam)<<endl<<endl;
	   
       //maiorVetor=vetor2;
       cout<<"vetor2"<<endl;
	   imprimeVetor(vetor2,tam);
	   cout<<"peso final v2:"<<verificaPeso(vetorPesos,vetor2,tam)<<endl<<endl;
	   
	   int peso1,peso2,pesoM;
	   
	   pesoM=verificaPeso(vetorPesos,maiorVetor,tam);
	   peso1=verificaPeso(vetorPesos,vetor1,tam);
	   peso2=verificaPeso(vetorPesos,vetor2,tam);
	   
	   
	   //motra pesos usados para ponderação do resultado
	   cout<<"pesoM: "<<pesoM<<endl;
	   cout<<"peso1: "<<peso1<<endl;
	   cout<<"peso2: "<<peso2<<endl;
	   
	   
	   //realiza a seleção do maior peso, (melhor indivíduo)
	   if((pesoM>capacidade) && peso1<capacidade)
	   {
	   	for(int i=0;i<tam;i++)
	            maiorVetor[i]=vetor1[i];
	   	
	   	
	   }
	   	 else
			{
				if((pesoM>capacidade) && peso2<capacidade)
	   	               for(int i=0;i<tam;i++)
	                        maiorVetor[i]=vetor2[i];
				
				
			}
	   	 	
	   
	   
	   if( (pesoM < peso2) && (peso2 <= capacidade))
		   {

		   	for(int i=0;i<tam;i++)
	            maiorVetor[i]=vetor2[i];
	        
		   	cout<<"entrei mV < 2"<<endl;
		   	
		   }
		  
		else{	   
           if( (pesoM < peso1) && (peso1 <=capacidade))
		   {
            for(int i=0;i<tam;i++)
	            maiorVetor[i]=vetor1[i];
		   	
		   	cout<<"entrei mV < 1"<<endl;
		   	
		   }
		   
		}  
			
		
		//ele para, caso já se tenha achado um resultado ótimo
		if(pesoM==capacidade)
			break;
		
			
       //faz uma mutação com taxa de 0.5*capacidade de interação
	   if(i==limite*0.5)
	   {
	   	int muta;
	    muta=rand()%tam;
	    
          cout<<"muta: "<<muta<<endl;
        
          for(int i=0;i<tam;i++)
	      vetor1[i]=maiorVetor[i];
	   	
	    if(vetor1[muta]==0)
	    	vetor1[muta]=1;
	    else
	    	vetor1[muta]=0;
	   	
	   }
	   
	   	   
	   
	   i++;	
		
	}
	
	imprimeVetor(maiorVetor,tam);
	cout<<"área ocupada: "<<verificaPeso(vetorPesos,maiorVetor,tam)<<endl;
	cout<<"preço total dos carros: "<<verificaPeso(vetorPreco,maiorVetor,tam)<<endl;
	
	cout<<"\n\nvetor com área de cada carro"<<endl;
    imprimeVetorPesos(maiorVetor,vetorPesos,tam);
    
    cout<<"\n\nvetor com preço de cada carro"<<endl;
    imprimeVetorPesos(maiorVetor,vetorPreco,tam);
	
	
	
}