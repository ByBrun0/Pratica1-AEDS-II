#include "Dicionary.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "Qual numero de palavras deseja utilizar do dicionário? ";
        int limite;
        std::cin >> limite;

        std::string nomeArquivo = "Input/words.txt";
        Dicionary dicionario(nomeArquivo, limite);

        dicionario.Buscar();
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
