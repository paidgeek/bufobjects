package rpg;

// Generated with https://github.com/paidgeek/bufobjects

public interface RPGService{

  rpg.Character getCharacterByName(String name);
  rpg.inventory.Item getItemByName(String name);

}