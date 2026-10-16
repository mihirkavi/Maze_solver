# maze_solver

Arduino code for a robot that autonomously takes decisions to follow and solve a maze
traced by a black line.

## Overview

The robot reads a five-sensor infrared line array, steers along the line with a PID
controller, and performs interrupt-driven turns at junctions. The goal is a maze solver
based on the wall-follower (hand rule) algorithm described below.

### Maze-solving algorithm

Priorities are set when the bot encounters a junction:

- If a 'T' joint with a right turn is present, it goes straight.
- If a 'T' joint with a left turn is present, it takes the left turn.
- If it is a dead end, it takes a 'U' turn.

So the priorities are **left turn > straight > right turn**: the highest priority is the
left turn and the lowest is the right turn. This lets the bot simply solve the maze.

Once the algorithm has run through the maze in a dry run, the plan is to store the correct
turns in memory and replay those turn instructions on the next run.

## What's inside

```
Advanced-Line-follower.ino  # main sketch: PID line following, interrupt-based turns,
                            #   serial PID tuning helper (btDebug)
DCMotors.h                  # templated dual DC motor driver (enable + 2 direction pins per motor)
Sensor.h                    # templated 5-sensor IR array; computes error / turn-required flag
maze_test.h                 # DetectNode: classifies T-junctions and dead ends from sensor readings
```

Pin assignments are set by the template arguments in the sketch:
`DCMotors<10,18,19,11,14,15>` (enL, L1, L2, enR, R1, R2) and `Sensor<2,3,4,5,6>`.

## Getting started

1. Install the Arduino IDE and the [EnableInterrupt](https://github.com/GreyGnome/EnableInterrupt) library.
2. Open `Advanced-Line-follower.ino` (keep the `.h` files in the same folder).
3. Adjust pins and the `Kp`, `Ki`, `Kd` gains for your robot, then upload.

## Status

Work-in-progress robotics project from 2016; not actively maintained. The node detector
in `maze_test.h` is not yet wired into the main loop, the turn-memory replay is not
implemented, and the sketch contains an incomplete line (`maze_`) that must be removed
before it compiles.

## License

Released under the Apache License 2.0. See [LICENSE](LICENSE).
