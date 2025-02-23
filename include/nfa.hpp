#ifndef NFA_HPP
#define NFA_HPP

#include <map>
#include <set>

class NFA {
    private:
        int states;
        std::set<int> final_states;
        std::map<int, std::map<char, std::set<int> > > transitions;
    public:
        NFA(int noofstates);
        void addTransition(int from, char symbol, int to);
        void addFinalState(int state);
        std::set<int> epsilon_closures(std::set<int> states);
};

#endif