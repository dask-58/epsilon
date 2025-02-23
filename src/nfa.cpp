#include "../include/nfa.hpp"
#include <queue>

NFA::NFA(int numStates) : states(numStates) {}

void NFA::addTransition(int from, char symbol, int to) {
    transitions[from][symbol].insert(to);
}

void NFA::addFinalState(int state) {
    final_states.insert(state);
}

// BFS
std::set<int> NFA::epsilon_closures(std::set<int> states) {
    std::queue<int> Q;
    std::set<int> closures = states;
    for (int state : states) {
        Q.push(state);
    }
    while (!Q.empty()) {
        int current = Q.front();
        Q.pop();
        for (int next : transitions[current]['\0']) {
            if (closures.find(next) == closures.end()) {
                closures.insert(next);
                Q.push(next);
            }
        }
    }
    return closures;
}
