#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "=== Create DiamondTrap ===" << std::endl;
    DiamondTrap d1("DI4M-TP");

    std::cout << "\n=== Copy and Assignment ===" << std::endl;
    DiamondTrap d2(d1);
    DiamondTrap d3;
    d3 = d1;

    std::cout << "\n=== Test attacks ===" << std::endl;
    d1.attack("an enemy");
    d2.attack("another enemy");
    d3.attack("a final boss");

    std::cout << "\n=== Test special functions ===" << std::endl;
    d1.guardGate();
    d1.highFivesGuys();
    d1.whoAmI();

    std::cout << "\n=== Test polymorphism ===" << std::endl;
    ClapTrap* poly = new DiamondTrap("POLY-TP");
    poly->attack("a dummy target");
    delete poly;

    std::cout << "\n=== End of program ===" << std::endl;
    return 0;
}
