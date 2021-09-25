#include <cstdio>
#include <vector>
using namespace std;
vector<int>root;
int find(int node) {
    if (root[node] == node)
        return node;
    else
        return root[node] = find(root[node]);
}
void uni(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    root[pb] = pa;
}
int main() {
    int num, calc;
    scanf("%d %d", &num, &calc); 
    for (int i = 0; i <= num; i++)
        root.push_back(i);
    int cmd, a, b;
    for (int i = 0; i < calc; i++) {
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd == 0) {
            uni(a, b);
        }
        else {
            if (find(a) == find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}