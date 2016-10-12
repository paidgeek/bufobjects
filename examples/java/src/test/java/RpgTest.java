import org.junit.Assert;
import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.text.DecimalFormat;

import rpg.*;
import rpg.Character;
import rpg.inventory.*;

public class RpgTest {

  @Test
  public void testCharacterWriteRead() {
    Character character = newCharacter();
    BufferBuilder bb = new BufferBuilder();

    BufferObject.writeIdentifiedTo(bb, character);
    character.clear();
    bb.rewind();

    character = (Character) BufferObject.readIdentifiedFrom(bb);
    assertCharacter(character);
  }

  @Test
  public void testCharacterJson() throws IOException {
    Character character = newCharacter();
    ByteArrayOutputStream out = new ByteArrayOutputStream();
    character.writeJsonTo(out);

    Assert
      .assertEquals("{\"name\":\"Bobby\",\"position\":{\"x\":-1,\"y\":1},\"speed\":3,\"bag\":{\"capacity\":10,\"items\":[{\"_id\":2,\"damage\":\"10\",\"name\":\"A\",\"quality\":1,\"cost\":\"5\"},{\"_id\":3,\"defense\":\"15\",\"name\":\"B\",\"quality\":2,\"cost\":\"15\"}]},\"equipment\":{\"Head\":{\"_id\":3,\"defense\":\"100\",\"name\":\"Fedora\",\"quality\":3,\"cost\":\"42\"},\"MainHand\":{\"_id\":2,\"damage\":\"50\",\"name\":\"Knife\",\"quality\":1,\"cost\":\"10\"}},\"buffs\":[32,64,0,0,0,0,0,0]}", out
        .toString());
  }

  private Character newCharacter() {
    return Character.newBuilder()
      .setName("Bobby")
      .setPosition(new Position(-1, 1))
      .setSpeed(3.0f)
      .setBag(Inventory.newBuilder()
        .setCapacity(10)
        .setItems(new Weapon(10, "A", Quality.COMMON, 5), new Armor(15, "B", Quality.RARE, 15))
        .build())
      .setEquipment("MainHand", new Weapon(50, "Knife", Quality.COMMON, 10))
      .setEquipment("Head", new Armor(100, "Fedora", Quality.EPIC, 42))
      .setBuffs(32.0, 64.0)
      .build();
  }

  private void assertCharacter(Character character) {
    Assert.assertEquals("Bobby", character.getName());
    Assert.assertEquals(3.0f, character.getSpeed(), 0.01f);
    Assert.assertEquals(32.0, character.getBuffs(0), 0.01);
    Assert.assertEquals(64.0, character.getBuffs(1), 0.01);
    Assert.assertEquals(-1, character.getPosition().x, 0.01f);
    Assert.assertEquals(1, character.getPosition().y, 0.01f);

    Assert.assertTrue(character.hasBag());
    Weapon weapon = (Weapon) character.getBag().getItems(0);
    Assert.assertEquals("A", weapon.getName());
    Assert.assertEquals(5, weapon.getCost());
    Assert.assertEquals(Quality.COMMON, weapon.getQuality());
    Assert.assertEquals(10, weapon.getDamage());
    Armor armor = (Armor) character.getBag().getItems(1);
    Assert.assertEquals("B", armor.getName());
    Assert.assertEquals(15, armor.getCost());
    Assert.assertEquals(Quality.RARE, armor.getQuality());
    Assert.assertEquals(15, armor.getDefense());

    weapon = (Weapon) character.getEquipment("MainHand");
    Assert.assertEquals("Knife", weapon.getName());
    Assert.assertEquals(10, weapon.getCost());
    Assert.assertEquals(Quality.COMMON, weapon.getQuality());
    Assert.assertEquals(50, weapon.getDamage());
    armor = (Armor) character.getEquipment("Head");
    Assert.assertEquals("Fedora", armor.getName());
    Assert.assertEquals(42, armor.getCost());
    Assert.assertEquals(Quality.EPIC, armor.getQuality());
    Assert.assertEquals(100, armor.getDefense());
  }

}
