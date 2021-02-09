#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;


// By Vitor de Almeida Silva


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

//isto é um treino basico de algoritimo genêtico
//este código faz um crosing over e uma mutação
//ambos sem seguir nem um critério de realização
//que não seja os próprios da ação, ou seja, não foi aplicada
//probabilidade e estatística alguma


//obs: este algoritimo só acha uma combinação qualquer que somada os pesos resulta em
//um valor próximo ou igual a capacidade da mochila. Não foi seguide nem um critério do tipo
//                     *Deve aver mais qtd de itens possivel;
//                     *Deve-se somar os menores ou maiores pesos primeiro;
//                     *etc...

int main()
{
   // vector<int> *lista=new vector<int>();
	
	int tam=20;
	
	srand(time(NULL));
	
	int vetorPesos[20]={5,10,14,9,3,1,7,60,8,10,1,23,22,12,1,100,1,7,8,4};
	//int vetorPesos[20]={1,1,1,1,1,1,1,2,2,2,2,1,1,2,2,2,3,3,4,4};
	
	int vetor1[tam],vetor2[tam];
	
	int maiorVetor[tam];
	
	int capacidade=300;

	int i=0,p;
	
	
	
	
	//pai e mãe inicial
	//int vetor1[20]={1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
	//int vetor2[20]={0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1};
	
	//preenchimento aleatório dos vetóres
	 for(int i=0;i<tam;i++)
	 {
	 	vetorPesos[i]=rand()%40;
	 	vetor1[i]=rand()%2;
	 	vetor2[i]=rand()%2;
	 }
	
	
	
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
	
   
   int limite=100000;
   
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
		   	//lista->push_back(vetor2);
		   	//*maiorVetor=*vetor2;
		   	for(int i=0;i<tam;i++)
	            maiorVetor[i]=vetor2[i];
	        
		   	cout<<"entrei mV < 2"<<endl;
		   	
		   }
		  
		else{	   
           if( (pesoM < peso1) && (peso1 <=capacidade))
		   {
		   	//lista->push_back(vetor2);
		   	//*maiorVetor=*vetor1;
            for(int i=0;i<tam;i++)
	            maiorVetor[i]=vetor1[i];
		   	
		   	cout<<"entrei mV < 1"<<endl;
		   	
		   }
		   
		}  
			
		
		//ele para caso já se tenha achado um resultado ótimo
		if(pesoM==capacidade)
			break;
		
			
       //faz uma mutação 
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
	cout<<"maior peso: "<<verificaPeso(vetorPesos,maiorVetor,tam)<<endl;
	
    imprimeVetorPesos(maiorVetor,vetorPesos,tam);
	
	
	
}

