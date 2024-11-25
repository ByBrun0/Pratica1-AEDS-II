#ifndef DICIONARIO_HPP
#define DICIONARIO_HPP

#include "BinaryTree.hpp"
#include <vector>
#include <string>

class Dicionary {
private:
    BinaryTree arvore;
    std::vector<std::string> todasPalavras;

    void carregarPalavrasDeArquivo(const std::string& nomeArquivo, int limite);

public:
    Dicionary(const std::string& nomeArquivo, int limite);
    void Buscar();
};

#endif // DICIONARIO_HPP
