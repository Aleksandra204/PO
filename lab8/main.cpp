#include <iostream>
#include "Player.h"
#include "Enemy.h"

int main() {
  GameObject* player_1 = GameObject::addGameObject(new Player());
  GameObject* player_2 = GameObject::addGameObject(new Player("Ned"));
  {
    GameObject* enemy_1 = GameObject::addGameObject(new Enemy());
    GameObject* enemy_2 = GameObject::addGameObject(new Enemy("Cersei"));
    std::cout << "List of active game objects:" << std::endl;
    for (GameObject* ago : GameObject::ActiveGameObjects())
      std::cout << ago->Name() << ", ";
    std::cout << std::endl;
    GameObject::destroyGameObject(enemy_1);
  }
  GameObject::destroyGameObject(player_1);
  GameObject* enemy_1 = GameObject::addGameObject(new Enemy("Jaime"));

  for (GameObject* ago : GameObject::ActiveGameObjects()) {
    ago->action();
  }

  GameObject::destroyGameObjects();
  return 0;
}

/* wynik:
List of active game objects:
Unnamed Player, Ned, Unnamed Enemy, Cersei, 
Performing player-specific action for Ned:
Rendering object
Updating object
Performing enemy-specific action for Cersei:
Rendering object
Handling collision
Updating object
Performing enemy-specific action for Jaime:
Rendering object
Handling collision
Updating object
*/