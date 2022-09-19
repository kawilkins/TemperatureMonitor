#!/bin/bash

# Set current version and file for testing
VERSION = 0.2.1
FILE = tempmonCPU.cpp

# Download and compile
wget https://raw.githubusercontent.com/kawilkins/TemperatureMonitor/$(VERSION)/src/tempmonCPU.cpp
g++ -o tempmonTEST $(FILE)