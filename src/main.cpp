#include <iostream>
#include <queue>

void prioridadeFixa(int quantia_p, int prioridades[], int tempo[], std::queue <int> solicitacoes){
	std::cout << "PRIORIDADE FIXA: ";
	//obedencendo a ordem de solicitações, imprime as com maior prioridade, de 5 em 5 tempos
}

void prioridadeRotativa(int quantia_p, int prioridades[], int tempo[], std::queue <int> solicitacoes){

}

void justica(int quantia_p, int prioridades[], int tempo[], std::queue <int> solicitacoes){

}

int main(){
	int quantia_p;

	std::cout << "Simulador de Árbitro de Barramento" << std::endl;
	std::cout << "\n1. Informe a quantidade de periféricos: ";
	std::cin >> quantia_p;

	int prioridades[quantia_p];
	std::cout << "\n2. Informe a prioridade de cada periférico (1 a 3, sendo 1 a mais baixa): " << std::endl;
	for(int i = 0; i < quantia_p; i++){ 
		std::cout << "Periférico " << i+1 << ": "; 
		std::cin >> prioridades[i];
	}
	
	std::queue <int> solicitacoes;
	int periferico;
	std::cout << "\n3. Informe a ordem de solicitação dos periféricos"
			  << "(Digite os nº's referentes aos periféricos na ordem desejada; para encerrar as solicitações, digite 0):" 
			  << std::endl;
	std::cout << "Ordem: ";
	do{
		std::cin >> periferico;
		if(periferico != 0)
			solicitacoes.push(periferico);
	}while(periferico != 0);

	//talvez aqui seja percebido q queue não é uma boa escolha pois, pra imprimir cada periférico
	//e perguntar quanto tempo ele vai levar, precise apagar o primeiro elemento, perdendo todos os dados
	int tempo[solicitacoes.size()];
	std::cout << "\n4. Informe o tempo que cada periférico precisa para enviar/receber informações (múltiplos de 5): " << std::endl;
	for (int i = 0; i < solicitacoes.size(); i++){
		std::cout << "Periférico " << i+1 << ": ";
		std::cin >> tempo[i];
	}
	
	std::cout << "\nSolicitações atendidas utilizando diferentes arbitragens de barramento: " << std::endl;
	prioridadeFixa(quantia_p, prioridades, tempo, solicitacoes);
	prioridadeRotativa(quantia_p, prioridades, tempo, solicitacoes);
	justica(quantia_p, prioridades, tempo, solicitacoes);

	return 0;
}