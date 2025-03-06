#include "PlayerCharacter.h"
#include <memory>


int main() {
  
  std::unique_ptr<GameObject> gameObject = std::make_unique<PlayerCharacter>();
  std::unique_ptr<Renderable> renderableObject = std::make_unique<PlayerCharacter>();

  gutils::handleGameObject(gameObject.get());
  gutils::handleRenderable(renderableObject.get());

  return 0;

}

/* wynik:
Rendering GameObject
PlayerCharacter attacking!
Drawing Renderable
PlayerCharacter attacking!
*/