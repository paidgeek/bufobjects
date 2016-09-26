# Buffer Objects
Serialization library for performance-critical applications.

# Usage
1. Define schema with Simple Schema Definition Language ([sidl](https://github.com/paidgeek/sidl)) in directory `$INPUT_DIR`.
2. Generate source code with:
  ```
  bufobjects -i $INPUT_DIR -o $OUTPUT_DIR -l $TARGET_LANGUAGE
  ```
  Currently supported languages are: Java and C++11.
3. Use in code. See an example [schema](https://github.com/paidgeek/bufobjects/tree/master/src/test/resources/rpg), [generated code](https://github.com/paidgeek/bufobjects/tree/master/src/test/java/rpg) and [example usage](https://github.com/paidgeek/bufobjects/blob/master/src/test/java/RPGTest.java).
