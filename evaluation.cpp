#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
using namespace std;

void fcfs(int process_no[], int n, int burst_time[], int waiting_time[])
{
    waiting_time[0] = 0;
    for (int  i = 1; i < n ; i++ )
        waiting_time[i] =  burst_time[i-1] + waiting_time[i-1] ;
}


void sjf(int process_no[], int n, int burst_time[], int waiting_time[]) 
{ 
    //sort
    for (int i = 0; i < n; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++)
            if (burst_time[j] < burst_time[idx])
                idx = j;
        int temp = burst_time[i];
        burst_time[i] = burst_time[idx];
        burst_time[idx] = temp;
 
        temp = process_no[i];
        process_no[i] = process_no[idx];
        process_no[idx] = temp;
    }
    fcfs(process_no, n, burst_time, waiting_time);
} 

void rr(int process_no[], int n, int burst_time[], int waiting_time[]) 
{ 
    int qt=20;
    int time_left[n]; 
    for (int i = 0 ; i < n ; i++) 
        time_left[i] = burst_time[i]; 
  
    int curr_time = 0;
    while (true) 
    { 
        bool finished = true; 
        for (int i = 0 ; i < n; i++) 
        { 
            if (time_left[i] > 0) 
            { 
                finished = false;
                if (time_left[i] > qt) 
                { 
                    curr_time += qt; 
                    time_left[i] -= qt; 
                } 
                else
                { 
                    curr_time = curr_time + time_left[i]; 
                    waiting_time[i] = curr_time - burst_time[i]; 
                    time_left[i] = 0; 
                } 
            } 
        }
        if (finished == true) 
        break; 
    } 
} 
  
void schedule(int process_no[], int n, int burst_time[], int alg)
{
    int waiting_time[n];
    switch (alg)
    {
    case 1: //fcfs
        fcfs(process_no, n, burst_time, waiting_time); 
        break;
    case 2: //sjf
        sjf(process_no, n, burst_time, waiting_time); 
        break;
    case 3: //rr
        rr(process_no, n, burst_time, waiting_time); 
        break;
    
    default:
        break;
    }
        cout << "Process      "<< " Burst time  "<< " Waiting time \n";

    int total = 0; 
    for (int i=0; i<n; i++) 
    { 
        total = total + waiting_time[i];  
        cout << "   " << process_no[i] << "\t\t" << burst_time[i] <<"ms\t    "<< waiting_time[i] << "ms" << endl;
    } 
  
    float avg_time = total / (float)n;
    cout << "Average waiting time = " << avg_time;
}

int main() {
	STARTUPINFO si; 
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	clock_t process_1 = clock();
	CreateProcess(NULL, "C:\\Users\\crown\\Documents\\os_hw2\\process1.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	double bt_1 = (clock() - process_1);

	clock_t process_2 = clock();
	CreateProcess(NULL, "C:\\Users\\crown\\Documents\\os_hw2\\process2.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	double bt_2 = (clock() - process_2);

	clock_t process_3 = clock();
	CreateProcess(NULL, "C:\\Users\\crown\\Documents\\os_hw2\\process3.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	double bt_3 = (clock() - process_3);

	clock_t process_4 = clock();
	CreateProcess(NULL, "C:\\Users\\crown\\Documents\\os_hw2\\process4.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	double bt_4 = (clock() - process_4);

	clock_t process_5 = clock();
	CreateProcess(NULL, "C:\\Users\\crown\\Documents\\os_hw2\\process5.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	double bt_5 = (clock() - process_5);

	CloseHandle(pi.hProcess); 
	CloseHandle(pi.hThread);

    int process_no[] = {1, 2, 3, 4, 5};
    int n = 5;
    int  burst_time[] = {bt_1, bt_2, bt_3, bt_4, bt_5};

    cout << "------------------------------------------------\nFCFS\n";
    schedule(process_no, n,  burst_time, 1);

    cout << "\n------------------------------------------------\nRound Robin\n";
    schedule(process_no, n,  burst_time, 3);

    cout << "\n------------------------------------------------\nNonpreemptive SJF\n";
    schedule(process_no, n,  burst_time, 2);

	return 0;
}