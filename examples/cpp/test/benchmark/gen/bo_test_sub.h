// Generated with https://github.com/paidgeek/bufobjects
#ifndef GEN_BOTESTSUB_H
#define GEN_BOTESTSUB_H

#include "../buffer_object.h"

namespace gen {

  class BoTestSub
    : public bufobjects::BufferObject {

  protected:
    float x_;
    double y_;

  public:

    typedef gen::BoTestSub *Ptr;

    BoTestSub();
    BoTestSub(float x, double y);

    ~BoTestSub();

    void Init(float x, double y);
    static Ptr New(float x, double y);
    BoTestSub(const BoTestSub &from);
    BoTestSub &operator=(const BoTestSub &from);
    explicit operator bufobjects::BufferObject::Ptr() {
      return bufobjects::PointerCast<BufferObject>(this);
    }
    uint16_t BufferObjectId() const;
    void Reset();
    void CopyTo(bufobjects::BufferObject &obj) const;
    uint32_t Size() const;
    void WriteTo(bufobjects::BufferObjectBuilder &bob) const;
    void ReadFrom(bufobjects::BufferObjectBuilder &bob);
    const float &GetX() const;
    void SetX(const float &x);

    const double &GetY() const;
    void SetY(const double &y);

    static void WriteDirectTo(bufobjects::BufferObjectBuilder &bob, float x, double y);
    static void WriteDirectIdentifiedTo(bufobjects::BufferObjectBuilder &bob, float x, double y);
  };

}

#endif