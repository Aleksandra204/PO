#include <iostream>
#include "Player.h"
#include "Enemy.h"

int main() {
  GameObject* player = GameObject::addGameObject(new Player());
  {
    GameObject* enemy = GameObject::addGameObject(new Enemy());
    GameObject::destroyGameObject(enemy);
  }
  GameObject* enemy = GameObject::addGameObject(new Enemy());

  performRuntimeTypeChecking(player);
  performRuntimeTypeChecking(enemy);

  for (GameObject* ago : GameObject::ActiveGameObjects()) {
    ago->action();
  }

  GameObject::destroyGameObjects();
  return 0;
}

/* wynik:
Player object is renderable collidable
Enemy object is renderable collidable updatable
Performing player-specific action... 
Rendering object
Handling collision
Performing enemy-specific action
Rendering object
Handling collision
Updating object
*/