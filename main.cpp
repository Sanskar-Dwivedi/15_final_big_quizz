#include <iostream>

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
        : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
    {
    }

    std::string getTypeString()
    {
        switch (m_type)
        {
        case dragon:    return "dragon";
        case goblin:    return "goblin";
        case ogre:      return "ogre";
        case orc:       return "orc";
        case skeleton:  return "skeleton";
        case troll:     return "troll";
        case vampire:   return "vampire";
        case zombie:    return "zombie";
        default:        return "???";
        }
    }

    void print()
    {
        if (m_hitPoints > 0)
        {
            std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << "\n";
        }
        else
        {
            std::cout << m_name << " the " << getTypeString() << " is dead.";
        }
    }

private:
    Type m_type{};
    std::string m_name{"???"};
    std::string m_roar{"???"};
    int m_hitPoints{};
};

int main()
{
    Monster skeleton{Monster::skeleton, "Bones", "*rattle*", 4};
    skeleton.print();

    Monster vampire{Monster::vampire, "Nibblez", "*hiss*", 0};
    vampire.print();
    return 0;
}