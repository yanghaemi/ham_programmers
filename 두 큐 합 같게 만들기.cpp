#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<long int> q1;
queue<long int> q2;
long int half_sum;
long int sum1 = 0;
long int sum2 = 0;
long long int sum = 0;
long int Max = -99;

int solution(vector<int> queue1, vector<int> queue2) {

    for (int i = 0; i < queue1.size(); i++) {
        q1.push(queue1[i]);
        sum1 += queue1[i];
        if (Max < queue1[i]) Max = queue1[i];
    }

    for (int i = 0; i < queue1.size(); i++) {
        q2.push(queue2[i]);
        sum2 += queue2[i];
        if (Max < queue2[i]) Max = queue2[i];
    }
    sum = sum1 + sum2;
    half_sum = (sum) / 2;

    if (sum % 2 != 0) return -1;     // half_sum이 홀수이면 -1 반환
    if (Max > half_sum) return -1;

    int cnt = 0;
    int num = 0;
    
    int preSum1=sum1;
    int preSum2=sum2;
    int flag = 0;
    
    

    while (sum1 != sum2) {
        
       int preDiff = sum1-sum2;
        while (sum1 > half_sum) {
            num = q1.front();
            sum1 -= num;
            sum2 += num;
            q2.push(num);
            q1.pop();
            cnt++; // 큐에서 값을 뽑아내는 횟수만큼 cnt 증가
        }
        

        while (sum2 > half_sum) {
            num = q2.front();
            sum2 -= num;
            sum1 += num;
            q1.push(num);
            q2.pop();
            cnt++; // 큐에서 값을 뽑아내는 횟수만큼 cnt 증가
        }
        if(preDiff == sum1-sum2) {
            if(flag == 10) return -1;
            else flag ++;
        }
        if(preSum1==sum2 && preSum2==sum1) return -1;
    }
    return cnt;
}
