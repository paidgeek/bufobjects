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

    Character() : BufferObject() {}

    Character(std::string name, float speed, std::array<double, 8> buffs)
      : name_(name),
        speed_(speed),
        buffs_(buffs) {}

    virtual std::unique_ptr<bufobjects::BufferObject> New() const override {
      return std::unique_ptr<bufobjects::BufferObject>{new Character{}};
    }

    virtual uint16_t BufferObjectId() const override {
      return 0;
    }

    virtual uint32_t Size() const override {
      return bufobjects::BufferObject::Size();
    }

    virtual void
    WriteTo(const std::unique_ptr<bufobjects::BufferObjectBuilder> &bob) const override {
    }

    virtual void ReadFrom(const std::unique_ptr<bufobjects::BufferObjectBuilder> &bob) override {
    }

    virtual void Reset() override {
      name_ = "";
      speed_ = 0.0f;
      std::fill(buffs_.begin(), buffs_.end(), 0.0);
    }

    void CopyFrom(bufobjects::BufferObject& from) {
      CopyFrom(static_cast<Character &>(from));
    }

    void CopyFrom(Character& from) {
      name_ = from.name_;
      speed_ = from.speed_;
      buffs_ = from.buffs_;
    }

    std::string GetName() { return name_; }
    float GetSpeed() { return speed_; }
    std::array<double, 8> GetBuffs() { return buffs_; };

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
