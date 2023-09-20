#include <iostream>
#include <string>
#include <cmath>

struct vector
{
    double x;
    double y;
};


//Фунция сложения векторов
void add()
{
    vector vecA;
    vector vecB;
    
    vecA.x = 2.5;
    vecA.y = 4.5;
    vecB.x = -2.5;
    vecB.y = 2.5;

    std::cout << "Result vector coordinates: x=" << vecA.x+vecB.x << " y=" << vecA.y+vecB.y << std::endl;
}

//Фунция вычитания векторов
void subtract()
{
    vector vecA;
    vector vecB;
    
    vecA.x = 2.5;
    vecA.y = 4.5;
    vecB.x = -2.5;
    vecB.y = 2.5;

    std::cout << "Result vector coordinates: x=" << vecA.x-vecB.x << " y=" << vecA.y-vecB.y << std::endl;
}

//Фунция умножения вектора на скаляр
void scale()
{
    vector vec;
    double scale=2.0;

    vec.x = 2.5;
    vec.y = 4.5;
    
    std::cout << "Result vector coordinates: x=" << vec.x*scale << " y=" << vec.y*scale << std::endl;
}

//Фунция нахождения длины вектора
void length()
{
    vector vec;
    
    vec.x = 1.0;
    vec.y = 1.0;
    
    std::cout << "Vector length=" << sqrt(pow(vec.x,2)+pow(vec.y,2)) << std::endl;
}

//Фунция нормализации вектора
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