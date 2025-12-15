#include "ClapTrap.hpp"
void test_clap_trap()
{
    // --- 1. Construction and Initialization Test ---
    std::cout << "\n--- TEST 1: CONSTRUCTION & INITIAL STATE ---\n";
    ClapTrap clap("T-3000"); // Constructor message should appear here

    // --- 2. Take Damage Tests (Clamping & Death) ---
    std::cout << "\n--- TEST 2: TAKE DAMAGE ---\n";
    clap.takeDamage(5);    // Should show 5 damage taken, 5 HP remaining
    clap.takeDamage(4);    // Should show 4 damage taken, 1 HP remaining
    clap.takeDamage(100);  // Damage exceeds HP, should clamp HP to 0. Message: "destroyed!"
    clap.takeDamage(1);    // Called after 0 HP. Message: "already dead/cannot take damage"

    // --- 3. Repair Tests (Success, Cost, No Energy) ---
    // Note: Repairing only works if ClapTrap has HP and EP. 
    // Since HP is 0, we can test that action is blocked.

    std::cout << "\n--- TEST 3: REPAIR (BLOCKED BY 0 HP) ---\n";
    // Check if being dead blocks other actions
    clap.beRepaired(2);  // Should be blocked by 0 HP. Message: "cannot do anything if it has no hit points"

    // We can't fully test repair/attack costs until we create a new ClapTrap.
    // Let's create a new one to continue testing actions.
    
    std::cout << "\n--- TEST 4: NEW CLAPTRAP FOR ACTION TESTS ---\n";
    ClapTrap action_bot("ActionBot");

    // Test successful repair and cost
    action_bot.takeDamage(5); // Bring HP down to 5
    action_bot.beRepaired(3); // Should cost 1 EP, HP goes to 8. Message: "EP remaining: 9"

    // Test draining Energy Points
    std::cout << "\n--- TEST 5: DRAIN ENERGY POINTS (9 remaining) ---\n";
    for (int i = 0; i < 9; ++i)
    {
        action_bot.attack("Target"); // Should cost 1 EP each time.
    }

    // Test action blocked by no Energy
    std::cout << "\n--- TEST 6: ACTION BLOCKED BY 0 ENERGY ---\n";
    action_bot.attack("FinalTarget"); // Should be blocked by 0 EP. Message: "cannot do anything if it has no energy points"
    action_bot.beRepaired(1);       // Should be blocked by 0 EP.

    // Note: The destruction messages for 'clap' and 'action_bot' 
    // will appear automatically when this function finishes.
}

int main ()
{
	test_clap_trap();
}

