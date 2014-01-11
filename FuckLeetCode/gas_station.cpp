/*
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to
 * its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise
 * return -1.
 *
 * Note:
 * The solution is guaranteed to be unique.
 */
#include <vector>
#include <assert.h>
int CanCompleteCircuit(const std::vector<int> &gas, const std::vector<int> &cost) {
    int start = 0, sum = 0, cur = 0;
    for (int i = 0; i < gas.size(); i++) {
        if (cur < 0) {
            start = i;
            cur = 0;
        }
        int left = gas[i] - cost[i];
        sum += left;
        cur += left;
    }
    if (sum < 0)
        return -1;
    else
        return start;
}

int main() {
    int a[] = {5,0,9,4,3,3,9,9,1,2}, b[] = {6,7,5,9,5,8,7,1,10,5};
    std::vector<int> gas(a, a + sizeof(a) / sizeof(int));
    std::vector<int> cost(b, b + sizeof(b) / sizeof(int));
    assert(CanCompleteCircuit(gas, cost) == -1);
    int c[] = {31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    int d[] = {36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
    gas.clear();
    gas.insert(gas.end(), c, c + sizeof(c) / sizeof(int));
    cost.clear();
    cost.insert(cost.end(), d, d + sizeof(d) / sizeof(int));
    assert(CanCompleteCircuit(gas, cost) == 15);
    return 0;
}
