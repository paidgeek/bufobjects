package rpg;

// Generated with https://github.com/paidgeek/bufobjects

public interface RPGService{

  rpg.Character getCharacterByName(byte[] name);
  rpg.inventory.Item getItemByName(byte[] name);

}