#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
    int value;          // Valor armazenado no nó
    Node* left;         // Ponteiro para o filho à esquerda
    Node* right;        // Ponteiro para o filho à direita

    // Construtor
    Node(int val);
};

#endif // NODE_HPP
