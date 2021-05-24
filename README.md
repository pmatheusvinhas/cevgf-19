# cevgf-19
## COVID19 Emergency Ventilator General Firmware (CEVGF-19)

This project has borned in the middle of the Covid-19 pandemics when I was trying to find a way to help. I found a group created in Facebook called Coletivo Ar Brasil that was linking people whom wants to help and people that was needing help in different kind of projects: ventilators, donations of money, masks, medicines, etc.

As an Embedded Software Enginneer I went to the ventilators projects side and my way to help was to create a general firmware that could help max projects as possible.

The initial versions of this project intent to create an ease deploy firmware to be deployed by Mechanical Engineers and ones with none or little knowledge of microcontrolers. Arduino platform sounded a good choice but in stable version I expect to work with RTOS because of the necessity of time realiability.

## Installation

1. Clone this repo in `--recursive`
2. Open `cevgf-19.ino` with Arduino IDE and upload it to your board (Tested in Arduino UNO)

## How to use
In serial monitor:
Ti:Te relation (inhale/exhale):

't11' for Ti:Te = 1:1 't12' for Ti:Te = 1:2 't13' for Ti:Te = 1:3

PWM:
'vN' where N is PWM % (0-100). e.g: 'v50' for 50% of PWM.
Log

Versão de Teste para Projeto Victor/Nikolai (Mabuchi 4RPM Motor) @ 5h 15/04/2020