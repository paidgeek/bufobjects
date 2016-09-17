package rpg;

// Generated with https://github.com/paidgeek/bufobjects

public interface RPGService {

  rpg.Character GetCharacterByName(String name);
  rpg.inventory.Item GetItemByName(String name);

}