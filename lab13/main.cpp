#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Enemy.h"
#include "Action.h"

int main() {
  GameObject* player_1 = GameObject::addGameObject(new Player());
  GameObject* player_2 = GameObject::addGameObject(new Player("Ned"));
  GameObject* enemy_1 = GameObject::addGameObject(new Enemy("Cersei"));
  std::cout << "List of active game objects:" << std::endl;
  const std::vector<GameObject*>& gameObjects = GameObject::ActiveGameObjects();
  std::for_each(gameObjects.begin(), gameObjects.end(), [](GameObject* ago) {
      std::cout << ago->Name() << ", ";
  });
  std::cout << std::endl;

  for (GameObject* ago : GameObject::ActiveGameObjects()) {
    GameObjectAction::execute(ago);
  }

  GameObjectAction::execute<Player>(dynamic_cast<Player*>(player_2));
  GameObjectAction::execute<Enemy>(dynamic_cast<Enemy*>(enemy_1));

  GameObject::destroyGameObjects();
  return 0;
}

/* wynik:
List of active game objects:
Unnamed Player, Ned, Cersei, 
Executing action for a generic type: "Unnamed Player"
Executing action for a generic type: "Ned"
Executing action for a generic type: "Cersei"
Executing action specifically for Player: "Ned"
Rendering object
Updating object
Executing action specifically for Enemy: "Cersei"
Rendering object
Handling collision
Updating object
All active objects destroyed
*/