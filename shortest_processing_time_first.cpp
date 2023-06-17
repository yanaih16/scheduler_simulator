#include "shortest_processing_time_first.hpp"

void ShortestProcessingTimeFirst::start() {
    while (finish.size() != (long unsigned int)task_num) {
        cout << "time:" << time << endl;
        while (!create.empty() && create.front().arrival_time == time) {
            wait.push_back(create.front());
            cout << "   ";
            cout << create.front().task_name << " is arrived" << endl;
            create.pop_front();
            sort(wait.begin(), wait.end(), [](task& e1, task& e2) { return e1.cost < e2.cost; });
        }
        if (running.status == none) {
            if (!wait.empty()) {
                running = wait.front();
                wait.pop_front();
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