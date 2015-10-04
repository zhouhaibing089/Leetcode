
void gameOfLife(int** board, int boardRowSize, int boardColSize) {
  int rs = boardRowSize;
  int cs = boardColSize;
  for (int i = 0; i < rs; ++i) {
    for (int j = 0; j < cs; ++j) {
      int state = board[i][j];
      int neighbors = 0;
      /* top left */
      if (i > 0 && j > 0 && board[i - 1][j - 1] >= 1) {
        ++neighbors;
      }
      /* top */
      if (i > 0 && board[i - 1][j] >= 1) {
        ++neighbors;
      }
      /* top right */
      if (i > 0 && j < (cs - 1) && board[i - 1][j + 1] >= 1) {
        ++neighbors;
      }
      /* left */
      if (j > 0 && board[i][j - 1] >= 1) {
        ++neighbors;
      }
      /* right */
      if (j < (cs - 1) && board[i][j + 1] >= 1) {
        ++neighbors;
      }
      /* bottom left */
      if (i < (rs - 1) && j > 0 && board[i + 1][j - 1] >= 1) {
        ++neighbors;
      }
      /* bottom */
      if (i < (rs - 1) && board[i + 1][j] >= 1) {
        ++neighbors;
      }
      /* bottom right */
      if (i < (rs - 1) && j < (cs - 1) && board[i + 1][j + 1] >= 1) {
        ++neighbors;
      }
      /* #1: under population */
      if (board[i][j] == 1 && neighbors < 2) {
        board[i][j] = 2;
      }
      /* #2: live */
      if (board[i][j] == 1 && neighbors >= 2 && neighbors <= 3) {
        board[i][j] = 1;
      }
      /* #3: overpopulation */
      if (board[i][j] == 1 && neighbors > 3) {
        board[i][j] = 2;
      }
      /* #4: reproduction */
      if (board[i][j] == 0 && neighbors == 3) {
        board[i][j] = -1;
      }
    }
  }
  for (int i = 0; i < rs; ++i) {
    for (int j = 0; j < cs; ++j) {
      if (board[i][j] == -1) {
        board[i][j] = 1;
      } else if (board[i][j] == 2) {
        board[i][j] = 0;
      }
    }
  }
}
