#include "schedule.hpp"

Scheduler::Scheduler() {
    time = 0;
    running.status = none;
    cout << "タスクの生成方法" << endl
         << "0:手入力" << endl
         << "1:ファイル入力" << endl
         << "2:ランダム生成" << endl;
    int num;
    cin >> num;
    if (num == 0) {
        cout << "task of num" << endl;
        cin >> task_num;
        cout << "task name,arriva time,cost" << endl;
        for (int i = 0; i < task_num; i++) {
            task t;
            cin >> t.task_name;
            cin >> t.arrival_time;
            cin >> t.cost;
            create.push_back(t);
        }
    } else if (num == 1) {
        ifstream ifs("task.txt");
        ifs >> task_num;
        for (int i = 0; i < task_num; i++) {
            task t;
            ifs >> t.task_name;
            ifs >> t.arrival_time;
            ifs >> t.cost;
            create.push_back(t);
        }
    } else {
        srand(std::time(NULL));
        ofstream ofs("task.txt");
        task_num = rand() % 18 + 3;
        ofs << task_num << endl;
        for (int i = 0; i < task_num; i++) {
            task t;
            t.task_name = 'A' + i;
            t.arrival_time = rand() % 50;
            t.cost = 1 + rand() % 50;
            create.push_back(t);
            ofs << t.task_name << " " << t.arrival_time << " " << t.cost << endl;
        }
    }
    sort(create.begin(), create.end(), [](task& e1, task& e2) { return e1.arrival_time < e2.arrival_time; });
}

void Scheduler::result() {
    cout << "task name|arrival time|finish time|response time" << endl;
    int sum = 0;
    for (auto v : finish) {
        cout << setw(9) << v.task_name << "|"
             << setw(12) << v.arrival_time << "|"
             << setw(11) << v.fin_time << "|"
             << setw(13) << v.fin_time - v.arrival_time << endl;
        sum += v.fin_time - v.arrival_time;
    }
    cout << "response time average is " << (double)sum / (double)task_num << endl;
}
