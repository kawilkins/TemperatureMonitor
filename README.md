<center>

# TemperatureMonitor

</center>

# Releases

## `v0.1.2-stable`

* First release on 07/23/2022.

<hr>

# Program Description
Reads system temperature from `/sys/class/thermal/thermal_zone0/temp` and outputs to human readable format in Celsius (&deg;C), Fahrenheit (&deg;F), and Kelvin (K).  This is a terminal based application is intended for exclusive use on Linux machines and will not work on Windows or Mac.

Please report issues.

This software is FOSS (Free and Open Source Software).  Therefore there is NO COST to download and use this software.  If you would like to support my work you can [Buy Me a Coffee](https://www.buymeacoffee.com/kwilkins).

<hr>

# Screenshot

![Preview](https://raw.githubusercontent.com/kawilkins/TemperatureMonitor/0.2.1/screenshots/tempmon-preview.png)

# Quick setup

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
 tempmon
```
<hr>

# Compiling
It is easy to Compile but you need to have g++

**Clone the repo with git**
```
git clone https://github.com/kawilkins/TemperatureMonitor.git
```
**Change directory and then compile it**
```
cd TemperatureMonitor/src
g++ -o tempmon tempmonCPU.cpp
```
Additionally you may want to move the complied binary to ```/usr/bin```.
