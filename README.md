# TemperatureMonitor
## What does it do?
Reads system temperature from `/sys/class/thermal/thermal_zone0/temp` and outputs to human readable format.  This is a terminal based application is intended for Linux computer systems and will not work on Windows or Macintosh computer systems.

Please report issues.

<hr>

## Installation
It is easy to install by using the following commands in terminal:

**Make a hidden directory in your user's home directory**
```
mkdir ~/.TemperatureMonitor
```

**Use WGET to download the source code to the hidden directory you just created**
```
wget https://raw.githubusercontent.com/kawilkins/TemperatureMonitor/master/src/tempmonCPU.cpp -P ~/.TemperatureMonitor/
```

**Compile the .cpp file**
```
g++ -o ~/.TemperatureMonitor/tempmon ~/.TemperatureMonitor/tempmonCPU.cpp
```
Addtionally you may want to add an alias to your `~/.bash_aliases` file so that you don't have to type in the executable file path/name all the time.

To do this make sure that the `~/.bash_aliases` file is created then add this line inside the file:
```
alias tempmon="~/.TemperatureMonitor/tempmon"
```
Then run the following command to refresh your BASH session:
```
source ~/.bashrc
```
<hr>