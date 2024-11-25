#ifndef ARVORE_BINARIA_HPP
#define ARVORE_BINARIA_HPP

#include "Node.hpp"
#include <string>
#include <vector>
#include <algorithm>

class BinaryTree {
private:
    std::unique_ptr<No> raiz;

    void inserir(std::unique_ptr<No>& no, const std::string& palavra);
    void buscarSugestoes(No* no, const std::string& prefixo, std::vector<std::string>& sugestoes) const;

public:
    BinaryTree();
    void inserir(const std::string& palavra);
    std::vector<std::string> obterSugestoes(const std::string& prefixo) const;
};

#endif // ARVORE_BINARIA_HPP
