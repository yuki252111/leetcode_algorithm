#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//边界上的不会被包围（反过来想），bfs
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty()) {
			return;
		}
		int rowNum = board.size();
		if (rowNum == 0) {
			return;
		}
		int colNum = board[0].size();
		if (colNum == 0) {
			return;
		}
		for (int i = 0; i < rowNum; i++) {
			for (int j = 0; j < colNum; j++) {
				if (board[i][j] == 'O') {
					if (i == 0 || i == rowNum - 1 || j == 0 || j == colNum - 1) {
						bfs(board, i, j, rowNum, colNum);
					}
				}
			}
		}
		for (int i = 0; i < rowNum; i++) {
			for (int j = 0; j < colNum; j++) {
				if (board[i][j] == '*') {
					board[i][j] = 'O';
				}
				else {
					board[i][j] = 'X';
				}
			}
		}
	}
private:
	void bfs(vector<vector<char>>& board, int i, int j, int rowNum, int colNum) {
		queue<pair<int, int>> q;
		board[i][j] = '*';
		q.push(make_pair(i, j));
		while (!q.empty()) {
			pair<int,int> pos = q.front();
			q.pop();
			int x = pos.first, y = pos.second;
			if (x - 1 >= 0 && board[x - 1][y] == 'O') {
				q.push(make_pair(x - 1, y));
				board[x - 1][y] = '*';
			}
			if (x + 1 < rowNum  && board[x + 1][y] == 'O') {
				q.push(make_pair(x + 1, y));
				board[x + 1][y] = '*';
			}
			if (y - 1 >= 0 && board[x][y - 1] == 'O') {
				q.push(make_pair(x, y - 1));
				board[x][y - 1] = '*';
			}
			if (y + 1 < colNum && board[x][y + 1] == 'O') {
				q.push(make_pair(x, y + 1));
				board[x][y + 1] = '*';
			}
		}
	}
};

int main() {
	vector<vector<char>> board(2, vector<char>(2, 'O'));
	Solution s;
	s.solve(board);
}