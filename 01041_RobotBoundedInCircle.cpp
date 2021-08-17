/*
On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degrees to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

Example 1:

Input: instructions = "GGLLGG"
Output: true
Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: instructions = "GG"
Output: false
Explanation: The robot moves north indefinitely.
Example 3:

Input: instructions = "GL"
Output: true
Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Constraints:

1 <= instructions.length <= 100
instructions[i] is 'G', 'L' or, 'R'.
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<int> units(4, 0);
        vector<bool> dir(4, false);
        dir[0] = true;
        int c_dir = 0;
        for (auto e : instructions) {
            if (e == 'G') {
                units[c_dir]++;
            } else if (e == 'L') {
                dir[c_dir] = false;
                c_dir = (c_dir - 1 + 4) % 4;
                dir[c_dir] = true;
            } else if (e == 'R') {
                dir[c_dir] = false;
                c_dir = (c_dir + 1) % 4;
                dir[c_dir] = true;
            }
        }
        
        if (!dir[0]) {
            return true;
        }
        return units[0] == units[2] && units[1] == units[3];
    }
};
