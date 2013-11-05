/**
 * 6.5 in <Crack the code interview>.
 * You have a five quart jug and a three quart jag , and an unlimited supply of water
 * How wolud you come up with exactly four quarts of water?
 */
#define private public
#include <vector>
#include <string.h>
#include "util.h"
enum OperationType {
    DROPA,
    DROPB,
    FULLA,
    FULLB,
    TRANSFERB,
    TRANSFERA,
    NONE,
};
struct Operation {
    int quart_a;
    int quart_b;
    int last_op_index;
    OperationType last_op_type;
};

void Print(Operation *ops, int index) {
    if (index != -1) {
        Print(ops, ops[index].last_op_index);
        switch(ops[index].last_op_type) {
            case DROPA:
                printf("Empty A.\t");
                break;
            case DROPB:
                printf("Empty B.\t");
                break;
            case FULLA:
                printf("Fullfill A.\t");
                break;
            case FULLB:
                printf("Fullfill B.\t");
                break;
            case TRANSFERA:
                printf("Pour water from B to A.\t");
                break;
            case TRANSFERB:
                printf("Pour water from A to B.\t");
                break;
            case NONE:
                printf("Start.\t");
                break;
        }
        printf("There are %d quarts in A, %d quarts in B\n", ops[index].quart_a, ops[index].quart_b);
    }
}

void PourWater(int quart_a, int quart_b, int need) {
    ArrayQueue<Operation> ops;
    bool flags[quart_a + 1][quart_b + 1];
    memset(flags, 0, quart_a * quart_b * sizeof(bool));
    bool found = false;
    Operation op;
    op.quart_a = quart_a;
    op.quart_b = quart_b;
    op.last_op_index = -1;
    op.last_op_type = NONE;
    ops.enqueue(op);
    flags[quart_a][quart_b] = true;
    while (!ops.empty()) {
        op = ops.dequeue();
        if (op.quart_a == need || op.quart_b == need) {
            found = true;
            break;
        }
        Operation next_op;
        next_op.last_op_index = ops._head - 1;
        for (int i = 0; i < (int)NONE; i++) {
            int next_a, next_b;
            switch((OperationType)i) {
                case DROPA:
                    next_a = 0;
                    next_b = op.quart_b;
                    break;
                case DROPB:
                    next_a = op.quart_a;
                    next_b = 0;
                    break;
                case FULLA:
                    next_a = quart_a;
                    next_b = op.quart_b;
                    break;
                case FULLB:
                    next_a = op.quart_a;
                    next_b = quart_b;
                    break;
                case TRANSFERA:
                    int lefta = quart_a - op.quart_a;
                    next_a = (lefta > op.quart_b) ? op.quart_a + op.quart_b : quart_a;
                    next_b = (lefta > op.quart_b) ? 0 : op.quart_b - lefta;
                    break;
                case TRANSFERB:
                    int leftb = quart_b - op.quart_b;
                    next_a = (leftb > op.quart_a) ? 0 : op.quart_a - leftb;
                    next_b = (leftb > op.quart_a) ? op.quart_a + op.quart_b : quart_b;
                    break;
            }
            if (!flags[next_a][next_b]) {
                next_op.last_op_type = (OperationType)i;
                next_op.quart_a = next_a;
                next_op.quart_b = next_b;
                ops.enqueue(next_op);
                flags[next_a][next_b] = true;
            }
        }
    }
    if (found) {
        Print(ops._array, (ops._head - 1) % ARRAYSIZE);
    } else {
        printf("Not found\n");
    }
}

int main() {
    PourWater(5, 3, 4);
    PourWater(5, 3, 6);
    PourWater(5, 3, 3);
    PourWater(12, 7, 9);
    return 0;
}
