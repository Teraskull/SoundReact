# SoundReact
Arduino project for a sound reacting 5V non-addressable RGB LED Strip.

## Note

Make sure you are using a `non-addressable RGB LED`, with 4 contacts.

For this project you need:
- Any Arduino (I tested on Arduino UNO)
- Sound Sensor (I used a sensor based on LM393)
- RGB Strip (I used a 2-meter long one)

## Usage
- Connect all pins as shown on `Connection-schematic.jpg`.
- Set the value of `minNum` and `maxNum` as you like. A higher value will result in a slower change of colors. (As I experimented, I found out that the range 4000-15000 looks the best)

![Connection Schematic](/Connection-schematic.jpg)

## License

This software is available under the following licenses:

  * MIT
