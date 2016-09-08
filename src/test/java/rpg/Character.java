package rpg;

public class Character {

  private String name;
  private float speed;
  private rpg.inventory.Inventory bag;
  private rpg.inventory.Item mainHand;
  private double[] buffs;
  public static final int BUFFS_LENGTH = 8;

  public Character() {
    reset();
  }

  public Character(String name, float speed, rpg.inventory.Inventory bag, rpg.inventory.Item mainHand, double[] buffs) {
    this.name = name;
    this.speed = speed;
    this.bag = bag;
    this.mainHand = mainHand;
    this.buffs = buffs;
  }

  public void reset() {
    this.name = "";
    this.speed = 0.0f;
    this.bag = null;
    this.mainHand = null;
    this.buffs = new double[BUFFS_LENGTH];
  }

  public Character copy() {
    Character newCopy = new Character();
    newCopy.name = this.name;
    newCopy.speed = this.speed;
    if (this.bag != null) {
      newCopy.bag = this.bag.copy();
    }
    if (this.mainHand != null) {
      newCopy.mainHand = this.mainHand.copy();
    }
    for (int i = 0; i < BUFFS_LENGTH; i++) {
      newCopy.buffs[i] = this.buffs[i];
    }
    return newCopy;
  }

  public String getName() {
    return this.name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public float getSpeed() {
    return this.speed;
  }

  public void setSpeed(float speed) {
    this.speed = speed;
  }

  public rpg.inventory.Inventory getBag() {
    return this.bag;
  }

  public void setBag(rpg.inventory.Inventory bag) {
    this.bag = bag;
  }

  public rpg.inventory.Item getMainHand() {
    return this.mainHand;
  }

  public void setMainHand(rpg.inventory.Item mainHand) {
    this.mainHand = mainHand;
  }

  public double[] getBuffs() {
    return this.buffs;
  }

  public void setBuffs(double[] buffs) {
    this.buffs = buffs;
  }

  public double getBuffsAt(int index) {
    return this.buffs[index];
  }

  public void setBuffsAt(int index, double value) {
    this.buffs[index] = value;
  }

  public static Builder newBuilder() {
    return new Builder();
  }

  public static class Builder {

    private String name;
    private float speed;
    private rpg.inventory.Inventory bag;
    private rpg.inventory.Item mainHand;
    private double[] buffs;

    public Builder setName(String name) {
      this.name = name;
      return this;
    }

    public Builder setSpeed(float speed) {
      this.speed = speed;
      return this;
    }

    public Builder setBag(rpg.inventory.Inventory bag) {
      this.bag = bag;
      return this;
    }

    public Builder setMainHand(rpg.inventory.Item mainHand) {
      this.mainHand = mainHand;
      return this;
    }

    public Builder setBuffs(double... buffs) {
      this.buffs = buffs;
      return this;
    }

    public Character build() {
      return new Character(this.name, this.speed, this.bag, this.mainHand, this.buffs);
    }
  }
}
