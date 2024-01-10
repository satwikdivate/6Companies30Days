  bool palindrome(int x, string& s) {
        int l = 0, r = s.size()-1;
        while( l < r ) {
            if( ((1 << l) & x) == 0 ) 
                l++;

            if( ((1 << r) & x) == 0 )
                r--;

            if( l < r && ((1 << l) & x) != 0 && ((1 << r) & x) != 0 ) {
                if( s[l] != s[r] )
                    return false;

                l++;
                r--;
            }

        }

        return true;
    }

public:
    int maxProduct(string s) {
        int ans = 1;
        for( int a = 1 ; a < (1 << s.size()) ; a++ ) {
            if( !palindrome(a, s) )
                continue; // check a is palindrome

            // int bit = s.size() - popcount(a);
            for( int b = 1 ; b < (1 << s.size()) ; b++ ) {
                if( (a & b) != 0 || !palindrome(b, s) ) 
                    continue; // not disjoint, not palindrome
                
                ans = max(ans, __builtin_popcount(a) * __builtin_popcount(b));
            }
        }

        return ans;
    }