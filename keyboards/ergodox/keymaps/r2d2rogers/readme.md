Placeholder for r2d2rogers keymap for ErgoDox Infinity.

SpaceFN

Mouse/Movement Layer
Vim-like arrow keys and mouse scroll

Media Layer

I like to use this shell script to build and flash each half of the ErgoDox Infinity with this keymap. If I am running the script from remote, I use the bin files from my Downloads patht to pull them to the machine I am logged in from.  Change the first like to where you have checked out the repository.

```
#!/bin/bash

cd ~/Projects/ergodox/qmk_firmware/;
sudo make clean;
sudo make dfu-util KEYBOARD=ergodox SUBPROJECT=infinity KEYMAP=r2d2rogers VISUALIZER_ENABLE=yes MASTER=left;
cp ~/Projects/ergodox/qmk_firmware/.build/ergodox_infinity_r2d2rogers.bin /home/r2d2rogers/Downloads/keyboard/ergodox/qmk/ergodox_infinity_r2d2rogers_left.bin;

sudo make clean;
sudo make dfu-util KEYBOARD=ergodox SUBPROJECT=infinity KEYMAP=r2d2rogers VISUALIZER_ENABLE=yes MASTER=right;
cp ~/Projects/ergodox/qmk_firmware/.build/ergodox_infinity_r2d2rogers.bin /home/r2d2rogers/Downloads/keyboard/ergodox/qmk/ergodox_infinity_r2d2rogers_right.bin;

ls -altr ~/Downloads/keyboard/ergodox/qmk/;

```
