#include "Node.hpp"

No::No(std::string palavra) : palavra(std::move(palavra)), esquerda(nullptr), direita(nullptr) {}
