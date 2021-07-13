#include <iostream>
#include <list>

std::list<int> selected;

void printCand(std::list<int>& cand) {
    printf("[");
    for (int s : cand) {
        printf("%d,", s);
    }
    printf("]");
}

void printAll(int tabCount, int count, std::list<int>& cand) {
    for (int i = 0; i < tabCount; ++i) {
        printf("\t");
    }
    printf("<printAllStart count=%d cand=", count);
    printCand(cand);
    printf(">\n");

    if (count == 0) {
        // // 지금까지 선택한 애들 출력
        // for (int s : selected) {
        //     printf("%d ", s);
        // }
        // printf("\n");
    } else if (!cand.empty()) {
        // 1. 첫번째를 출력하는 경우
        int front = cand.front();
        selected.push_back(front);
        cand.pop_front();
        printAll(tabCount+1, count-1, cand);

        // 2. 첫번째를 안 출력하는 경우
        selected.pop_back();
        printAll(tabCount+1, count, cand);

        cand.push_front(front);
    }

    for (int i = 0; i < tabCount; ++i) {
        printf("\t");
    }
    printf("</printAllEnd count=%d cand=", count);
    printCand(cand);
    printf(">\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    std::list<int> cand;
    for (int i = 1; i <= n; ++i) {
        cand.push_back(i);
    }

    printAll(0, m, cand);

    return 0;
}