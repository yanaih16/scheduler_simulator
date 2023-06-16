#pragma once
#include <bits/stdc++.h>
using namespace std;

enum Status {
    run,
    fin,
    none
};

struct task {
    std::string task_name;
    int arrival_time;
    int cost;
    int progres = 0;
    int fin_time = -1;
    Status status = run;
};

class Scheduler {
   protected:
    int time;
    int task_num;
    deque<task> create;
    task running;
    vector<task> finish;

   public:
    Scheduler();
    void result();
};
