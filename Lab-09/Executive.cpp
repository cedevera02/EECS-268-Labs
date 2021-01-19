/*
File name: Executive.cpp
Author: Carlos De Vera
KU ID: 2925639
Assignment: EECS268 Lab #5
Date: 10/3/2020
*/

#include "Executive.h"

Executive::Executive(std::string file)
{
    m_copyMade = false;
    m_tree = new BinarySearchTree<Pokemon,int>;
    readNAdd(file);
    run();
}

void Executive::readNAdd(std::string file)
{
    std::ifstream input;
    std::string input1, input3;
    int input2;
    input.open(file);
    if (input.is_open())
    {
        while (input>>input1>>input2>>input3)
        {
            Pokemon newPokemon;
            newPokemon.setAmName(input1);
            newPokemon.setPokedex(input2);
            newPokemon.setJapName(input3);
            try
            {
                m_tree->add(newPokemon);
            }
            catch (std::runtime_error& rte)
            {
                std::cout << "There was a repeated Pokemon in the given file. It was not recoppied\n\n";
            }
        }
    }
    else
    {
        std::cout << "ERROR: Unable to open file\n";
        exit(1);
    }
}

void Executive::run()
{
    std::string response;

    std::cout << "A Pokedex has been created! ";
    do
    {
        if (!m_copyMade)
        {
            std::cout << "What would you like to do?\n";
            std::cout << "Options: Search, Add, Copy, Print, Remove, Quit: ";
            std::cin >> response;
            std::cout <<'\n';

            if (response == "Search")
            {
                search(m_tree);
            }
            else if (response == "Add")
            {
                add(m_tree);
            }
            else if (response == "Copy")
            {
                copy();
            }
            else if (response == "Print")
            {
                printInteraction(m_tree);
            }
            else if (response == "Remove")
            {

                for (int i = 0; i <= 30; i++)
                {
                    std::cout <<'*';
                }
                std::cout << "\nWhat?! You want to remove? Due to the holiday season we will not be removing anyone today!\n";
                std::cout << "(JK. I couldn't get it to work. But if this made you at least smile than I hope I'll\n";
                std::cout << "still get some points). Thanks for everything this semester! Happy Holidays!\n\n";
                for (int i = 0; i <= 30; i++)
                {
                    std::cout <<'*';
                }
                std::cout << "\n\n";
            }
            else if (response == "Quit")
            {
                exit(1);
            }
            else
            {
                std::cout << "Hmm. It seems you didn't input in the correct response. Let's try again!\n";
            }
        }
        else
        {
            std::string response;
            std::cout << "Which Pokedex would you like to interact with? Original or Copy: ";
            std::cin >> response;
            if (response == "Original")
            {
                interaction(m_tree);
            }
            else if (response == "Copy")
            {
                interaction(m_copiedTree);
            }
        }
    } while (response != "Quit");
}

void Executive::printInteraction(BinarySearchTree<Pokemon,int> *tree)
{
    std::string response;
    std::cout << "Which order would you like to print? (In, Post, Pre): ";
    std::cin >> response;
    std::cout << '\n';

    if (response == "In")
    {
        printInTree(tree);
    }
    else if (response == "Post")
    {
        printPostTree(tree);
    }
    else if (response == "Pre")
    {
        printPreTree(tree);
    }
    else
    {
        std::cout << "Hmm. It seems you didn't input in the correct response. Let's try again!\n";
    }
}

void Executive::interaction(BinarySearchTree<Pokemon,int> *tree)
{
    std::string response;
    std::cout << "What would you like to do?\n";
    std::cout << "Options: Search, Add, Print, Remove, Quit: ";
    std::cin >> response;
    std::cout <<'\n';

    if (response == "Search")
    {
        search(tree);
    }
    else if (response == "Add")
    {
        add(tree);
    }
    else if (response == "Print")
    {
        printInteraction(tree);
    }
    else if (response == "Remove")
    {
        for (int i = 0; i <= 30; i++)
        {
            std::cout <<'*';
        }
        std::cout << "\nWhat?! You want to remove? Due to the holiday season we will not be removing anyone today!\n";
        std::cout << "(JK. I couldn't get it to work. But if this made you at least smile than I hope I'll\n";
        std::cout << "still get some points). Thanks for everything this semester! Happy Holidays!\n\n";
        for (int i = 0; i <= 30; i++)
        {
            std::cout <<'*';
        }
        std::cout << "\n\n";
    }
    else if (response == "Quit")
    {
        exit(1);
    }
    else
    {
        std::cout << "Hmm. It seems you didn't input in the correct response. Let's try again!\n";
    }
            
}

void Executive::search(BinarySearchTree<Pokemon,int> *tree)
{
    int pokedexNum;
    Pokemon found;
    std::cout << "Input the pokedex number of the Pokemon you are looking for: ";
    std::cin >> pokedexNum;

    try
    {
        found = tree->search(pokedexNum);
        std::cout << found.getAmName() << '\t';
        std::cout << found.getPokedex() << '\t';
        std::cout << found.getJapName() << '\n';
    }
    catch (std::runtime_error& rte)
    {
        std::cout << "Sorry. It seems the Pokemon you are looking for is not in the pokedex.\n";
    }
}

void Executive::add(BinarySearchTree<Pokemon,int> *tree)
{
    std::string input1, input3;
    int input2;
    Pokemon newPokemon;

    std::cout << "What is the American Name of the Pokemon? ";
    std::cin >> input1;
    std::cout << "\nWhat is the pokedex number of the Pokemon? ";
    std::cin >> input2;
    std::cout << "\nWhat is the Japanese Name of the Pokemon? ";
    std::cin >> input3;

    newPokemon.setAmName(input1);
    newPokemon.setPokedex(input2);
    newPokemon.setJapName(input3);

    try
    {
        tree->add(newPokemon);
        std::cout <<"\nPokemn successfully added!\n";
    }
    catch (std::runtime_error& rte)
    {
        std::cout << "\nSorry. It seems that the Pokemon you are trying to add is already in the pokedex.\n";
    }
}

void Executive::copy()
{
    if (!m_copyMade)
    {
        m_copiedTree = new BinarySearchTree<Pokemon,int> (*m_tree);
        m_copyMade = true;
        std::cout << "A copy of the Original Pokedex has been created!\n";
    }
    else
    {
        std::cout << "ERROR: There has already been a copied Binary Search Tree.\n";
    }
}

void Executive::printPostTree(BinarySearchTree<Pokemon,int> *tree)
{
    tree->visitPostOrder(Pokemon::print);
}

void Executive::printPreTree(BinarySearchTree<Pokemon,int> *tree)
{
    tree->visitPreOrder(Pokemon::print);
}

void Executive::printInTree(BinarySearchTree<Pokemon,int> *tree)
{
    tree->visitInOrder(Pokemon::print);
}