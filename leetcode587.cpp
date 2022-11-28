// TLE

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& arr) {
        
        int n=arr.size();
        
        vector<int>first,second;
        
        for(auto i: arr){
            
            first.push_back(i[0]);
            second.push_back(i[1]);
        }
        
        
        set<int>st;
        
        for(int i: first){
            st.insert(i);
        }
        
        first.clear();
        
        for(auto i: st){
            
            first.push_back(i);
        }
        
        for(int i: first){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i: second){
            cout<<i<<" ";
        }cout<<endl;
        
        vector<vector<int>>res;
        
        sort(second.begin(),second.end());
        
        
        vector<int>temp;
        
        for(int i=0;i<first.size();i++){
            
            
            int st=0;
            int end=second.size()-1;
            
            bool check=false;
            
            while(st<=end){

            
            int mid=st+(end-st)/2;
            
            if(second[mid]==first[i]){
                check=true;
                break;
            }
            else if(second[mid]<first[i]) st=mid+1;
            else end=mid-1;
                
            }
            
            if(check==false){
                temp.push_back(first[i]);
            }
        }
        
        
        res.push_back(temp);
        
        
       map<int,int>mp;
        
        vector<int>t;
        
        sort(t.begin(),t.end());
        
        for(int i: second){
            mp[i]++;
        }
        
        for(auto i: mp){
            
            if(i.second==1){
                t.push_back(i.first);
            }
        }
        
        
        res.push_back(t);

        
        return res;
        
    }
};




// optimized--->>Acceptable

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& arr) {
        
        vector<vector<int>>res;
        vector<int>f,s;
        
        set<int>st1,st2;
        
        for(vector<int>v: arr){
            
            st1.insert(v[0]);
            st2.insert(v[1]);
        }
        
        
        for(auto i: st1){
            f.push_back(i);
        }
        
        for(auto i: st2){
            s.push_back(i);
        }
        
        sort(s.begin(),s.end());
        
        
        vector<int>t;
        
        for(int i: f){
            
            
            int st=0;
            int end=s.size()-1;
            
            bool check=true;
            
            while(st<=end){
                
                int mid=st+(end-st)/2;
                
                if(s[mid]==i){
                    check=false;
                    break;
                }
                else if(s[mid]<i){
                    st=mid+1;
                }else {
                    end=mid-1;
                }
            }
            
            if(check){
                t.push_back(i);
            }
        }
        
        res.push_back(t);
        
        vector<int>v;
        
        for(auto i: arr){
            v.push_back(i[1]);
        }
        
        unordered_map<int,int>mp;
        
        for(int i: v){
            mp[i]++;
        }
        
        vector<int>tt;
        
        for(auto i: mp){
            
            if(i.second==1){
                tt.push_back(i.first);
            }
        }
        
        sort(tt.begin(),tt.end());
        
        res.push_back(tt);
        
        return res;
    }
};

