#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    vector<string> vecs;
    int n,m;
    string s, t;
    while(cin >> n >> m) {
        for(int i = 0; i != n; ++i) {
            getline(cin, s, '\n');
            vecs.push_back(s);
        }
        char ch;
        for(int i = 0; i != m; ++i) {
			while(cin.get(ch)){
				s.push_back(ch);
			}
//            for(vector<string>::iterator it = vecs.begin(); it != vecs.end(); ++it) {
//                string::iterator tmp;
//                while((tmp = find((*it).begin(), (*it).end(), s)) != (*it).end()) {
//                    (*it).replace(tmp, s.length(), t);
//                }
//            }
        }
cout << t << endl;
        for(vector<string>::iterator it = vecs.begin(); it != vecs.end(); ++it) {
            cout << *it << endl;
        }
    }
    return 0;
}
