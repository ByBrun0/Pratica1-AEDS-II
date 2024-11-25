#include "BinaryTree.hpp"

// Construtor
BinaryTree::BinaryTree() : raiz(nullptr) {}

// Inserção de palavras
void BinaryTree::inserir(std::unique_ptr<No>& no, const std::string& palavra) {
    if (!no) {
        no = std::make_unique<No>(palavra);
    } else if (palavra < no->palavra) {
        inserir(no->esquerda, palavra);
    } else if (palavra > no->palavra) {
        inserir(no->direita, palavra);
    }
}

void BinaryTree::inserir(const std::string& palavra) {
    inserir(raiz, palavra);
}

// Busca de sugestões
void BinaryTree::buscarSugestoes(No* no, const std::string& prefixo, std::vector<std::string>& sugestoes) const {
    if (!no) return;

    if (no->palavra.find(prefixo) == 0) { // Verifica se começa com o prefixo
        sugestoes.push_back(no->palavra);
    }

    buscarSugestoes(no->esquerda.get(), prefixo, sugestoes);
    buscarSugestoes(no->direita.get(), prefixo, sugestoes);
}

std::vector<std::string> BinaryTree::obterSugestoes(const std::string& prefixo) const {
    std::vector<std::string> sugestoes;
    buscarSugestoes(raiz.get(), prefixo, sugestoes);
    std::sort(sugestoes.begin(), sugestoes.end()); // Ordena alfabeticamente
    return sugestoes;
}
