#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool flag; // t =right f = left

int left_position = 10, right_position = 12;
bool visit[10];
int dis = 0;

int distance(int temp, int current) {
  if (temp == 0) {
    if (current == 2) return 3;
    if (current == 5) return 2;
    if (current == 8) return 1;
    if (current == 0) return 0;
  }
  if (current == 0) {
    if (temp == 2) return 3;
    if (temp == 5) return 2;
    if (temp == 8) return 1;
    if (temp == 0) return 0;
  }
  int answer = (current - temp) / 3;
  if (answer < 0) return -answer;
  return answer;
}

string solution(vector<int> numbers, string hand) {
  string answer = "";
  if (hand == "right") flag = true;
  if (numbers[0] == 2 || numbers[0] == 5 || numbers[0] == 8 || numbers[0] == 0) {
    if (flag) {
      right_position = numbers[0];
      answer.push_back('R');
    } else {
      left_position = numbers[0];

      answer.push_back('L');
    }
  } else if (numbers[0] == 1 || numbers[0] == 4 || numbers[0] == 7) {
    left_position = numbers[0];
    answer.push_back('L');
  } else {
    right_position = numbers[0];
    answer.push_back('R');
  }
  for (int i = 1; i < numbers.size(); ++i) {
    int temp = numbers[i];
    if (temp == 1 || temp == 4 || temp == 7) {
      left_position = temp;
      answer.push_back('L');
    } else if (temp == 3 || temp == 6 || temp == 9) {
      right_position = temp;
      answer.push_back('R');
    } else {
      int left, right;
      if (left_position == 1 || left_position == 4 || left_position == 7) {
        left = distance(temp, left_position + 1) + 1;
      } else if (left_position == 2 || left_position == 5 || left_position == 8 || left_position == 0) {
        left = distance(temp, left_position);
      } else if (left_position == 10) {
        left = distance(temp, 0) + 1;
      }
      cout << left_position << "\t" << left << endl;
      if (right_position == 3 || right_position == 6 || right_position == 9) {
        right = distance(temp, right_position - 1) + 1;
      } else if (right_position == 2 || right_position == 5 || right_position == 8 || right_position == 0) {
        right = distance(temp, right_position);
      } else if (right_position == 12) {
        right = distance(temp, 0) + 1;
      }
      cout << right_position << "\t" << right << endl;
      if (left > right) {
        answer.push_back('R');
        right_position = temp;
      } else if (left == right) {
        if (flag) {
          answer.push_back('R');
          right_position = temp;
        } else {
          answer.push_back('L');
          left_position = temp;
        }
      } else {
        answer.push_back('L');
        left_position = temp;
      }
    }
  }
  return answer;
}

int main() {

}