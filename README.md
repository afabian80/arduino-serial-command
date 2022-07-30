# arduino-serial-command
Send USB serial commands to an Arduino board to start and stop blinking of an LED

# Usage
This worked for me with an Arduino Leonardo
```bash
bash -c "echo -n 0 | socat - /dev/ttyACM0"
bash -c "echo -n 1 | socat - /dev/ttyACM0"
```

But with a cheaper Arduino Nano with CH340 driver only this helped

```bash
stty -F /dev/ttyUSB0 -hup
echo -n 1 > /dev/ttyUSB0
echo -n 0 > /dev/ttyUSB0
```

You can add these commands to your crontab.
For example,

```bash
crontab -e
```

Add this line to start blinking every day at 10:40 and 15:40
```
40 10,15 * * * echo -n 1 | socat - /dev/ttyACM0
```

or

```
40 10,15 * * *  bash -c "stty -F /dev/ttyUSB0 -hup; echo -n 0 > /dev/ttyUSB0"
```
