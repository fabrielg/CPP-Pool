#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
    std::cout << "=== Create ClapTraps ===" << std::endl;
    ClapTrap c1("CL4P-TP");
    ClapTrap c2 = c1;
    c2.attack("a cactus");
    c2 = c1;

    std::cout << "\n=== Create FrapTraps ===" << std::endl;
    FragTrap f1("FR4V-TP");
    FragTrap f2(f1);
    f2.attack("a bee");
    f2 = f1;

    std::cout << "\n=== Test values ===" << std::endl;
    f1.attack("an enemy");
    f1.attack("another enemy");

    std::cout << "\n=== Test polymorphism ===" << std::endl;
    ClapTrap* poly = new FragTrap("POLY-TP");
    poly->attack("final boss");
    delete poly;

    std::cout << "\n=== Test special ===" << std::endl;
    f1.highFivesGuys();

    return 0;
}
