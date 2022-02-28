class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int idx = 0;
        int len = s.size();
        while(idx<len){
            char ch = s[idx];
            switch(ch){
                case 'I':
                    if(idx<len-1){
                        if(s[idx+1]=='V'){
                            sum+=4; idx+=2; break;
                        }
                        if(s[idx+1]=='X'){
                            sum+=9; idx+=2; break;
                        }
                    }else{
                        if(idx<len-2&&s[idx+1]=='I'&&s[idx+2]=='I'){
                            sum+=3;
                            idx+=3;
                            break;
                        }
                        if(idx<len-1&&s[idx+1]=='I'){
                            sum+=2;
                            idx+=2;
                            break;
                        }
                    }

                    sum+=1;
                    idx++;
                    break;
                case 'X':
                    if(idx<len-1){
                        if(s[idx+1]=='L'){
                            sum+=40; idx+=2; break;
                        }
                        if(s[idx+1]=='C'){
                            sum+=90; idx+=2; break;
                        }
                    }
                    sum+=10;
                    idx++;
                    break;
                case 'C':
                    if(idx<len-1){
                        if(s[idx+1]=='D'){
                            sum+=400; idx+=2; break;
                        }
                        if(s[idx+1]=='M'){
                            sum+=900; idx+=2; break;
                        }
                    }
                    sum+=100;
                    idx++;
                    break;
                case 'V':
                    sum+=5; idx++;
                    break;
                case 'L':
                    sum+=50; idx++;
                    break;
                case 'D':
                    sum+=500; idx++;
                    break;
                case 'M':
                    sum+=1000; idx++;
                    break;
            }
        }
        return sum;
    }
};