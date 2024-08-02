#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);   // **** input problems happen not only when cin or init errors, can also happen due to inf loop/out of bounds/code errors, etc
    cin.tie(0);
    cout.tie(0);                    // how to initialise and use pushback in 2d vectors??

    int t ; cin >> t;
    while(t--){
        int n; cin >> n;
        //vector< vector<int> > grid;        do we have to tell size before accessing elements?
        vector< vector<char> > grid(2, vector<char> (n));         // mtd of initialising 2d, else doesnt work

        for(int i=0;i<n;i++){
            char temp; cin >> temp;                              // wasnt working bcoz each row was clustered so int vector wont work, make char
            grid[0][i] = temp;                                  // also assign only works with cin, else had to do temp = quotes(no);
        }
        for(int i=0;i<n;i++){
            char temp; cin >> temp;
            grid[1][i] = temp;
        }
        string s;
        int count = 1,changeIndex;

        pair<int, int> p = {0,0};
        s.push_back(grid[0][0]);
        while(p.first != 1 || p.second != n-1){
            if(p.first == 0){            
                if(p.second == n-1 || grid[p.first+1][p.second] < grid[p.first][p.second+1]){
                    p.first++;                      // write here since imp to check first, else out of bounds accessed
                    changeIndex = p.second;
                }
                else if(grid[p.first+1][p.second] > grid[p.first][p.second+1]) p.second++;
                else if(grid[p.first+1][p.second] == grid[p.first][p.second+1]){   // forgot border n-1 case, also &&, not || and wrote != inplace of ==
                     p.second++;        // wrote if, instead of else if, so wrong
                }
                //else p.second++;          write as OR in first case, else changeIndex goes wrong  


                // ***** all above problems show how imp order of checking/statements is, think properly        

            }else{
                p.second++;
            }
            s.push_back(grid[p.first][p.second]);
            // *** converting int to char : s.push_back(grid[p.first][p.second]+ '0');
        }

        for(int i=changeIndex ;i >= 0;i--){
            if(grid[0][i] == grid[1][i-1]) count ++;
            else break;
        }
        cout << s << '\n' << count << "\n";
    }

    return 0;
}