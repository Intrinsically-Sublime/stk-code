## README
______
Work in progress port of SuperTuxKart for Ubuntu Touch. See current state below.

### Build
______
Install clickable build enviroment https://clickable-ut.dev/en/latest/

In order to build SuperTuxKart from source, you'll need both the code and the assets
```
git clone https://github.com/Intrinsically-Sublime/stk-code stk-code
svn co https://svn.code.sf.net/p/supertuxkart/code/stk-assets stk-assets
```
To compile SuperTuxKart, run the following commands inside `stk-code/ubuntu_touch` directory
```
# Desktop
clickable desktop

# Armhf
clickable build --arch=armhf

# Arm64
clickable build --arch=arm64

# You can also use clean-build or add --dirty to prevent cleaning
```
## Current State
______
I have documented the current state for each build type below

### Clickable Arm64 build
______

This one builds completely and creates a clickable. I tried installing it on my OnePlus 6T which is running a GSI from a few months ago. It is the only arm64 device I have and is not a stable device.

I get
```
Fatal error: /home/phablet/Downloads/supertuxkart_1.2.0-ubports_arm64.click fail
WARNING:root:signiture check failed, but installing anyway as requested
Cannot install /home/phablet/Downloads/supertuxkart_1.2.0-ubports_arm64.click F
```
There may be more to the message but UT_tweak tools output window does not wrap and has no side scroll I could find.

### Clickable Armhf build
______
Armhf builds all the object files and only fails at the last step creating the executable which fails at 
```
Linking CXX executable bin/supertuxkart
lib/angelscript/projects/cmake/libangelscript.a(as_callfunc.cpp.o): In function `CallSystemFunction(int, asCContext*)':
as_callfunc.cpp:(.text+0x1e4): undefined reference to `CallSystemFunctionNative(asCContext*, asCScriptFunction*, void*, unsigned long*, void*, unsigned long long&, void*)'

```
I get the feeling
```
as_callfunc.cpp.o
```
should be a call to 
```
as_callfunc_arm.cpp.o
```
and that means it is not detecting the architecture correctly?? It appears to be related to Anglescript (Again https://github.com/supertuxkart/stk-code/issues/2411 https://github.com/supertuxkart/stk-code/pull/2195 https://github.com/supertuxkart/stk-code/issues/2569 and others) and compiling for arm. Again I am not sure how I would do this without modifying STKs code. I would rather do it from the clickable build files.

### Clickable desktop build
______
I can build all the object files and even build an executable but it fails at the very end with.
```
Installing /home/Projects/stk/stk-code/ubuntu_touch/manifest.json
Installing /home/Projects/stk/stk-code/ubuntu_touch/supertuxkart.apparmor
Installing /home/Projects/stk/stk-code/ubuntu_touch/supertuxkart.desktop
Installing /home/Projects/stk/stk-code/ubuntu_touch/icon.png
Successfully built package in './supertuxkart_1.2.0-ubports_amd64.click'.
/home/Projects/stk/stk-code/ubuntu_touch/build/x86_64-linux-gnu/app/supertuxkart_1.2.0-ubports_amd64.click: pass
non-network local connections being added to access control list
Mounting device home to /home/.clickable/home
[error  ] FileManager: Could not find file 'supertuxkart.git'in any standard location (esp. ../data).
[error  ] FileManager: Last location checked '/./share/supertuxkart/data/'.
[fatal  ] FileManager: Set $SUPERTUXKART_DATADIR to point to the data directory.
Command exited with non-zero exit status 1, see above for details. This is most likely not a problem with Clickable.
```
The solution is here I think https://forum.freegamedev.net/viewtopic.php?f=18&t=7595 but I would like to implement it from the clickable build files rather than modifying anything in the STK code or having to do it manually but I have not figured that one out yet.

