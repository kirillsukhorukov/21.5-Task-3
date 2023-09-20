#include <iostream>
#include <string>

struct vector
{
    double x;
    double y;
};



void add()
{
    vector vecA;
    vector vecB;
}

void subtract()
{
    vector vecA;
    vector vecB;
}

void scale()
{
    vector vecA;
    vector vecB;
}

void length()
{
    vector vecA;
    vector vecB;
}

void normalize()
{
    vector vecA;
    vector vecB;
}

int main()
{
    std::cout << "------ Math vector program ------" << std::endl << std::endl;


    std::cout << "Enter the command:" << std::endl;
    std::cout << "'add' - addition of two vectors;" << std::endl;
    std::cout << "'subtract' - subtracting two vectors" << std::endl;
    std::cout << "'scale' - multiplying a vector by a scalar;" << std::endl;
    std::cout << "'length' - finding the length of a vector;" << std::endl;
    std::cout << "'normalize' - vector normalization;" << std::endl;
    std::cout << "'quit' - terminate program execution." << std::endl << std::endl;
    
    bool error = false;
    std::string str;
    do
    {
        error = false;
        std::getline(std::cin,str);
        if (str == "add") add();
        else if (str == "subtract") subtract();
        else if (str == "scale") scale();
        else if (str == "length") length();
        else if (str == "normalize") normalize();
        else if (str == "quit") 
        {
            std::cout << "--- Program completed ---" << std::endl;
            return 1;
        }
        else 
        {
            std::cerr <<"Error! Repeat input." << std::endl;
            error = true;
        }
    } while (error);

    std::cout << "--- Program completed ---" << std::endl;
    return 1;
}