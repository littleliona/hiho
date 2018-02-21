#include<iostream>
using namespace std;
#include<vector>
#include<map>

void delete_node(int N, int K, vector<int> weight, vector<int> parent)
{
    map<int, int> parent_dic;
    map<int, int> ::iterator it;
    for (int i = 0; i < N; i++)
    {
        if (weight[i] < K)
        {   
            it = parent_dic.find(parent[i]);
            if (it != parent_dic.end())
                parent[i] = parent_dic[parent[i]];   
            parent_dic[i+1] = parent[i];
            parent[i] = -1;
        }
        else
        {
            it = parent_dic.find(parent[i]);
            if (it != parent_dic.end())
                parent[i] = parent_dic[parent[i]];
        }
        cout << parent[i]<< cout.fill(' ');
    }    
}


int main()
{
    int N,K;
    cin >> N >> K;
    vector<int> weight(N,0);
    vector<int> parent(N,0);

    for (int i = 0; i < N; i++)
    {
        cin >> weight[i];
    }

    for (int j = 0; j < N; j++)
    {
        cin >> parent[j];
    }
    delete_node(N, K, weight, parent);
    return 0;
}

