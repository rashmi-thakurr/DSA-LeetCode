class Solution {
public:
    bool atOrigin(int v, int h){
        if(v==0 and h==0)
            return true;
        
        return false;
    }
    bool isRobotBounded(string instructions) {
        
        char currentDirection = 'N';
        int vertical = 0;
        int horizontal = 0;
        
        for(int i=0;i<instructions.length();i++){
            if(instructions[i]=='G'){
                vertical += currentDirection == 'N' ? 1 : 0;
                vertical += currentDirection == 'S' ? -1 : 0;
                horizontal += currentDirection == 'E' ? 1 : 0;
                horizontal += currentDirection == 'W' ? -1 : 0;
            }
            else{
                if(currentDirection == 'N'){
                    currentDirection = instructions[i] == 'L' ? 'W' : 'E';
                }
                else if(currentDirection == 'S'){
                    currentDirection = instructions[i] == 'L' ? 'E' : 'W';
                }
                else if(currentDirection == 'E'){
                    currentDirection = instructions[i] == 'L' ? 'N' : 'S';
                }
                else{
                    currentDirection = instructions[i] == 'L' ? 'S' : 'N';
                }
            }
        }
        
        if( atOrigin(vertical,horizontal) || currentDirection!='N')
            return true;
        
        return false;
    }
};