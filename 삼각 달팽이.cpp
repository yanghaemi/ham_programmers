#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int n) {
    
    vector<vector<int>> v(n, vector<int>(n, 0));
 //2차원 벡터 생성
    
    int n_sum =0;
    for(int i= 0 ;i<n;i++){
        n_sum += i;
    }
    
    int row = -1;
    int col =0;
    
    int curNum =1; //각 배열에 채울 현재 숫자
    
    for(int i=n;i>0;i-=3){
        for(int j=0; j< i;j++) v[++row][col] = curNum++;    //왼쪽 모서리
        for(int j=0; j<i-1; j++) v[row][++col] = curNum++;  //아래 모서리
        for(int j=0;j<i-2; j++) v[--row][--col] = curNum++; //오른쪽 모서리
    }
    
    
    vector<int> answer;
    
    for(int r=0;r<n ;r++){  //answer에 1차원 형태로 push_back하기
        for(int c=0;c<n;c++){
        if(v[r][c] !=0) answer.push_back(v[r][c]);
        }
    }
    
    return answer;
}
