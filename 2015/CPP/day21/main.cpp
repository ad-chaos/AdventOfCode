#include <iostream>
#include <vector>

struct Item {
    int cost;
    int deal;
};

struct Player {
    int damage;
    int protection;
};
int main()
{
    std::vector<Item> Weapons {
        {8, 4}, {10, 5}, {25, 6}, {40, 7}, {74, 8},
    };
    std::vector<Item> Armours {
        {0,0}, {13, 1}, {31, 2}, {53, 3}, {75, 4}, {102, 5},
    };
    std::vector<Item> RingsAttacks {
        {25, 1}, {50, 2}, {100, 3}
    };
    std::vector<Item> RingsDefends {
        {20, 1}, {40, 2}, {80, 3}
    };

    int effective_damage {}, cost{};
    for(auto& weapon : Weapons) {
        for(auto& armour : Armours) {
            effective_damage = weapon.deal - armour.deal;
            cost += weapon.cost + armour.cost;
        }
    }
}
