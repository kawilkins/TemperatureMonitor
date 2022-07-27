# TemperatureMonitor
## Release v0.1.2-stable
First release on 07/23/2022.

<hr>

## What does it do?
Reads system temperature from `/sys/class/thermal/thermal_zone0/temp` and outputs to human readable format.  This is a terminal based application is intended for Linux machines and will not work on Windows or Mac.

Please report issues.

This software is FOSS (Free and Open Source Software).  Therefore there is NO COST to download and use this software.  If you would like to support my work you can [Buy Me a Coffee](https://www.buymeacoffee.com/kwilkins)

<hr>

## Quick setup

**Download binary from github**
```
wget https://github.com/kawilkins/TemperatureMonitor/releases/download/v0.1.2-stable/tempmon
```

**Make it executable**
```
chmod +x tempmon
```
**Move it to ```/usr/bin```**
```
sudo mv tempmon /usr/bin
```
**Test it out**
```
watch tempmon
```
<hr>

## Compiling
It is easy to Compile but you need to have g++

**clone the repo with git**
```
git clone https://github.com/kawilkins/TemperatureMonitor.git
```
**change directory and then compile it**
```
cd TemperatureMonitor/src
g++ -o tempmon tempmonCPU.cpp
```
Additionally you may want to move the complied binary to ```/usr/bin```
