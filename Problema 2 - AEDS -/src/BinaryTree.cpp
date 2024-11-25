#include "BinaryTree.hpp"
#include <algorithm>

// Construtor
BinaryTree::BinaryTree() : root(nullptr) {}

// Destrutor para liberar memória
BinaryTree::~BinaryTree() {
    liberaMemoria(root);
}

// Função auxiliar para liberar memória
void BinaryTree::liberaMemoria(Node* node) {
    if (node == nullptr) return;
    liberaMemoria(node->left);
    liberaMemoria(node->right);
    delete node;
}

// Função auxiliar para inserção
void BinaryTree::insereAux(Node*& node, int valor) {
    if (node == nullptr) {
        node = new Node(valor);
    } else if (valor < node->value) {
        insereAux(node->left, valor);
    } else {
        insereAux(node->right, valor);
    }
}

// Função pública para inserção
void BinaryTree::insere(int valor) {
    insereAux(root, valor);
    std::cout << "Nível máximo atual: " << calculaAltura() - 1 << std::endl;
}

// Função auxiliar para imprimir pré-ordem
void BinaryTree::imprimePreOrdemAux(Node* node) {
    if (node == nullptr) return;
    std::cout << node->value << " ";
    imprimePreOrdemAux(node->left);
    imprimePreOrdemAux(node->right);
}

// Função pública para imprimir pré-ordem
void BinaryTree::imprimePreOrdem() {
    imprimePreOrdemAux(root);
    std::cout << std::endl;
}

// Função auxiliar para calcular a altura da árvore
int BinaryTree::calculaAlturaAux(Node* node) {
    if (node == nullptr) return 0;
    int alturaEsquerda = calculaAlturaAux(node->left);
    int alturaDireita = calculaAlturaAux(node->right);
    return 1 + std::max(alturaEsquerda, alturaDireita);
}

// Função pública para calcular a altura da árvore
int BinaryTree::calculaAltura() {
    return calculaAlturaAux(root);
}

// Função auxiliar para encontrar o caminho mais longo
void BinaryTree::caminhoMaisLongoAux(Node* node, std::vector<int>& caminhoAtual, std::vector<int>& maiorCaminho) {
    if (node == nullptr) return;
    caminhoAtual.push_back(node->value);
    if (node->left == nullptr && node->right == nullptr) { // Nó folha
        if (caminhoAtual.size() > maiorCaminho.size()) {
            maiorCaminho = caminhoAtual;
        }
    }
    caminhoMaisLongoAux(node->left, caminhoAtual, maiorCaminho);
    caminhoMaisLongoAux(node->right, caminhoAtual, maiorCaminho);
    caminhoAtual.pop_back();
}

// Função pública para encontrar e exibir o caminho mais longo
void BinaryTree::caminhoMaisLongo() {
    std::vector<int> caminhoAtual, maiorCaminho;
    caminhoMaisLongoAux(root, caminhoAtual, maiorCaminho);
    std::cout << "Caminho mais longo: ";
    for (int v : maiorCaminho) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

Node* encontraPredecessor(Node* node) {
    Node* atual = node->left;
    while (atual->right != nullptr) {
        atual = atual->right;
    }
    return atual;
}

Node* BinaryTree::removeAux(Node* node, int valor) {
    if (node == nullptr) return nullptr;

    if (valor < node->value) {
        node->left = removeAux(node->left, valor);
    } else if (valor > node->value) {
        node->right = removeAux(node->right, valor);
    } else {
        // Caso 1: Nó sem filhos
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // Caso 2: Nó com um filho
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Caso 3: Nó com dois filhos
        else {
            Node* predecessor = encontraPredecessor(node);
            node->value = predecessor->value; // Substitui o valor pelo predecessor
            node->left = removeAux(node->left, predecessor->value); // Remove o predecessor
        }
    }
    return node;
}

void BinaryTree::remove(int valor) {
    root = removeAux(root, valor);
    std::cout << "Nível máximo atual: " << calculaAltura() - 1 << std::endl;
}
