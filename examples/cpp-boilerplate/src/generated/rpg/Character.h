// Generated with https://github.com/paidgeek/bufobjects
#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H

#include "buffer_object.h"

namespace rpg {

  class Character
    : public bufobjects::BufferObject {

  protected:
    std::string name_;
    float speed_;
    std::array<double, 8> buffs_;

  public:

    static const uint32_t kBuffsLength = 8;

    Character() {
      Reset();
    }

    Character(std::string name, float speed, std::array<double, 8> buffs)
      : name_(name), speed_(speed), buffs_(buffs), {}

    uint16_t BufferObjectId() {
      return bufobjects::kRPGCharacterId;
    }

    void Reset() {
      name_ = std::string{};
      speed_ = 0.0f;
      buffs_ = std::array<double,>{};

    }

    Character Copy() {

      Character newCopy = new Character();
      newCopy.name = new byte[this.name.length];
      System.arraycopy(this.name, 0, newCopy.name, 0, this.name.length);
      newCopy.speed = this.speed;
      for (int i = 0; i < BUFFS_LENGTH; i++) { newCopy.buffs[i] = this.buffs[i]; }
      return newCopy;
    }

    void CopyTo(BufferObject obj) {
      Character dst = (Character) obj;

      dst.name = new byte[this.name.length];
      System.arraycopy(this.name, 0, dst.name, 0, this.name.length);
      dst.speed = this.speed;
      for (int i = 0; i < BUFFS_LENGTH; i++) { dst.buffs[i] = this.buffs[i]; }
    }

    int Size() {
      int size = 0;

      size += BufferObjectBuilder.getStringSize(this.name);
      size += 4; // size for "f32"
      if (this.buffs == null) {

        this.buffs = new double[BUFFS_LENGTH];

      }
      size += BUFFS_LENGTH * 8;

      return size;
    }

    void WriteTo(BufferObjectBuilder bob) {
      int needed = size();
      if (bob.getRemaining() < needed) {
        bob.growBuffer(needed);
      }
      {
        bob.writeString(this.name);

      }
      {
        bob.writeFloat32(this.speed);

      }
      {
        if (this.buffs == null) {

          this.buffs = new double[BUFFS_LENGTH];

        }
        for (int i = 0; i < BUFFS_LENGTH; i++) {
          bob.writeFloat64(this.buffs[i]);
        }
      }
    }

    void ReadFrom(BufferObjectBuilder bob) {
      {
        this.name = bob.readString();

      }
      {
        this.speed = bob.readFloat32();

      }
      {
        if (this.buffs == null) {

          this.buffs = new double[BUFFS_LENGTH];

        }
        for (int i = 0; i < BUFFS_LENGTH; i++) {
          this.buffs[i] = bob.readFloat64();
        }
      }
    }

    std::string
    GetName() {

      return BufferObjectBuilder.getStringFromBytes(this.name);

    }

    void SetName(std::string name) {

      this.name = name;

    }

    float
    GetSpeed() {

      return this.speed;

    }

    void SetSpeed(float speed) {

      this.speed = speed;

    }

    std::array<double, 8>
    GetBuffs() {

      return this.buffs;

    }

    void SetBuffs(std::array<double, 8> buffs) {

      this.buffs = buffs;

    }

    double getBuffsAt(int index) {

      return this.buffs[index];

    }

    void SetBuffsAt(int index, double value) {

      this.buffs[index] = value;

    }

  }