#include<iostream>
using namespace std;
#include<vector>

void backpack(int N, int M, vector<int> need, vector<int> value)
{
    vector<int> dp(M+1,0);
    for (int i=0; i<N; i++)
    {
        for (int j=M; j>=need[i]; j--)
        {
            dp[j] = max(dp[j],dp[j-need[i]]+value[i]);
        }
    }
    cout << dp[M] << endl;
}

int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> need(N,0);
    vector<int> value(N,0);
    for(int i = 0; i < N;i++)
    {
        cin >> need[i] >> value[i];
    }
    backpack(N,M,need,value);

}

