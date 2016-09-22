#ifndef BUFOBJECTS_RPG_H
#define BUFOBJECTS_RPG_H

#include "bufobjects/bufobjects.h"

namespace rpg {

  class Character : public bufobjects::BufferObject {
  private:
    std::string name_;
    float speed_;
    std::array<double, 8> buffs_;
  public:
    const uint32_t kBuffsLength = 8;

    class Builder;

    Character() {
      Reset();
    }

    Character(std::string name, float speed, std::array<double, 8> buffs)
      : name_(name),
        speed_(speed),
        buffs_(buffs) {}
  };

  class Character::Builder {
  private:
    std::string name_;
    float speed_;
    std::array<double, 8> buffs_;
  public:
    Builder() {
    }
    Builder &SetName(const std::string &name) {
      name_ = name;
      return *this;
    }
    Builder &SetSpeed(const float speed) {
      speed_ = speed;
      return *this;
    }
    Builder &SetBuffs(const std::array<double, 8> &buffs) {
      buffs_ = buffs;
      return *this;
    }
    std::unique_ptr<Character> Build() {
      return std::unique_ptr<Character>{new Character{name_, speed_, buffs_}};
    }
  };

}

#endif
