#include "DiamondTrap.hpp"

int main()
{
        // {
        //         DiamondTrap dt("Jim");

        //         dt.attack("Kim");
        //         dt.beRepaired(12);
        //         dt.highFiveGuys();
        //         dt.guardGate();
        //         dt.whoAmi();
        // }
        std::cout << "=========================\n\n";
        {
                DiamondTrap dt("Jim");
                
                dt.beRepaired(12);
                DiamondTrap dt2 = dt;
                dt2.highFiveGuys();
                dt2.guardGate();
                dt2.whoAmi();
        }
        // std::cout << "=========================\n\n";
        // {
        //         DiamondTrap dt("Jim");
        //         DiamondTrap dt2;
        //         dt2 = dt;

        //         dt2.attack("Kim");
        //         dt2.beRepaired(12);
        //         dt2.highFiveGuys();
        //         dt2.guardGate();
        //         dt2.whoAmi();
        // }
        // return 0;
}