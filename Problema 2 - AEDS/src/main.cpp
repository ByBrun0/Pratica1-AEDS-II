#include "BinaryTree.hpp"
#include <fstream>
#include <sstream>
#include <string>


int main() {
    int option;
    int num;
    BinaryTree tree;
    std::ifstream file("Input/number.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }
    std::string line;
    std::vector<int> numbers;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string number;

        // Split the line by commas and store each number in the vector
        while (std::getline(ss, number, ',')) {
            try {
                numbers.push_back(std::stoi(number)); // Convert string to int
            } catch (const std::invalid_argument &e) {
                std::cerr << "Invalid number in the file: " << number << std::endl;
            }
        }
    }

    for (int i = 0; i < numbers.size(); ++i) {
        tree.insere(numbers[i]);
    }

    // Close the file
    file.close();
    std::cout << "Altura da árvore inicial: " << tree.calculaAltura() - 1 << std::endl;
    while (option != 4) {
        std::cout << "Insira 1: Inserir\nInsira 2: Remover\nInsira 3: Altura\nInsira 4: Sair" << std::endl;

        std::cout << "Qual opcao deseja:" << std::endl;

        std::cin >> option;


        switch (option) {
            case 1:
                std::cout << "Digite o valor a inserir:" << std::endl;
                std::cin >> num;
                tree.insere(num);
                break;

            case 2:
                std::cout << "Digite o valor a remover:" << std::endl;
                std::cin >> num;
                tree.remove(num);
                break;

            case 3:
                std::cout << "Altura da árvore atual: " << tree.calculaAltura() - 1 << std::endl;
                std::cout << "Impressão em pré-ordem: ";
                tree.imprimePreOrdem();
                tree.caminhoMaisLongo();
                break;

            case 4:
                std::cout << "Saindo..." << std::endl;
                break;

            default:
                std::cout << "Opcao invalida" << std::endl;
                break;
        }
    }

    return 0;
}
