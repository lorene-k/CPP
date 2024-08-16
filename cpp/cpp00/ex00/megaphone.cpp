#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i;
    int j;

    j = 0;
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
        while (av && av[++j])
        {
            i = -1;
            while (av[j][++i])
                std::cout << (char)std::toupper(av[j][i]);
        }
    std::cout << "\n";
    return (0);
}
