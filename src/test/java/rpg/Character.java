package rpg;

// Generated with https://github.com/paidgeek/bufobjects

@SuppressWarnings("all")
public class Character
  extends BufferObject {

  protected byte[] name;
  protected float speed;
  protected rpg.inventory.Inventory bag;
  protected rpg.inventory.Item mainHand;
  protected double[] buffs;
  public static final int BUFFS_LENGTH = 8;

  public Character() {
    reset();
  }

  public Character(String name, float speed, rpg.inventory.Inventory bag, rpg.inventory.Item mainHand, double[] buffs) {
    this.name = BufferObjectBuilder.getStringBytes(name);
    this.speed = speed;
    this.bag = bag;
    this.mainHand = mainHand;
    this.buffs = buffs;
  }

  public void init(String name, float speed, rpg.inventory.Inventory bag, rpg.inventory.Item mainHand, double[] buffs) {
    this.name = BufferObjectBuilder.getStringBytes(name);
    this.speed = speed;
    this.bag = bag;
    this.mainHand = mainHand;
    this.buffs = buffs;
  }

  public short bufferObjectId() {
    return RPG_CHARACTER_ID;
  }

  public void reset() {
    this.name = new byte[0];
    this.speed = 0.0f;
    this.bag = null;
    this.mainHand = null;
    this.buffs = new double[BUFFS_LENGTH];

  }

  public Character copy() {

    Character newCopy = new Character();
    newCopy.name = new byte[this.name.length];
    System.arraycopy(this.name, 0, newCopy.name, 0, this.name.length);
    newCopy.speed = this.speed;
    if (this.bag != null) {
      newCopy.bag = (rpg.inventory.Inventory) this.bag.copy();
    }
    if (this.mainHand != null) {
      newCopy.mainHand = (rpg.inventory.Item) this.mainHand.copy();
    }
    for (int i = 0; i < BUFFS_LENGTH; i++) {
      newCopy.buffs[i] = this.buffs[i];
    }
    return newCopy;
  }

  public void copyTo(BufferObject obj) {
    Character dst = (Character) obj;

    dst.name = new byte[this.name.length];
    System.arraycopy(this.name, 0, dst.name, 0, this.name.length);
    dst.speed = this.speed;
    if (this.bag != null) {
      this.bag.copyTo(dst.bag);
    }
    if (this.mainHand != null) {
      this.mainHand.copyTo(dst.mainHand);
    }
    for (int i = 0; i < BUFFS_LENGTH; i++) {
      dst.buffs[i] = this.buffs[i];
    }
  }

  public int size() {
    int size = 0;

    size += BufferObjectBuilder.getStringSize(this.name);
    size += 4; // size for "f32"

    size += 1; // +1 for "is null" byte
    if (this.bag != null) {
      size += this.bag.size();
      // this comment seems to fix a jtwig bug "[]"

    }

    size += 1; // +1 for "is null" byte
    if (this.mainHand != null) {
      size += this.mainHand.size();
      // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.TypeDefinition@30dae81, com.moybl.sidl.ast.TypeDefinition@1b2c6ec2]"

      size += 2; // size of bufferObjectId

    }
    if (this.buffs == null) {

      this.buffs = new double[BUFFS_LENGTH];

    }
    size += BUFFS_LENGTH * 8;

    return size;
  }

  public void writeTo(BufferObjectBuilder bob) {
    int needed = size();
    if (bob.getRemaining() < needed) {
      bob.growBuffer(needed);
    }
    {
      bob.writeString(this.name);

    }
    {
      bob.writeFloat32(this.speed);

    }
    {
      if (this.bag == null) {
        bob.writeUInt8((byte) 0x80);
      } else {
        bob.writeUInt8((byte) 0x81);
        // this comment seems to fix a jtwig bug []

        this.bag.writeTo(bob);
      }

    }
    {
      if (this.mainHand == null) {
        bob.writeUInt8((byte) 0x80);
      } else {
        bob.writeUInt8((byte) 0x81);
        // this comment seems to fix a jtwig bug [com.moybl.sidl.ast.TypeDefinition@30dae81, com.moybl.sidl.ast.TypeDefinition@1b2c6ec2]

        bob.writeUInt16(this.mainHand.bufferObjectId());

        this.mainHand.writeTo(bob);
      }

    }
    {
      if (this.buffs == null) {

        this.buffs = new double[BUFFS_LENGTH];

      }
      for (int i = 0; i < BUFFS_LENGTH; i++) {
        bob.writeFloat64(this.buffs[i]);
      }
    }
  }

  public void readFrom(BufferObjectBuilder bob) {
    {
      this.name = bob.readString();

    }
    {
      this.speed = bob.readFloat32();

    }
    {
      // this comment seems to fix a jtwig bug "[]"

      if (bob.readUInt8() == (byte) 0x81) {
        if (this.bag == null) {
          this.bag = new rpg.inventory.Inventory();
        }
        this.bag.readFrom(bob);
      } else {
        this.bag = null;
      }

    }
    {
      // this comment seems to fix a jtwig bug "[com.moybl.sidl.ast.TypeDefinition@30dae81, com.moybl.sidl.ast.TypeDefinition@1b2c6ec2]"

      if (bob.readUInt8() == (byte) 0x81) {
        short id = bob.readUInt16();
        switch (id) {
          case RPG_INVENTORY_WEAPON_ID:
            this.mainHand = new rpg.inventory.Weapon();
            break;
          case RPG_INVENTORY_ARMOR_ID:
            this.mainHand = new rpg.inventory.Armor();
            break;
        }
        this.mainHand.readFrom(bob);
      } else {
        this.mainHand = null;
      }

    }
    {
      if (this.buffs == null) {

        this.buffs = new double[BUFFS_LENGTH];

      }
      for (int i = 0; i < BUFFS_LENGTH; i++) {
        this.buffs[i] = bob.readFloat64();
      }
    }
  }

  public String
  getName() {

    return BufferObjectBuilder.getStringFromBytes(this.name);

  }

  public void setName(String name) {

    this.name = BufferObjectBuilder.getStringBytes(name);

  }

  public float
  getSpeed() {

    return this.speed;

  }

  public void setSpeed(float speed) {

    this.speed = speed;

  }

  public rpg.inventory.Inventory
  getBag() {

    return this.bag;

  }

  public void setBag(rpg.inventory.Inventory bag) {

    this.bag = bag;

  }

  public rpg.inventory.Item
  getMainHand() {

    return this.mainHand;

  }

  public void setMainHand(rpg.inventory.Item mainHand) {

    this.mainHand = mainHand;

  }

  public double[]
  getBuffs() {

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

  public static void writeDirectTo(BufferObjectBuilder bob, String name, float speed, rpg.inventory.Inventory bag, rpg.inventory.Item mainHand, double[] buffs) {
    {
      bob.writeString(name);

    }
    {
      bob.writeFloat32(speed);

    }
    {
      if (bag == null) {
        bob.writeUInt8((byte) 0x80);
      } else {
        bob.writeUInt8((byte) 0x81);
        // this comment seems to fix a jtwig bug []

        bag.writeTo(bob);
      }

    }
    {
      if (mainHand == null) {
        bob.writeUInt8((byte) 0x80);
      } else {
        bob.writeUInt8((byte) 0x81);
        // this comment seems to fix a jtwig bug [com.moybl.sidl.ast.TypeDefinition@30dae81, com.moybl.sidl.ast.TypeDefinition@1b2c6ec2]

        bob.writeUInt16(mainHand.bufferObjectId());

        mainHand.writeTo(bob);
      }

    }
    {
      for (int i = 0; i < BUFFS_LENGTH; i++) {
        bob.writeFloat64(buffs[i]);
      }
    }
  }

  public static void writeDirectIdentifiedTo(BufferObjectBuilder bob, String name, float speed, rpg.inventory.Inventory bag, rpg.inventory.Item mainHand, double[] buffs) {
    bob.writeUInt16(RPG_CHARACTER_ID);
    writeDirectTo(bob, name, speed, bag, mainHand, buffs);
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
      if (buffs.length == BUFFS_LENGTH) {
        this.buffs = buffs;
      } else if (buffs.length < BUFFS_LENGTH) {
        this.buffs = new double[BUFFS_LENGTH];
        System.arraycopy(buffs, 0, this.buffs, 0, buffs.length);
      } else {
        throw new IndexOutOfBoundsException();
      }
      return this;
    }

    public Character build() {
      return new Character(
        this.name, this.speed, this.bag, this.mainHand, this.buffs);
    }

  }

}