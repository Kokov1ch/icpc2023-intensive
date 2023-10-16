#include <iostream>
#include "recurrent/TaskA/taskA.cpp"
#include "recurrent/TaskB/taskB.cpp"
#include "recurrent/TaskC/taskC.cpp"
#include "recurrent/TaskD/taskD.cpp"
using namespace std;

int main() {
    taskC task;

    task.solve();
    return 0;
}
