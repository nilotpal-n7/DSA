#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string me;
    cin >> me;
    int n;
    cin >> n;
    cin.ignore();

    map<string, int> priority;
    set<string> names;

    while(n--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<string> words;
        string w;
        while(ss >> w) words.push_back(w);

        string X = words[0];
        string Y;
        int points = 0;

        if(words[1] == "posted") { points = 15; Y = words[3]; }
        else if(words[1] == "commented") { points = 10; Y = words[3]; }
        else if(words[1] == "likes") { points = 5; Y = words[2]; }

        // remove trailing "'s" if exists
        if(Y.size() > 2 && Y.substr(Y.size()-2) == "'s") Y = Y.substr(0, Y.size()-2);

        // add to set of names (excluding yourself)
        if(X != me) names.insert(X);
        if(Y != me) names.insert(Y);

        // update priority only if one of X or Y is you
        if(X == me) priority[Y] += points;
        else if(Y == me) priority[X] += points;
    }

    // prepare vector for sorting
    vector<string> res(names.begin(), names.end());
    sort(res.begin(), res.end(), [&](const string &a, const string &b) {
        if(priority[a] != priority[b]) return priority[a] > priority[b]; // descending points
        return a < b; // lexicographical
    });

    for(auto &name : res) cout << name << "\n";

    return 0;
}
