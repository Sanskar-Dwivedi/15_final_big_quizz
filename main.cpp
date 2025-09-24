#include <iostream>
#include "Random.h"

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterType
    };

    Monster(Type type, std::string name, std::string roar, int hitPoints) // constructor
        : m_type{type},
          m_name{name},
          m_roar{roar},
          m_hitPoints{hitPoints}
    {
    }

    std::string getTypeString()
    {
        switch (m_type)
        {
        case dragon:        return "dragon";
        case goblin:        return "goblin";
        case ogre:          return "ogre";
        case orc:           return "orc";
        case skeleton:      return "skeleton";
        case troll:         return "troll";
        case vampire:       return "vampire";
        case zombie:        return "zombie";
        }
        return "???";
    }

    void print()
    {
        if (m_hitPoints > 0)
            std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << "\n";
        else
            std::cout << m_name << " the " << getTypeString() << " is dead.\n";
    }

private:
    Type m_type{};
    std::string m_name{"???"};
    std::string m_roar{"???"};
    int m_hitPoints{};
};
namespace MonsterGenerator
{
    Monster::Type getType(int Rand)
    {
        switch (Rand)
        {
        case 1:     return Monster::Type::dragon;
        case 2:     return Monster::Type::goblin;
        case 3:     return Monster::Type::ogre;
        case 4:     return Monster::Type::orc;
        case 5:     return Monster::Type::skeleton;
        case 6:     return Monster::Type::troll;
        case 7:     return Monster::Type::vampire;
        case 8:     return Monster::Type::zombie;
        }
        return Monster::Type::dragon; // defual?
    }

    std::string getName(int Rand)
    {
        switch (Rand)
        {
        case 1:     return "Lallu sa sachin";
        case 2:     return "Bullaa";
        case 3:     return "viladamir putin";
        case 4:     return "shri shri shri narendar pogi";
        case 5:     return "nuclear Gandhi";
        }
        return "???";
    }
    std::string getRoar(int rand)
    {
        switch (rand)
        {
        case 1:     return "*vaauuuu*";
        case 2:     return "*khikhikhikhi*";
        case 3:     return "*meeaau*";
        case 4:     return "*namaskar dosto*";
        case 5:     return "*mitroo*";
        }
        return "???";
    }

    Monster generate()
    {
        return Monster{getType(Random::get(1, 8)),
                       getName(Random::get(1, 5)),
                       getRoar(Random::get(1, 5)),
                       Random::get(1, 100)};
    }

};
int main()
{
    Monster skeleton{Monster::skeleton, "Bones", "*rattle*", 4};
    skeleton.print();

    Monster vampire{Monster::vampire, "Nibblez", "*hiss*", 0};
    vampire.print();

    Monster m{MonsterGenerator::generate()};
    m.print();
    
    return 0;
}