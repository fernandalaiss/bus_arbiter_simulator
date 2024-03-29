#include <iostream>
#include <vector>
#include <ctime>

void prioridadeFixa(int quantia_p, int prioridades[], std::vector <int> solicitacoes){
	std::cout << "PRIORIDADE FIXA: ";
	for(int p = 3; p>0; p--){
		for(int i = 0; i < solicitacoes.size(); i++){
			if(prioridades[solicitacoes[i]-1] == p){
				std::cout << solicitacoes[i] << " ";
			}
		}
	}
	std::cout << "\n";
}

void prioridadeRotativa(int quantia_p, int prioridades[], std::vector <int> solicitacoes){
	std::cout << "PRIORIDADE ROTATIVA: ";
	for(int p = 1; p <= 3; p++){
		for(int i = 0; i < solicitacoes.size(); i++){
			if(prioridades[solicitacoes[i]-1] == p){
				std::cout << solicitacoes[i] << " ";
			}
		}
	}
	std::cout << "\n";
}

void justica(std::vector <int> tempo, std::vector <int> solicitacoes){
	std::cout << "JUSTIÇA: ";
	
	while(solicitacoes.size() > 0){
		for(int i = 0; i < solicitacoes.size(); i++){
			if(tempo[i] >= 5){
				std::cout << solicitacoes[i] << " ";
				tempo[i] -= 5;
			}else{
				solicitacoes.erase(solicitacoes.begin()+i);
				tempo.erase(tempo.begin()+i);
				i--;
			}
		}
	}
	std::cout << "\n";
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
	
	std::vector<int> solicitacoes;
	int periferico;
	std::cout << "\n3. Informe a ordem de solicitação dos periféricos"
			  << "(Digite os nº's referentes aos periféricos na ordem desejada; para encerrar as solicitações, digite 0):" 
			  << std::endl;
	std::cout << "Ordem: ";
	do{
		std::cin >> periferico;
		if(periferico != 0)
			solicitacoes.push_back(periferico);
	}while(periferico != 0);

	std::vector <int> tempo;
	int t;
	std::cout << "\n4. Informe o tempo que cada periférico precisa para enviar/receber informações (múltiplos de 5): " << std::endl;
	for (int i = 0; i < solicitacoes.size(); i++){
		std::cout << "Solicitação " << i+1 << ": ";
		std::cin >> t;
		tempo.push_back(t);
	}
	
	std::cout << "\nSolicitações atendidas utilizando diferentes arbitragens de barramento: " << std::endl;
	
	auto inicio = std::clock();
	prioridadeFixa(quantia_p, prioridades, solicitacoes);
	double duracao = (double)((std::clock() - inicio)/(double)CLOCKS_PER_SEC);
	std::cout.precision(10);
	std::cout << "Tempo de compilação: " << duracao << " segundos.\n\n";
	
	auto inicio2 = std::clock();
	prioridadeRotativa(quantia_p, prioridades, solicitacoes);
	double duracao2 = (double)((std::clock() - inicio2)/(double)CLOCKS_PER_SEC);
	std::cout.precision(10);
	std::cout << "Tempo de compilação: " << duracao2 << " segundos.\n\n";

	auto inicio3 = std::clock();
	justica(tempo, solicitacoes);
	double duracao3 = (double)((std::clock() - inicio3)/(double)CLOCKS_PER_SEC);
	std::cout.precision(10);
	std::cout << "Tempo de compilação: " << duracao3 << " segundos.\n\n";

	
	return 0;
}
