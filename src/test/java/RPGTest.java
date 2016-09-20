import org.junit.Assert;
import org.junit.Test;

import rpg.*;
import rpg.Character;
import rpg.inventory.*;

public class RPGTest {

  @Test
  public void testItemClass() {
    Weapon weapon = Weapon.newBuilder()
      .setName("Knife")
      .setCost(42)
      .setQuality(Quality.EPIC)
      .setDamage(10)
      .build();
    Assert.assertEquals("Knife", weapon.getName());
    Assert.assertEquals(42, weapon.getCost());
    Assert.assertEquals(Quality.EPIC, weapon.getQuality());
    Assert.assertEquals(10, weapon.getDamage());

    Weapon copy = (Weapon) weapon.copy();
    Assert.assertEquals("Knife", copy.getName());
    Assert.assertEquals(42, copy.getCost());
    Assert.assertEquals(Quality.EPIC, copy.getQuality());
    Assert.assertEquals(10, copy.getDamage());

    weapon.reset();
    Assert.assertEquals("", weapon.getName());
    Assert.assertEquals(0, weapon.getQuality());
    Assert.assertEquals(0, weapon.getCost());
    Assert.assertEquals(0, weapon.getDamage());
  }

  @Test
  public void testInventoryClass() {
    Inventory i = Inventory.newBuilder()
      .setCapacity(10)
      .setItems(
        Weapon.newBuilder()
          .setName("A")
          .setCost(5)
          .setQuality(Quality.COMMON)
          .setDamage(10)
          .build(),
        Armor.newBuilder()
          .setName("B")
          .setCost(15)
          .setQuality(Quality.RARE)
          .setDefense(10)
          .build())
      .build();

    Assert.assertEquals(10, i.getCapacity());

    Assert.assertEquals("A", i.getItemsAt(0).getName());
    Assert.assertEquals(5, i.getItemsAt(0).getCost());
    Assert.assertEquals(Quality.COMMON, i.getItemsAt(0).getQuality());
    Assert.assertEquals(10, ((Weapon) i.getItemsAt(0)).getDamage());

    Assert.assertEquals("B", i.getItemsAt(1).getName());
    Assert.assertEquals(15, i.getItemsAt(1).getCost());
    Assert.assertEquals(Quality.RARE, i.getItemsAt(1).getQuality());
    Assert.assertEquals(10, ((Armor) i.getItemsAt(1)).getDefense());
  }

  @Test
  public void writeAndReadCharacter() {
    Character character = Character.newBuilder()
      .setName("Bobby")
      .setBuffs(32.0, 64.0)
      .setSpeed(3.0f)
      .setBag(Inventory.newBuilder()
        .setCapacity(10)
        .setItems(
          Weapon.newBuilder()
            .setName("A")
            .setCost(5)
            .setQuality(Quality.COMMON)
            .setDamage(10)
            .build(),
          Armor.newBuilder()
            .setName("B")
            .setCost(15)
            .setQuality(Quality.RARE)
            .setDefense(10)
            .build())
        .build())
      .build();

    BufferObjectBuilder bob = new BufferObjectBuilder(100000, 100000);
    BufferObjects.writeTo(bob, character);
    character.reset();
    bob.rewind();
    character = (Character) BufferObjects.readFrom(bob);

    Assert.assertEquals("Bobby", character.getName());
    Assert.assertEquals(32.0, character.getBuffsAt(0), 0.1);
    Assert.assertEquals(64.0, character.getBuffsAt(1), 0.1);
    Assert.assertEquals(3.0f, character.getSpeed(), 0.1f);
    Assert.assertNull(character.getMainHand());

    Inventory i = character.getBag();
    Assert.assertEquals(10, i.getCapacity());
    Assert.assertEquals("A", i.getItemsAt(0).getName());
    Assert.assertEquals(5, i.getItemsAt(0).getCost());
    Assert.assertEquals(Quality.COMMON, i.getItemsAt(0).getQuality());
    Assert.assertEquals(10, ((Weapon) i.getItemsAt(0)).getDamage());
    Assert.assertEquals("B", i.getItemsAt(1).getName());
    Assert.assertEquals(15, i.getItemsAt(1).getCost());
    Assert.assertEquals(Quality.RARE, i.getItemsAt(1).getQuality());
    Assert.assertEquals(10, ((Armor) i.getItemsAt(1)).getDefense());
  }

}
