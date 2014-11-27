#include<everything>
#include<string>
using namespace std;
class Solution {
public:
    string minWindow(const string& s, const string& t) 
    {
		const int ASCII_MAX = 128;
		int keys[ASCII_MAX] = {0};
		int window[ASCII_MAX] = {0};
        for(char c:t)
        {
            ++keys[c];
        }
		int match=0;
		auto min_ia = s.begin()-1;
		auto min_ib = s.end();
        auto ia = s.begin();
        for(auto ib = s.begin(); ib!=s.end(); ++ib)
        {
			if(++window[*ib]<=keys[*ib])
				++match;
			if(match == t.size())
			{
				for(; ia!=ib+1; ++ia)
				{
					if(keys[*ia])
					{
						if(match == t.size())
						{
							if(ib-ia+1 < min_ib-min_ia)
							{
								min_ia = ia;
								min_ib = ib+1;
							}
							if(--window[*ia] < keys[*ia])
								--match;
						}
						else
							break;
					}
				}
			}
        }
        if(min_ia != s.begin()-1)
            return string(min_ia, min_ib);
        else
            return "";

    }
};
int main()
{
    Solution ss;
    cout<<ss.minWindow("bdab","ab")<<endl;
}
