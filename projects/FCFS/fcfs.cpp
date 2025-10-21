

#include <iostream>

struct Process{
    int id;
    int arrivalTime;
    int burstTime;
    int waiting;
    int turnaround;
};



int main(){
    
    Process p[20];

    int n{};
    std::cout << "Number of processes: ";
    std::cin >> n;

    for (int i = 0; i < n; i++){
        p[i].id = i+1;
        std::cout << p[i].id << " arrival time: ";
        std::cin >> p[i].arrivalTime;
        std::cout << p[i].burstTime << " burst time: ";
        std::cin >> p[i].burstTime;
    }

    for(int i=0; i < n-1; i++){
        for(int j = i + 1; j < n; j++){
            if(p[i].arrivalTime > p[j].arrivalTime){
                std::swap(p[i], p[j]);
            }
        }
    }

    int currentTime = 0;
    for(int i = 0; i < n; i++){
        if(currentTime < p[i].arrivalTime){
            currentTime = p[i].arrivalTime;
        }

        p[i].waiting = currentTime - p[i].arrivalTime;
        currentTime += p[i].burstTime;
        p[i].turnaround = p[i].waiting + p[i].burstTime;
    }

    std::cout << "\nID\tArrival\tBurst\tWaiting\tTurnaround\n";
    int totalWaiting = 0, totalTurnaround = 0;
    for(int i=0; i<n; i++) {
        std::cout << p[i].id << "\t"
             << p[i].arrivalTime << "\t"
             << p[i].burstTime << "\t"
             << p[i].waiting << "\t"
             << p[i].turnaround << "\n";
        totalWaiting += p[i].waiting;
        totalTurnaround += p[i].turnaround;
    }

    double avgWaiting = (double) totalWaiting / n;
    double avgTurnaround = (double) totalTurnaround / n;

    std::cout << "\nAverage Waiting Time: " << avgWaiting;
    std::cout << "\nAverage Turnaround Time: " << avgTurnaround << "\n";

    return 0;
}  