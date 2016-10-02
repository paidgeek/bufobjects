# Buffer Objects
Fast serialization library for performance-critical applications.

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
  bufobjects -i $INPUT_DIR -o $OUTPUT_DIR -l $TARGET_LANGUAGE
  ```

Currently supported languages are: Java (`java`) and C++11 (`cpp`).

**3**. Use in code. [Here](https://github.com/paidgeek/bufobjects/blob/master/examples/cpp/test/rpg/rpgtest.cc) is an example in C++. (Also [Java](https://github.com/paidgeek/bufobjects/blob/master/examples/java/src/test/java/RpgTest.java))

Some quick notes:
  * Classes:
    * If a class has a SIDL annotation `@MakeBuilder`, it will have a generated builder
    * Each field will have a getter and a setter prefixed with "Get" and "Set"
    * Classes can inherit from other classes and interfaces, interfaces can inherit from other interfaces
    * Function `Reset()` will reset object's fields
    * Functions `WriteTo(bufobjects::BufferObject&)` and `ReadFrom(bufobjects::BufferBuilder&)` are used for unidentified writing and reading
    * Static functions `WriteDirectTo` and `WriteDirectIdentifiedTo` are used for fast writing (no instance needed and buffer capacity is not checked)
    * Functions `bufobjects::WriteIdentifiedTo(BufferBuilder&, BufferObject&)`
    and `BufferObject* bufobjects::ReadIdentifiedFrom(BufferBuilder&)` are used for identified writing and reading (object's id is written aswell, so `ReadIdentifiedFrom` knows what class it's reading)
    * If a field is null, it won't be written, `::Has*` checks if it's null (structs and primitives have default values)
    * Concrete classes will have `::WriteJsonTo(std::ostream&)`, which writes json to `std::ostream`
  * Structs:
    * Structs share `Reset()`, `WriteTo(BufferBuilder&)`, `ReadFrom(BufferBuilder&)` and `WriteJsonTo(std::ostream&)` with classes
    * They can only contain scalar types (`i8`, `u8`, `i16`, `u16`, `i32`, `u32`, `i64`, `u64`, `f32`, `f64`), other structs and arrays of those types.

## Benchmark
Benchmark vs. [FlatBuffers](https://github.com/google/flatbuffers) with [this](https://github.com/paidgeek/bufobjects/blob/master/examples/cpp/test/benchmark/bm.cc) source code. 500k iterations.

|                           | Buffer Objects | Flat Buffers |
| ------------------------- |:--------------:|:------------:|
| Encode & decode time (ms) | 56.34          | 69.78        |
| Encoded size (bytes)      | 211            | 352          |

