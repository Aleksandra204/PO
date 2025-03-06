#include <iostream>
#include "GameObjectStore.h"
#include "Action.h"

int main() {
  GameObjectStore& store = GameObjectStore::instance();

  GameObject* player_2 = store.addGameObject(new Player("Ned"));
  GameObject* enemy_1 = store.add<Enemy>("Cersei");
  auto player_2_ptr = dynamic_cast<Player*>(player_2);
  std::cout << *player_2 << ", " << *player_2_ptr << std::endl;

  for (const auto& ago : store.getActiveGameObjects())
    GameObjectAction::execute<GameObject>(ago);

  GameObjectAction::execute<Player>(player_2_ptr);
  GameObjectAction::execute<Enemy>(dynamic_cast<Enemy*>(enemy_1));

  const std::vector<GameObject*> sortedGameObjects = store.getSortedGameObjectsByName();
  std::cout << "List of sorted game objects:" << std::endl;
  for(const auto& go : sortedGameObjects) 
    std::cout << go->Name() << std::endl;

  store.destroyGameObjects();
  return 0;
}

/* wynik:
Ned(GameObject), Ned(Player)
Executing generic action for: "Ned"
Executing generic action for: "Cersei"
Executing action specifically for Player: "Ned"
Rendering object
Updating object
Executing action specifically for Enemy: "Cersei"
Rendering object
Handling collision
Updating object
List of sorted game objects:
Cersei
Ned
All active objects destroyed.
*/