#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m, a, b;
    while(cin >> n) {
        cin >> m;
        list<int> lt;
        for(int i = 1; i <= n; ++i) {
            lt.push_back(i);
        }
        for(int i = 0; i < m; ++i) {
            cin >> a >> b;
            list<int>::iterator it = find(lt.begin(), lt.end(), a);
            it = lt.erase(it);//ɾ����ӦԪ�� 
            advance(it, b);//���������ƶ�b��λ�� 
            lt.insert(it,a);
        }
        for(list<int>::iterator it = lt.begin();it != lt.end(); ++it){
        	cout << *it << " ";
		}
		cout << endl;
    }
    return 0;
}
