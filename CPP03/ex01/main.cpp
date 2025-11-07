#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
    std::cout << "=== Create ClapTraps ===" << std::endl;
    ClapTrap c1("CL4P-TP");
    ClapTrap c2 = c1;
    c2.attack("a cactus");
    c2 = c1;

    std::cout << "\n=== Create ScavTraps ===" << std::endl;
    ScavTrap s1("SC4V-TP");
    ScavTrap s2(s1);
    s2.attack("a bee");
    s2 = s1;

    std::cout << "\n=== Test values ===" << std::endl;
    s1.attack("an enemy");
    s1.attack("another enemy");

    std::cout << "\n=== Test polymorphism ===" << std::endl;
    ClapTrap* poly = new ScavTrap("POLY-TP");
    poly->attack("final boss");
    delete poly;

    std::cout << "\n=== Test special ===" << std::endl;
    s1.guardGate();

    return 0;
}
