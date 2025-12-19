#include "ScaveTrap.hpp"

int main()
{
    ScavTrap st("Jimmy");
    ScavTrap Now = st;

    st.attack("other");
    st.beRepaired(123);
    st.guardGate();
}