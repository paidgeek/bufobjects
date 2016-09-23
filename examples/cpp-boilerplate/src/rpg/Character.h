// Generated with https://github.com/paidgeek/bufobjects
    #ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H

#include "../buffer_object.h"


  
      namespace rpg {
  

  



class Character
: public bufobjects::BufferObject{

protected:
std::string name_;
float speed_;
std::array<double, 8> buffs_;


public:

    static const uint32_t kBuffsLength = 8;
  

Character();
Character(std::string name,float speed,std::array<double, 8> buffs);
Character(const Character& from);
inline Character& operator=(const Character& from);
uint16_t BufferObjectId() const override;
void Reset() override;
void CopyTo(bufobjects::BufferObject& obj) const override;
uint32_t Size() const override;
void WriteTo(bufobjects::BufferObjectBuilder& bob) const override;
void ReadFrom(bufobjects::BufferObjectBuilder& bob) override;const std::string& GetName() const;
  void SetName(std::string name);
  const float& GetSpeed() const;
  void SetSpeed(float speed);
  const std::array<double, 8>& GetBuffs() const;
  void SetBuffs(std::array<double, 8> buffs);
  
    const double& GetBuffsAt(int index) const;
    void SetBuffsAt(int index, double value);
  
};


  
    }
  

  


#endif