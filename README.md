# arduino-serial-command
Send USB serial commands to an Arduino board to start and stop blinking of an LED

# Usage
```bash
bash -c "echo -n 0 | socat - /dev/ttyACM0"
bash -c "echo -n 1 | socat - /dev/ttyACM0"
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
