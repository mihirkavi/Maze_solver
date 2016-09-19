#include <Arduino.h>

class DetectNode
{
  public:
      bool isOnNode(int s[]){
    
      if(s[0]==0 && s[1]==0 && s[2]==0 && s[3]==0 && s[4]==1 && s[5]==1) //this is left 'T' turn
      {
        return true;
      }
      
      else if(s[0]==1 && s[1]==1 && s[2]==0 && s[3]==0 && s[4]==0 && s[5]==0) //this is a right 'T' turn
      {
        return true;
      }
      
      else if(s[0]==1 && s[1]==1 && s[2]==1 && s[3]==1 && s[4]==1 && s[5]==1)//this is a 'U' turn
      {
        return true;
      }
      
      else
      return false;
    }

};

