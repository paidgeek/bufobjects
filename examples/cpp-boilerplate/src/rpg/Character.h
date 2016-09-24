// Generated with https://github.com/paidgeek/bufobjects
#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H

#include "../buffer_object.h"

namespace rpg { namespace inventory { class Item; }}

namespace rpg {

  class Character
    : public bufobjects::BufferObject {

  protected:
    std::string name_;
    float speed_;
    rpg::inventory::Item &main_hand_;
    std::array<double, 8> buffs_;

  public:

    static const uint32_t kBuffsLength = 8;

    Character();
    Character(std::string name, float speed, rpg::inventory::Item &main_hand,
              std::array<double, 8> buffs);
    void Init(std::string name, float speed, rpg::inventory::Item &main_hand,
              std::array<double, 8> buffs);
    Character(const Character &from);
    Character &operator=(const Character &from);
    uint16_t BufferObjectId() const;
    void Reset();
    void CopyTo(bufobjects::BufferObject &obj) const;
    uint32_t Size() const;
    void WriteTo(bufobjects::BufferObjectBuilder &bob) const;
    void ReadFrom(bufobjects::BufferObjectBuilder &bob);
    const std::string &GetName() const;
    void SetName(const std::string &name);
    const float &GetSpeed() const;
    void SetSpeed(const float &speed);
    const rpg::inventory::Item &GetMainHand() const;
    void SetMainHand(const rpg::inventory::Item &main_hand);
    const std::array<double, 8> &GetBuffs() const;
    void SetBuffs(const std::array<double, 8> &buffs);

    const double &GetBuffsAt(int index) const;
    void SetBuffsAt(int index, const double &value);

  };

}

#endif