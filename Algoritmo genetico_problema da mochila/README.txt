Autor: Vitor De Almeida Silva


Este é uma algorítmo genêtico para solucionar um problema de otimização de uma empresa de venda de carros. 

//problema: uma pequena empresa de compra e venda de carros adiquiriu um terreno com o objetivo de 
//construir um pátio e um galpão para colocar os carros. O objetivo da empresa é realizar um evento onde 
//as pessoas poderiam ver os carros que estão dentro do galpão, ela quer colocar os carros de acordo com 
//o preço e a área ocupada, seguindo os seguintes critérios:
//             * o preço dos carros devem ser somados para se ter um preço total
//             * a soma das áreas ocupadas pelos veiculos não deve exeder o limite do galpão exedido pela empresa (60 m^2)


O algorítmo funciona de forma simplificada, realizando somente crossing over e uma mutação aleatória que ocorre em tempo aleatório. O programa somente utiliza uma população de 3 indivíduos, sendo 2 pais e 1 que é o melhor individuo obtido a cada interação. o melhor individuo é selecionado a cada interação para realizar o crossing over com o segundo melhor indivíduo na população com o objetivo de objeter o resultado ótimo. 