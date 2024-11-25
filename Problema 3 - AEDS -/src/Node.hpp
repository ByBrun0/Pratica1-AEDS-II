#ifndef NO_HPP
#define NO_HPP

#include <string>
#include <memory>

class No {
public:
    std::string palavra;
    std::unique_ptr<No> esquerda;
    std::unique_ptr<No> direita;

    No(std::string palavra);
};

#endif // NO_HPP
