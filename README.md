# Buffer Objects
Fast serialization code generation tool for performance-critical applications.

## Usage
**1**. Define schema with Simple Schema Definition Language ([sidl](https://github.com/paidgeek/sidl)) in directory `$INPUT_DIR`. Here is an example for a made up RPG game:

```
// names are all in PascalCase
// generator will follow naming conventions for each target language
namespace Rpg

struct Position {
  X f32
  Y f32
}

@MakeBuilder
class Character {
  Name s
  Position Position
  Speed f32
  Bag .Inventory.Inventory
  // this is a map, which maps string keys to Rpg.Inventory.Item
  Equipment <s, Rpg.Inventory.Item>
  // array of 8 doubles
  Buffs [8]f64
}

namespace Rpg.Inventory

enum Quality u8 { Common = 1, Rare, Epic }

interface Item {
  Name s
  Quality Quality
  Cost u64
}

class Weapon : Item {
  Damage u64
}

class Armor : Item {
  Defense u64
}

@MakeBuilder
class Inventory {
  Capacity u
  // vector of items
  Items []Item
}
```

**2**. Generate source code with:

  ```
  bufobjects -i $INPUT_DIR -o $OUTPUT_DIR -l $TARGET_LANGUAGE [--id $ID_TYPE]
  ```

Currently supported languages are: Java (`java`) and C++11 (`cpp`). Default object id type is `u16`, valid types are: `i8`, `u8`, `i16`, `u16`, `i32`, `u32`, `i64` and `u64`.

**3**. Use in code. [Here](https://github.com/paidgeek/bufobjects/blob/master/examples/cpp/test/rpg/rpgtest.cc) is an example in C++. (Also [Java](https://github.com/paidgeek/bufobjects/blob/master/examples/java/src/test/java/RpgTest.java))

A snippet:
```cpp
auto character = Character::Builder()
  .SetName("Bobby")
  .SetPosition({-13.5f, 8.2f})
  .SetSpeed(3.0f)
  .SetBag(Inventory::Builder()
    .SetCapacity(10)
    .SetItems({
      new Weapon{10, "Sword", Quality::kCommon, 5},
      new Armor{15, "Ring of Bits", Quality::kRare, 15}
    }).Build())
  .SetEquipment("MainHand", new Weapon{50, "Knife", Quality::kCommon, 10})
  .SetEquipment("Head", new Armor{1000, "Fedora", Quality::kEpic, 42})
  .SetBuffs({32.0, 64.0})
  .Build();
bufobjects::BufferBuilder bb;
bufobjects::WriteIdentifiedTo(bb, character);

character->Clear();
bb.Rewind();

auto newCharacter = dynamic_cast<Character*>(bufobjects::ReadIdentifiedFrom(bb));
```

Some quick notes:
  * Classes:
    * If a class has a SIDL annotation `@MakeBuilder`, it will have a generated builder
    * Each field will have a getter and a setter prefixed with "Get" and "Set"
    * Classes can inherit from other classes and interfaces, interfaces can inherit from other interfaces
    * Function `Clear()` will clear object's fields
    * Functions `WriteTo(bufobjects::BufferObject&)` and `ReadFrom(bufobjects::BufferBuilder&)` are used for unidentified writing and reading
    * Static functions `WriteDirectTo` and `WriteDirectIdentifiedTo` are used for fast writing (no instance needed and buffer capacity is not checked)
    * Functions `bufobjects::WriteIdentifiedTo(BufferBuilder&, BufferObject&)`
    and `BufferObject* bufobjects::ReadIdentifiedFrom(BufferBuilder&)` are used for identified writing and reading (object's id is written aswell, so `ReadIdentifiedFrom` knows what class it's reading)
    * If a field is null, it won't be written, `::Has*` checks if it's null (structs and primitives have default values)
    * Concrete classes will have `::WriteJsonTo(std::ostream&)`, which writes json to `std::ostream`
  * Structs:
    * Structs share `Reset()`, `WriteTo(BufferBuilder&)`, `ReadFrom(BufferBuilder&)` and `WriteJsonTo(std::ostream&)` with classes
    * They can only contain scalar types (`i8`, `u8`, `i16`, `u16`, `i32`, `u32`, `i64`, `u64`, `f32`, `f64`), other structs and arrays of those types.
