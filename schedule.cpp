#include "schedule.hpp"

Scheduler::Scheduler() {
    time = 0;
    running.status = none;
    cout << "task of num" << endl;
    cin >> task_num;
    for (int i = 0; i < task_num; i++) {
        task t;
        cout << "task name:";
        cin >> t.task_name;
        cout << "arriva time:";
        cin >> t.arrival_time;
        cout << "cost:";
        cin >> t.cost;
        create.push_back(t);
    }
    sort(create.begin(), create.end(), [](task& e1, task& e2) { return e1.arrival_time < e2.arrival_time; });
}

void Scheduler::result() {
    cout << "task name|arrival time|finish time|response time" << endl;
    for (auto v : finish) {
        cout << v.task_name << "|" << v.arrival_time << "|" << v.fin_time << "|" << v.fin_time - v.arrival_time << endl;
    }
}
