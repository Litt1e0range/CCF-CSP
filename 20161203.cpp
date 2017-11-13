#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
map<string,int> privilage;
map<string, map<string, int> > role;
map<string, map<string, int> > user;

void inputPrivilage(map<string,int>& mp) {
    int n;
    string s;
    char ch;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>s;
        ch = s[s.length()-1];
        if(isdigit(ch)) {
            string priv = s.substr(0,s.find(":"));
            if(mp[priv] < ch - '0') {
                mp[priv] = ch - '0';
            }
        } else {
            mp[s] = -1;
        }
    }
}

void inputRole(map<string, map<string, int> >& mp) {
    int n;
    string s;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>s;
        map<string, int> mmp;
        inputPrivilage(mmp);
        mp[s] = mmp;
    }
}

void inputUser(map<string, map<string, int> >& mp) {
    string userName, roleName;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int m;
        cin>>userName;
        cin>>m;
        map<string, int> roles;
        for(int j = 0; j < m; j++) {
            cin>>roleName;
            map<string, int> tmp = role[roleName];
            for(map<string, int>::iterator it = tmp.begin(); it!=tmp.end(); it++) {
                if(it->second == -1) {
                    roles[it->first] == -1;
                } else {
                    roles[it->first] = min(roles[it->first],it->second);
                }
            }
        }
        user[userName] = roles;
    }
}

int main(void) {
    inputPrivilage(privilage);
    inputRole(role);
    inputUser(user);
    int n;
    string s,t;
    cin >> n;
    while(n--) {
        cin >> s >> t;
        if(isdigit(t[t.length()-1])) {

            string pre = t.substr(0, t.find(":"));
            cout << user[s][pre] << endl;
            if(user[s].find(pre) != user[s].end()) {
cout << (user[s])[pre] << endl;
            } else cout << "false" << endl;
        } else {
            cout << user[s][t] << endl;
            if(user[s].find(t) != user[s].end()) {
                if(user[s][t] > 0) cout << user[s][t] << endl;
                cout << "true" << endl;
            } else cout << "false" << endl;
        }
    }
//    cout << user["bob"]["git"] << endl;
    for(map<string, map<string, int> >::iterator it1 = role.begin(); it1 != role.end(); ++it1) {
        cout << it1->first << ":";
        for(map<string, int>::iterator it2 = (it1->second).begin(); it2 != (it1->second).end(); ++it2) {
            cout << " " << it2->first << "-" << it2->second;
        }
        cout << endl;
    }
    return 0;
}


