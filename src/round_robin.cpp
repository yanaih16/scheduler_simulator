#include "../include/round_robin.hpp"

void RoundRobin::start() {
    cout << "slice time" << endl;
    cin >> slice_time;
    while (finish.size() != (long unsigned int)task_num) {
        cout << "time:" << time << endl;
        while (!create.empty() && create.front().arrival_time == time) {
            wait.push(create.front());
            cout << "   ";
            cout << create.front().task_name << " is arrived" << endl;
            create.pop_front();
        }
        if (running.status == none) {
            if (!wait.empty()) {
                running = wait.front();
                wait.pop();
                quantum = 0;
            } else {
                cout << "   ";
                cout << "no task" << endl;
            }
        }
        if (running.status == run) {
            running.progres++;
            cout << "   ";
            cout << running.task_name << "(" << running.progres << "/" << running.cost << ")" << endl;
            quantum++;
            if (running.progres == running.cost) {
                running.status = fin;
            } else if (quantum == slice_time) {
                wait.push(running);
                running.status = none;
            }
        }
        if (running.status == fin) {
            cout << "   ";
            cout << running.task_name << " is finis" << endl;
            running.fin_time = time + 1;
            finish.push_back(running);
            running.status = none;
        }
        time++;
    }
    cout << "all task is finished" << endl;
}