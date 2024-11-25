#include "Dicionary.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

void Dicionary::carregarPalavrasDeArquivo(const std::string& nomeArquivo, int limite) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo.");
    }

    std::string palavra;
    while (arquivo >> palavra && todasPalavras.size() < limite) {
        todasPalavras.push_back(palavra);
        arvore.inserir(palavra);
    }

    arquivo.close();
}

Dicionary::Dicionary(const std::string& nomeArquivo, int limite) {
    carregarPalavrasDeArquivo(nomeArquivo, limite);
}

void Dicionary::Buscar() {
    std::string prefixo;

    std::cout << "Comece a digitar uma palavra (caso queira sair digite 'sair'): ";
    while (std::cin >> prefixo) {
        if (prefixo == "sair" || prefixo == "Sair" || prefixo == "SAIR") {
            break;
        }
        auto sugestoes = arvore.obterSugestoes(prefixo);

        if (sugestoes.empty()) {
            std::cout << "Nenhuma palavra encontrada com este prefixo '" << prefixo << "'.\n";
        } else {

            std::cout << "Numero total de sugestoes: " << sugestoes.size() << "\n";

            std::cout << "As sugestoes sao:" << "\n";

            int k=0;
            for (const auto& palavra : sugestoes) {
                std::cout << palavra << " ";
                k++;
                if (k%10 == 0 ) {
                    std::cout << std::endl;
                }
            }
            std::cout << std::endl;
        }

        if (sugestoes.size() == 1 && sugestoes[0] == prefixo) {
            std::cout << "Palavra desejada seria: " << sugestoes[0] << std::endl;
            break;
        }

        std::cout << "\nDigite outra letra ou prefixo para continuar a busca: ";
    }
}
