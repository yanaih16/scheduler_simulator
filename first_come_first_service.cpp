#include "first_come_first_service.hpp"

void FirstComeFirstService::start() {
    while (finish.size() != (long unsigned int)task_num) {
        cout << "time:" << time << endl;
        while (!create.empty() && create.front().arrival_time <= time) {
            wait.push(create.front());
            cout << "   ";
            cout << create.front().task_name << " is arrived" << endl;
            create.pop_front();
        }
        if (running.status == none) {
            if (!wait.empty()) {
                running = wait.front();
                wait.pop();
            } else {
                cout << "   ";
                cout << "no task" << endl;
            }
        }
        if (running.status == run) {
            running.progres++;
            cout << "   ";
            cout << running.task_name << "(" << running.progres << "/" << running.cost << ")" << endl;
            if (running.progres == running.cost) {
                running.status = fin;
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