#include<iostream>
#include <functional>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        //처음에 값이 없는 경우
        if (maxheap.size() == 0) {
            maxheap.push(x);
        }
        else {
            //최대 힙의 크기가 더 크다면 최소 힙에 값을 넣는다.
            if (maxheap.size() > minheap.size()) {
                minheap.push(x);
            }
            else {
                //크기가 같다면 최대 힙에 넣는다.
                maxheap.push(x);
            }
            //최대 힙의 top의 값(최댓값)이 최소 힙의 최솟값보다 크다면 값을 교환한다.
            if (maxheap.top() > minheap.top()) {
                int maxtop = maxheap.top();
                int mintop = minheap.top();
                maxheap.pop();
                minheap.pop();
                maxheap.push(mintop);
                minheap.push(maxtop);
            }
        }
        //중간값을 출력
        cout << maxheap.top() << '\n';
    }
    return 0;
}