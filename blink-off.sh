#!/usr/bin/env bash

bash -c "stty -F /dev/ttyUSB0 -hup && sleep 2 && echo -n 0 > /dev/ttyUSB0"
