#include <iostream>

using namespace std;
enum Direction {
  NORTH,
  WEST,
  SOUTH,
  EAST
};

void printDirection(Direction direction) {
  switch (direction) {
    case NORTH:
      cout << "NORTH" << endl;
      break;
    case WEST:
      cout << "WEST" << endl;
      break;
    case SOUTH:
      cout << "SOUTH" << endl;
      break;
    case EAST:
      cout << "EAST" << endl;
      break;
    default:
      cout << "Invalid direction" << endl;
  }
}
Direction getNewDirection(Direction currentDirection, int command) {
  return Direction((currentDirection + command + 4) % 4);
}

int main() {
  char direction;
  int command;

  cout << "Enter the initial direction (N, W, S, E): ";
  cin >> direction;

  cout << "Enter the initial command (0, 1, -1): ";
  cin >> command;

  if (direction != 'N' && direction != 'W' && direction != 'S' && direction != 'E') {
    cout << "Invalid direction" << endl;
    return 1;
  }

  if (command != 0 && command != 1 && command != -1) {
    cout << "Invalid command" << endl;
    return 1;
  }

  Direction newDirection = getNewDirection(Direction(direction), command);
  cout << "The new direction of the robot is: ";
  printDirection(newDirection);

  return 0;
}
