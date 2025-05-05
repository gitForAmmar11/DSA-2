#include<bits/stdc++.h>
using namespace std;

struct Task
{
    string taskID;
    int startTime;
    int finishTime;
};

bool compare(Task a,Task b)
{
    if(a.finishTime<b.finishTime) return true;
    else return false;
}

int activitySelection(vector< Task > tasks)
{
    if(tasks.size() == 0) return 0;
    sort(tasks.begin(), tasks.end(), compare);
    int pick = 1;
    int freeTime = tasks[0].finishTime;
    cout << tasks[0].taskID << " ";
    for(int i=1; i<tasks.size(); i++)
    {
        Task currentTask = tasks[i];
        if(currentTask.startTime>=freeTime)
        {
            cout << tasks[i].taskID << " ";
            pick++;
            freeTime = currentTask.finishTime;
        }
    }
    cout << endl;
    return pick;
}

int main()
{
    cout << "Number of Task: ";
    int n;
    cin >> n;
    vector< Task > tasks(n);
    for(int i=0; i<n; i++)
    {
        getchar();
        cin >> tasks[i].taskID;
        cin >> tasks[i].startTime;
        cin >> tasks[i].finishTime;
    }
    int result = activitySelection(tasks);
    cout << result << endl;
    return 0;
}
