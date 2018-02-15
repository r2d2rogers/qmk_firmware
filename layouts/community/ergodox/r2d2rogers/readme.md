Placeholder for r2d2rogers keymap for ErgoDox Infinity.

SpaceFN

Mouse/Movement Layer
Vim-like arrow keys and mouse scroll

Media/Function Layer

I like to use this shell script to build and flash each half of the ErgoDox Infinity with this keymap. If I am running the script over SSH, I use the bin files from my Downloads path to pull them to the local machine to flash.  Change the first like to where you have checked out the repository.

```
#!/bin/bash

cd ~/Projects/ergodox/qmk_firmware/;
# make dfu-util KEYBOARD=ergodox SUBPROJECT=infinity KEYMAP=r2d2rogers VISUALIZER_ENABLE=yes MASTER=left;
make MASTER=left ergodox-infinity-r2d2rogers-.build/ergodox_infinity_r2d2rogers_left.bin
cp .build/ergodox_infinity_r2d2rogers_left.bin /home/r2d2rogers/Downloads/keyboard/ergodox/qmk/ergodox_infinity_r2d2rogers_left.bin;

# make dfu-util KEYBOARD=ergodox SUBPROJECT=infinity KEYMAP=r2d2rogers VISUALIZER_ENABLE=yes MASTER=right;
make MASTER=right ergodox-infinity-r2d2rogers-.build/ergodox_infinity_r2d2rogers_right.bin
cp .build/ergodox_infinity_r2d2rogers_right.bin /home/r2d2rogers/Downloads/keyboard/ergodox/qmk/ergodox_infinity_r2d2rogers_right.bin;

ls -altr ~/Downloads/keyboard/ergodox/qmk/;
```
