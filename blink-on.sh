#!/usr/bin/env bash

bash -c "stty -F /dev/ttyUSB0 -hup; echo -n 1 > /dev/ttyUSB0"
