#!/bin/bash
pid_maximum=$(cat /proc/sys/kernel/pid_max)
echo "maximum value of pid is: $pid_maximum"
