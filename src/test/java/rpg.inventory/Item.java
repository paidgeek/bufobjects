package rpg.inventory;

public class Item {

  private String name;
  private byte quality;
  private long cost;

  public Item() {
    reset();
  }

  public Item(String name, byte quality, long cost) {
    this.name = name;
    this.quality = quality;
    this.cost = cost;
  }

  public void reset() {
    this.name = "";
    this.quality = 0;
    this.cost = 0;
  }

  public Item copy() {
    Item newCopy = new Item();
    newCopy.name = this.name;
    newCopy.quality = this.quality;
    newCopy.cost = this.cost;
    return newCopy;
  }

  public String getName() {
    return this.name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public byte getQuality() {
    return this.quality;
  }

  public void setQuality(byte quality) {
    this.quality = quality;
  }

  public long getCost() {
    return this.cost;
  }

  public void setCost(long cost) {
    this.cost = cost;
  }

  public static Builder newBuilder() {
    return new Builder();
  }

  public static class Builder {

    private String name;
    private byte quality;
    private long cost;

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

    public Item build() {
      return new Item(this.name, this.quality, this.cost);
    }
  }
}
