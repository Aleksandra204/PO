#include "Player.h"
#include "Enemy.h"
#include "GameObject.h"
#include <vector>

int main() {
    Player player;
    Enemy enemy;

    std::future<void> player_future = std::async(std::launch::async, &Player::update, &player);

    std::future<void> enemy_future = std::async(std::launch::async, &Enemy::update, &enemy);

    std::vector <GameObject*> objects;

    for(int i = 0; i < 5; i++){
      objects.push_back(&player);
      objects.push_back(&enemy);
    }

    std::vector<std::future<void>> futures;

    for(auto object : objects){
      if (auto player = dynamic_cast<Player*>(object)) {
        auto fut = std::async(std::launch::async, &Player::update, player);
        futures.push_back(std::move(fut));
      } else if (auto enemy = dynamic_cast<Enemy*>(object)) {
        auto fut = std::async(std::launch::async, &Enemy::update, enemy);
        futures.push_back(std::move(fut));
      }
    }

    for (auto &fut : futures) {
        fut.get();
    }

    player.attack();
    enemy.takeDamage(20);

    player_future.get();

    enemy_future.get();

    std::cout << "All updates completed!" << std::endl;

    return 0;
}

/*
Na co trzeba uwazac wykonujac zadania asynchronicznie -> MultiThreating
race conditions -> std::lock_guard<std::mutex>(m)
static variables X
thred pool sturation -> ThreadPool
*/