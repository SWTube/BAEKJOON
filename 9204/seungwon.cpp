#include<iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char startX, endX;
    int startY, endY;

    cin >> startX >> startY >> endX >> endY;

    startX -= 65;
    startY -= 1;
    int a1, a2;	// -, +
    a1 = startY + startX;
    a2 = startY - startX;
    int type1 = startX + startY;


    endX -= 65;
    endY -= 1;
    int b1, b2;	// -, +
    b1 = endY + endX;
    b2 = endY - endX;
    int type2 = endX + endY;

    if (type1 % 2 != type2 % 2) {
      cout << "Impossible" << endl;
      continue;
    }

    if (startX == endX && startY == endY) {
      cout << 0 << " " << char(startX + 65) << " " << int(startY) + 1 << endl;
      continue;
    }

    if (a1 == b1 || a2 == b2) {
      cout << 1 << " " << char(startX + 65) << " " << int(startY) + 1 << " " << char(endX + 65) << " " << int(endY) + 1 << endl;
      continue;
    }

    if (0 <= (a1 - b2) / 2 && (a1 - b2) / 2 <= 7) {
      int x = (a1 - b2) / 2;
      int y = (a1 - b2) / 2 + b2;
      cout << 2 << " " << char(startX + 65) << " " << int(startY) + 1 << " " << char(x + 65) << " " << int(y) + 1 << " " << char(endX + 65) << " " << int(endY) + 1 << endl;
      continue;
    }

    if (0 <= (b1 - a2) / 2 && (b1 - a2) / 2 <= 7) {
      int x = (b1 - a2) / 2;
      int y = (b1 - a2) / 2 + a2;
      cout << 2 << " " << char(startX + 65) << " " << int(startY) + 1 << " " << char(x + 65) << " " << int(y) + 1 << " " << char(endX + 65) << " " << int(endY) + 1 << endl;
      continue;
    }
  }
}
