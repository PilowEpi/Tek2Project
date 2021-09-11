
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include "Ice.hpp"
#include "Cure.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

#include <iostream>
#include <memory>

int main ()
{
    IMateriaSource * src (new MateriaSource () ) ;
    src -> learnMateria (new Ice ) ;
    src -> learnMateria (new Cure ) ;
    std::unique_ptr<ICharacter> perceval (new Character (" Perceval ") ) ;
    auto tmp = src -> createMateria ("ice ") ;
    perceval -> equip ( tmp ) ;
    tmp = src -> createMateria (" cure ") ;
    perceval -> equip ( tmp ) ;
    std::unique_ptr<ICharacter> bohort (new Character (" Bohort ") ) ;
    perceval -> use (0 , * bohort ) ;
    perceval -> use (1 , * bohort ) ;
    return 0;
}