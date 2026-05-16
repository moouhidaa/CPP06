#include  "ScalarConverter.hpp"

void  infinity_literals(std::string  input)
{
    char  sign;
    std::cout <<"char: impossible\n";
    std::cout <<"int: impossible\n";
    if(input[0] ==  '-')
        sign = '-';
    else
        sign = 0;
    std::cout <<"float: "<< sign  <<"nanf\n";
    std::cout <<"double: "<< sign <<"nan\n"; 
}

void print_it(std::string  input)
{
    double  dd = atof(input.c_str());
    if(dd > 127 ||  dd <= -128)
        std::cout << "char: Impossible\n";
    else if(dd <= 32 || dd > 126)
        std::cout  << "char: Not Displayable\n";
    else
        std::cout << "char:" << static_cast<char>(dd) << std::endl;
    if(dd > INT_MAX || dd < INT_MIN)
        std::cout <<  "int: Impossible\n";
    else
        std::cout  << "int:" << static_cast<int>(dd) <<  std::endl;
    std::cout << std::fixed << std::setprecision(1);
    if(dd > __FLT_MAX__ &&  dd < __FLT_MIN__)
        std::cout <<  "float: Impossible";
    else
        std::cout << "float: " << static_cast<float>(dd) << "f"<< std::endl;
    std::cout << std::fixed << "double:" << dd << std::endl;
}

void  parse_it(std::string input)
{
    int count_it = 0;
    int flag = 1;
    for(size_t i = 0; i < input.size();i++)
    {
        if(std::isalpha(input[i]))
        {
            if(input[i] != 'f' || i != input.size() - 1)
                flag = 0;
            else    
                flag = input[i];
        }
        if(input[i] == '.')
            count_it++;
        if(input[i] == '-' || input[i] == '+')
        {
            if(input[i + 1] == '-' || input[i] ==  '+')
            {
                flag = 0;
                break;
            }
        }
    }
    if(count_it > 1  || input[0] == '.' || input[input.size()-1] == '.' || flag == 0)
    {
        std::cout  << "The Input Invalid\n";
        return;
    }
    print_it(input);
}



void    ScalarConverter::convert(std::string  converter)
{
    if(converter == "-inff" || converter == "+inff" || 
        converter  ==  "-inf" ||converter == "+inf")
        infinity_literals(converter);
    else
        parse_it(converter);
}
