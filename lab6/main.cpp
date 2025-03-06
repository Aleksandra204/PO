#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include "Npc.h"

int main() {
  Player player;
  Enemy enemy;
  NPC npc;

  player.printComplexity();
  player.interact();
  enemy.interact();
  npc.interact();

  CompareCplx compareComplexity;

  std::cout << "Is the player more complex than the enemy? " 
            << (compareComplexity(&player, &enemy) ? "Yes" : "No") << std::endl;
  std::cout << "Is the enemy more complex than the NPC? " 
            << (compareComplexity(&enemy, &npc) ? "Yes" : "No") << std::endl;
  std::cout << "Is the NPC more complex than the player? " 
            << (compareComplexity(&npc, &player) ? "Yes" : "No") << std::endl;

  return 0;
}

/* wynik:
Player complexity: HIGHEST
Player moves!
Enemy attacks!
NPC talks!
Is the player more complex than the enemy? Yes
Is the enemy more complex than the NPC? Yes
Is the NPC more complex than the player? No
*/