#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) :
    ClapTrap("DiamondTrap_clap_name"),
    ScavTrap(),
    FragTrap(),
    _name("DiamondTrap")
{
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "Default constructor DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap( const std::string& name ) :
    ClapTrap(name + "_clap_name"),
    ScavTrap(name),
    FragTrap(name),
    _name(name)
{
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "String constructor DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& copy ) :
    ClapTrap(copy),
    ScavTrap(copy),
    FragTrap(copy),
    _name(copy._name)  // ✅ Ajouté dans la liste d'initialisation
{
    std::cout << "Copy constructor DiamondTrap called" << std::endl;
    // ✅ Enlevé : *this = copy;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "Destructor DiamondTrap called" << std::endl;
}

DiamondTrap&  DiamondTrap::operator=( const DiamondTrap& copy )  // ✅ Enlevé const
{
    if (this == &copy)  // ✅ Ajouté : protection auto-assignation
        return *this;
        
    ClapTrap::operator=(copy);
    this->_name = copy._name;
    std::cout << "Assignment operator DiamondTrap called" << std::endl;
    return *this;
}

// ✅ ENLEVÉ : void DiamondTrap::attack()
// attack() est maintenant héritée automatiquement de ScavTrap grâce à virtual

void    DiamondTrap::whoAmI( void )
{
    std::cout   << "My name is " << this->_name << std::endl
                << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}