

  
    
      
    
  

  
    
      
    
  

  


  package rpg.inventory;


// Generated with https://github.com/paidgeek/bufobjects

public final class Quality {

public static final byte COMMON = 1;public static final byte RARE = 2;public static final byte EPIC = 3;

  private Quality() {}

  public static String getName(byte value) {
    switch(value) {
case 1:
        return "COMMON";case 2:
        return "RARE";case 3:
        return "EPIC";
      default:
        return null;
    }
  }

}
