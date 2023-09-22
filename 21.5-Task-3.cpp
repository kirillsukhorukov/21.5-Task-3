#include <iostream>
#include <string>
#include <cmath>

struct vector
{
    double x;
    double y;
};

//Фунция ввода и проверки вещественного числа
double input_double()
{
    bool error=false;
    std::string str;

    do
    {
        error=false;
        int pointCount=0;
        
        std::getline(std::cin, str);

        //Проверка первого знака
        if (!isdigit(str[0]) & str[0]!='-' & str[0]!='.') 
        {
            error=true;
            std::cerr << "Error! The entered data is not a real number! Please re-enter." << std::endl;
        }
        else if (str[0]=='.') pointCount++;
        //Проверка остальной строки
        else 
        for (int i=1; i<str.length(); i++)
        {
            if (str[i]=='.') pointCount++;
            else if (!isdigit(str[i]) || pointCount>1)
            {
                error=true;
                std::cerr << "Error! The entered data is not a real number! Please re-enter." << std::endl;
                i=str.length();
            } 
        }


    } while (error);

    double num = stod (str);
   
    return num;
}

//Функция ввода координат вектора
void input_coordinates(vector &vec)
{
    std::cout << "Enter the X coordinate of the vector: ";
    vec.x = input_double();
    std::cout << "Enter the Y coordinate of the vector: ";
    vec.y = input_double();
}

//Фунция сложения векторов
void add()
{
    vector vecA;
    vector vecB;
    
    std::cout << "--- Entering the coordinates of vector A ---" << std::endl;
    input_coordinates(vecA);
    std::cout << "--- Entering the coordinates of vector B ---" << std::endl;
    input_coordinates(vecB);

    std::cout << std::endl << "Result vector coordinates: x=" << vecA.x+vecB.x << " y=" << vecA.y+vecB.y << std::endl;
}

//Фунция вычитания векторов
void subtract()
{
    vector vecA;
    vector vecB;
    
    std::cout << "--- Entering the coordinates of vector A ---" << std::endl;
    input_coordinates(vecA);
    std::cout << "--- Entering the coordinates of vector B ---" << std::endl;
    input_coordinates(vecB);

    std::cout << std::endl << "Result vector coordinates: x=" << vecA.x-vecB.x << " y=" << vecA.y-vecB.y << std::endl;
}

//Фунция умножения вектора на скаляр
void scale()
{
    vector vec;

    std::cout << "--- Entering the coordinates of vector ---" << std::endl;
    input_coordinates(vec);
    std::cout << "Enter the scalar value: ";
    double scale = input_double();

    
    std::cout << std::endl << "Result vector coordinates: x=" << vec.x*scale << " y=" << vec.y*scale << std::endl;
}

//Фунция нахождения длины вектора
void length()
{
    vector vec;
    
    std::cout << "--- Entering the coordinates of vector ---" << std::endl;
    input_coordinates(vec);
    
    std::cout << std::endl << "Vector length=" << sqrt(pow(vec.x,2)+pow(vec.y,2)) << std::endl;
}

//Фунция нормализации вектора
void normalize()
{
    vector vec;

    std::cout << "--- Entering the coordinates of vector ---" << std::endl;
    input_coordinates(vec);

    double length = sqrt(pow(vec.x,2)+pow(vec.y,2));

    std::cout << std::endl << "Normalized vector coordinates: x=" << vec.x/length << " y=" << vec.y/length << std::endl;
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