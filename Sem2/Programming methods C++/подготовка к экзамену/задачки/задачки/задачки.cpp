#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    vector<int>g;
    int x,n;
    ofstream f("f.txt");
    for(cin.getline(x);x;cin>>x)
    {
        f << x;
    }
    f.close();
    ifstream h("f.txt");
    while (!h.eof())
        h >> x;
        g.push_back(x);
    h.close();
    for (auto i : g)cout << i <<" ";
}
