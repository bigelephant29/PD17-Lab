#include<cstdio>
#include<unordered_set>
using namespace std;
int main() {
    unordered_set<int> st;
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
        int t;
        scanf("%d", &t);
        if(st.find(t) == st.end()) st.insert(t);
        else st.erase(t);
    }
    printf("%d\n", *st.begin());
    return 0;
}
