#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "Node.hpp"
#include <iostream>
#include <vector>

class BinaryTree {
private:
    Node* root; // Raiz da árvore

    // Funções auxiliares privadas
    void insereAux(Node*& node, int valor);
    void imprimePreOrdemAux(Node* node);
    int calculaAlturaAux(Node* node);
    void caminhoMaisLongoAux(Node* node, std::vector<int>& caminhoAtual, std::vector<int>& maiorCaminho);
    void liberaMemoria(Node* node);

public:
    // Construtor e destrutor
    BinaryTree();
    ~BinaryTree();

    // Funções públicas
    void insere(int valor);
    void imprimePreOrdem();
    int calculaAltura();
    void caminhoMaisLongo();
    void remove(int valor); // Função pública para remoção de um nó
    Node* removeAux(Node* node, int valor); // Função auxiliar para remoção
};

#endif // BINARYTREE_HPP
