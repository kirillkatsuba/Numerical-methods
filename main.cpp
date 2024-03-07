#include <iostream>
#include <limits>


template<class T>
void func(T number, std::string type)
{
    int exponent = 0;
    
    // Машинный ноль
    while (number != 0)
    {
        number = number / 2;
        exponent -= 1;
    };
    std::cout << "Машинный ноль в режиме "<< type <<" точности равен 2^{" << exponent << "}"<< std::endl;
    
    // Машинная бесконечность
    exponent = 0;
    number = 1;
    while (number != std::numeric_limits<T>::infinity())
    {
        number = number * 2;
        exponent += 1;
    };
    std::cout << "Машинная бесконечность в режиме "<< type <<" точности равен 2^{" << exponent << "}"<< std::endl;
    
    // Машинный эпсилон
    exponent = 0;
    number = 1;
    while (1 + number != 1)
    {
        number = number / 2;
        exponent -= 1;
    };
    std::cout << "Машинный эпсилон в режиме "<< type <<" точности равен 2^{" << exponent << "}\n"<< std::endl;
};

int main(int argc, const char * argv[])
{
    float number1 = 1;
    double number2 = 1;
    long double number3 = 1;
    
    func(number1, "одинарной");
    func(number2, "двойной");
    func(number3, "расширенной");

    return 0;
}
