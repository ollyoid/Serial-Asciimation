# Serial ASCIImation

## Concept
This is a project that was inspired by Jeroen Domburg and Arjen Meek's gift to  Maarten Tromp which was a [Hardware Tetris Unit](https://www.geekabit.nl/projects/some-gifts-for-me/). I think this idea can be taken further, by designing other low tech text based games, programs, and perhaps things similar to [explorable explanations](https://explorabl.es/). I like the concept of sharing programs as physical objects that aren't actually running on the CPU of your computer. This gives these programs added value and means they will be more treasured.

## How does it work?
Basically, send frames of ASCII characters over serial from an MCU really quickly, this MCU should then be able to respond to inputs from the user.

## Progress
So far I have started programming a framework for these asciimations in c, and ported this to work on arduino. At the moment I am overcoming issues relating to the baud rate inputs from the serial terminal.

## Where is the project going?
If i can get the initial concept working I hope to have some PCBs manufactured  and load different asccimation programs onto them and distribute them. Hopefully I can design a simple framework that others can use to build their own asciimation devices and perhaps swap and share them. 
