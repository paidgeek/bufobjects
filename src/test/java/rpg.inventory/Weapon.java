package rpg.inventory;

// Generated with https://github.com/paidgeek/bufobjects

public class Weapon
  extends rpg.inventory.Item {

  protected long damage;

  public Weapon() {
    reset();
  }

  public Weapon(long damage, String name, byte quality, long cost) {
    this.damage = damage;
    this.name = name;
    this.quality = quality;
    this.cost = cost;
  }

  public int getBufferObjectId() {
    return 2;
  }

  public void reset() {
    super.reset();
    this.damage = 0;

  }

  public Weapon copy() {
    Weapon newCopy = new Weapon();

    newCopy.damage = this.damage;
    newCopy.name = this.name;
    newCopy.quality = this.quality;
    newCopy.cost = this.cost;
    return newCopy;

  }

  public long
  getDamage() {
    return this.damage;
  }

  public void setDamage(long damage) {
    this.damage = damage;
  }

  public int writeTo(byte[] b, int off) {
    {
      b[off++] = (byte) this.damage;
      b[off++] = (byte) (this.damage >> 8);
      b[off++] = (byte) (this.damage >> 16);
      b[off++] = (byte) (this.damage >> 24);
      b[off++] = (byte) (this.damage >> 32);
      b[off++] = (byte) (this.damage >> 40);
      b[off++] = (byte) (this.damage >> 48);
      b[off++] = (byte) (this.damage >> 56);

    }
    return off;
  }

  public int readFrom(byte[] b, int off) {
    {
      this.damage =
        (((long) b[off++] & 0xFF) |
          (((long) b[off++] & 0xFF) << 8) |
          (((long) b[off++] & 0xFF) << 16) |
          (((long) b[off++] & 0xFF) << 24) |
          (((long) b[off++] & 0xFF) << 32) |
          (((long) b[off++] & 0xFF) << 40) |
          (((long) b[off++] & 0xFF) << 48) |
          (((long) b[off++] & 0xFF) << 56));

    }
    return off;
  }

  public static Builder newBuilder() {
    return new Builder();
  }

  public static class Builder {

    private long damage;
    private String name;
    private byte quality;
    private long cost;

    public Builder setDamage(long damage) {
      this.damage = damage;
      return this;
    }

    public Builder setName(String name) {
      this.name = name;
      return this;
    }

    public Builder setQuality(byte quality) {
      this.quality = quality;
      return this;
    }

    public Builder setCost(long cost) {
      this.cost = cost;
      return this;
    }

    public Weapon build() {
      return new Weapon(
        this.damage, this.name, this.quality, this.cost);
    }

  }

}