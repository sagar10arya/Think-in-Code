class Solution {
public:
    // TC: O(N) : each asteroid is pushed and popped at most once
    // SC: O(N) : stack may store all asteroids in worst case
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;     // using vector as stack
        int n = asteroids.size();

        for(int i=0; i<n; i++)
        {   
            // Case1: asteroid moving right -> can't collide with previous one
            if(asteroids[i] > 0) st.push_back(asteroids[i]);
            else{
                // current asteroid is moving left and 
                // may collide with previous right moving asteroids

                // keep destroying smaller right moving asteroids
                while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i]))
                {
                    st.pop_back();  // previous asteroid explodes
                }
                // if equal size → both explode
                if(!st.empty() && st.back() == abs(asteroids[i])) st.pop_back();
                // if stack empty OR top is negative
                // means no collision possible → push current asteroid
                else if(st.empty() || st.back() < 0){
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};