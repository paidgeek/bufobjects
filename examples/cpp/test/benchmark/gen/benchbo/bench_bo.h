// Generated with https://github.com/paidgeek/bufobjects

#ifndef BUFOBJECTS_BENCHBO_H
#define BUFOBJECTS_BENCHBO_H

#include <iostream>
#include "buffer_object.h"

// forward declarations






namespace benchbo {}

namespace benchbo {}

namespace benchbo { class FooBar; }
namespace benchbo {}

namespace benchbo {

enum class Fruit : int16_t {
  kApples = 0, kPears = 1, kBananas = 2
};

}

namespace benchbo {

struct Foo {
  uint64_t id;
  int16_t count;
  int8_t prefix;
  uint32_t length;

  Foo();
  Foo(uint64_t id, int16_t count, int8_t prefix, uint32_t length);
  Foo(const Foo &from);
  void Reset();
  void WriteTo(bufobjects::BufferBuilder &bb) const;
  void ReadFrom(bufobjects::BufferBuilder &bb);
  void WriteJsonTo(std::ostream &os);
};

}

namespace benchbo {

struct Bar {
  benchbo::Foo parent;
  int32_t time;
  float ratio;
  uint16_t size;

  Bar();
  Bar(benchbo::Foo parent, int32_t time, float ratio, uint16_t size);
  Bar(const Bar &from);
  void Reset();
  void WriteTo(bufobjects::BufferBuilder &bb) const;
  void ReadFrom(bufobjects::BufferBuilder &bb);
  void WriteJsonTo(std::ostream &os);
};

}

namespace benchbo {

class FooBar
  : public bufobjects::BufferObject {

protected:
  benchbo::Bar sibling_;
  std::string name_;
  double rating_;
  uint8_t postfix_;

public:

  FooBar();
  FooBar(benchbo::Bar sibling, std::string name, double rating, uint8_t postfix);
  void Init(benchbo::Bar sibling, std::string name, double rating, uint8_t postfix);
  FooBar(const FooBar &from);
  FooBar &operator=(const FooBar &from);
  ~FooBar();
  uint16_t BufferObjectId() const override;
  void Reset() override;
  void CopyTo(bufobjects::BufferObject &obj) const override;
  uint32_t Size() const override;
  void WriteTo(bufobjects::BufferBuilder &bb) const override;
  void ReadFrom(bufobjects::BufferBuilder &bb) override;
  void WriteJsonTo(std::ostream &os);
  inline const benchbo::Bar &GetSibling() const { return sibling_; }
  inline void SetSibling(const benchbo::Bar &sibling) { sibling_ = sibling; }

  inline const std::string &GetName() const { return name_; }
  inline void SetName(const std::string &name) { name_ = name; }

  inline const double &GetRating() const { return rating_; }
  inline void SetRating(const double &rating) { rating_ = rating; }

  inline const uint8_t &GetPostfix() const { return postfix_; }
  inline void SetPostfix(const uint8_t &postfix) { postfix_ = postfix; }

  static void
  WriteDirectTo(bufobjects::BufferBuilder &bb, const benchbo::Bar &sibling, const std::string &name,
                const double &rating, const uint8_t &postfix);
  static void WriteDirectIdentifiedTo(bufobjects::BufferBuilder &bb, const benchbo::Bar &sibling,
                                      const std::string &name, const double &rating,
                                      const uint8_t &postfix);
};

}

namespace benchbo {

class FooBarContainer
  : public bufobjects::BufferObject {

protected:
  std::vector<benchbo::FooBar *> list_;
  bool initialized_;
  benchbo::Fruit fruit_;
  std::string location_;

public:

  FooBarContainer();
  FooBarContainer(std::vector<benchbo::FooBar *> list, bool initialized, benchbo::Fruit fruit,
                  std::string location);
  void Init(std::vector<benchbo::FooBar *> list, bool initialized, benchbo::Fruit fruit,
            std::string location);
  FooBarContainer(const FooBarContainer &from);
  FooBarContainer &operator=(const FooBarContainer &from);
  ~FooBarContainer();
  uint16_t BufferObjectId() const override;
  void Reset() override;
  void CopyTo(bufobjects::BufferObject &obj) const override;
  uint32_t Size() const override;
  void WriteTo(bufobjects::BufferBuilder &bb) const override;
  void ReadFrom(bufobjects::BufferBuilder &bb) override;
  void WriteJsonTo(std::ostream &os);
  inline const std::vector<benchbo::FooBar *> &GetList() const { return list_; }
  inline void SetList(const std::vector<benchbo::FooBar *> &list) { list_ = list; }

  inline benchbo::FooBar *GetList(int index) { return list_[index]; }
  inline void SetList(int index, benchbo::FooBar *value) { list_[index] = value; }

  inline const bool &GetInitialized() const { return initialized_; }
  inline void SetInitialized(const bool &initialized) { initialized_ = initialized; }

  inline benchbo::Fruit GetFruit() { return fruit_; }
  inline void SetFruit(benchbo::Fruit fruit) { fruit_ = fruit; }

  inline const std::string &GetLocation() const { return location_; }
  inline void SetLocation(const std::string &location) { location_ = location; }

  static void
  WriteDirectTo(bufobjects::BufferBuilder &bb, const std::vector<benchbo::FooBar *> &list,
                const bool &initialized, const benchbo::Fruit &fruit, const std::string &location);
  static void
  WriteDirectIdentifiedTo(bufobjects::BufferBuilder &bb, const std::vector<benchbo::FooBar *> &list,
                          const bool &initialized, const benchbo::Fruit &fruit,
                          const std::string &location);
};

}

#endif