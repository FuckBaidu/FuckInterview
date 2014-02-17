/**
 * 3.4 in <Crack the code interview>.
 * In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of
 * different sizes which can slide onto any tower.The puzzle starts with disks sorted
 * in ascending order of size from top to bottom.You have the following constraints:
 * (A) Only one disk can be moved at a time
 * (B) A disk is slide off from one rod onto the next rod
 * (C) A disk can only be placed on top of a larger disk
 */
#include "util.h"
#include <stdio.h>
#include <stack>
void Hanoi(int n, int from, int by, int to) {
    if (n > 0) {
        Hanoi(n-1, from, to, by);
        printf("move disk %d from rod %d to rod %d\n", n, from, to);
        Hanoi(n-1, by, from, to);
    }
}

struct Operation {
    int level;
    int from;
    int to;
    int by;
};

void Hanoi(int n) {
    ArrayStack<Operation> stack;
    Operation oper;
    oper.level = n;
    oper.from = 1;
    oper.by = 2;
    oper.to = 3;
    stack.push(oper);
    while (!stack.empty()) {
        oper = stack.pop();
        if (oper.by != -1 && oper.level > 1) {
            Operation new_oper = oper;
            new_oper.level = oper.level - 1;
            new_oper.from = oper.by;
            new_oper.by = oper.from;
            new_oper.to = oper.to;
            stack.push(new_oper);
            new_oper.level = oper.level;
            new_oper.from = oper.from;
            new_oper.by = -1;
            new_oper.to = oper.to;
            stack.push(new_oper);
            new_oper.level = oper.level - 1;
            new_oper.from = oper.from;
            new_oper.by = oper.to;
            new_oper.to = oper.by;
            stack.push(new_oper);
        } else {
            printf("move disk %d from rod %d to rod %d\n", oper.level, oper.from, oper.to);
        }
    }
}

struct Peg {
    int id;
    std::stack<int> disks;
    Peg(int i) : id(i) { }
};

bool MoveBetween(Peg &a, Peg &b) {
    if (a.disks.empty() && b.disks.empty())
        return false;
    if (a.disks.empty() || (!b.disks.empty() && a.disks.top() > b.disks.top())) {
        printf("move disk %d from peg %d to peg %d\n", b.disks.top(), b.id, a.id);
        a.disks.push(b.disks.top());
        b.disks.pop();
    } else {
        printf("move disk %d from peg %d to peg %d\n", a.disks.top(), a.id, b.id);
        b.disks.push(a.disks.top());
        a.disks.pop();
    }
    return true;
}

void HanoiIterative(int n) {
    Peg source(1), destination(3), auxiliary(2);
    for (int i = n; i >= 1; i--)
        source.disks.push(i);
    while (destination.disks.size() != n) {
        if (n & 1) {
            if (!MoveBetween(source, destination))
                break;
            if (!MoveBetween(source, auxiliary))
                break;
        } else {
            if (!MoveBetween(source, auxiliary))
                break;
            if (!MoveBetween(source, destination))
                break;
        }
        if (!MoveBetween(auxiliary, destination))
            break;
    }
}

int main() {
    for (int i = 1; i <= 4; i++) {
        printf("Solution for %d disks:\n", i);
        //Hanoi(i, 1, 2, 3);
        HanoiIterative(i);
    }
    return 0;
}
