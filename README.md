# freebsd-ports-dank

![dank meme pic](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/dankbsd.jpg?1)

Welcome!

This fork of the FreeBSD Ports Collection adds more bleeding edge desktop-related patches.

**NOTE**: this is the new `lite`/`lite-gnome` branch, which is constantly rebased on top of `master`/`gnome-*`.

## Usage

- Make sure you have an up-to-date FreeBSD 13-CURRENT kernel and base
- Clone this repo into `/usr/ports` (if it's already managed by git, add this repo as a remote, fetch and checkout/merge)
- Build any ports you want :)

### Weston

A port for Weston is developed in [D10599](https://reviews.freebsd.org/D10599), but I use Weston directly from [my fork](https://github.com/myfreeweb/weston/commits/master).
It has a bit of extra stuff beyond FreeBSD support (fractional HiDPI scaling, bugfixes), and it's master, not a release.

How to use Weston:

- Install Mesa, wayland, libinput, etc (preferably from here, but a lot has been merged/enabled upstream recently)
- Install Weston from my fork
- Install [loginw](https://github.com/myfreeweb/loginw) (`cargo build --release`, `cp target/release/loginw /usr/local/bin/`)
- Make `loginw` suid root
- Make sure you have an `XDG_RUNTIME_DIR` in the environment
- Run `loginw weston`!

### Firefox

[kb:FirefoxSettings](https://unrelenting.technology/kb/FirefoxSettings)

## Current status

### Graphics Stack

- `graphics/mesa-dev`: alternative mesa port! Development version ([little fork](https://github.com/myfreeweb/mesa) with my BSD patches), everything built together, using Meson! Always includes GL, GLES, Vulkan (RADV, ANV), Gallium Nine, OpenCL (Clover), VDPAU, VAAPI.
	- to install and keep pkg happy without rebuilding everything, just `pkg add -f` over existing `mesa-libs/dri`
	- but if you want to do it properly, define `MESA_DRI_PORT=graphics/mesa-dev` and `MESA_LIBS_PORT=graphics/mesa-dev` in `make.conf` and rebuild dependent ports
		- [synth](https://github.com/jrmarino/synth) is the recommended port upgrade tool, it does try to fetch binary packages when a rebuild is not necessary
	- `multimedia/libva` has the glx part split off into `multimedia/libva-glx` to avoid circular dependency with mesa
- `graphics/colord`: build vapi [227134](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227134)
- `graphics/wayland-protocols`: 1.17

NOTE: ANV (Intel Vulkan) requires running the apps as root and might not work for complex applications.
RADV (Radeon Vulkan) with the `amdgpu` KMS/DRM driver works very well!
Tested on an AMD Polaris (RX 480) GPU.

### Input Stack

- `x11/libinput`:
  - update to 1.12.4
  - fix [touchpad dropping out](https://blog.grem.de/pages/t470s.html)
  - ref: [222905](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=222905)
- `devel/evemu`: update

### Audio Stack

- `audio/jack`: jack2 [jack2/pull/400](https://github.com/jackaudio/jack2/pull/400)

### Devtools & Languages

- `lang/luajit`: 2.1.0-beta3 (works on arm64) [225342](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225342)
- `devel/llvm70`, `devel/llvm60`, `devel/ccls`: disable assertions [233506](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233506)
- `devel/mull`: mutation test framework
- `textproc/pict`: pairwise test gen tool [231407](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=231407)
- `devel/include-what-you-use`: 0.11 [234429](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=234429)
- `graphics/shaderc`: google's glslang-based thing, needed for vulkan support in mpv

### Misc Libraries

- `devel/libgusb`: GObject libusb wrapper (w/ [PR #10](https://github.com/hughsie/libgusb/pull/10))
- `textproc/libucl`: 0.8.1 [233383](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233383)
- `audio/libechonest`: qt5 [226529](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=226529)
- `sysutils/libcpuid`: git master

### Games, Emulators & Related Stuff

- `emulators/mesen`: a NES emulator [227351](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227351)
- `emulators/yuzu`: a Switch emulator [228487](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=228487)
- `games/retroarch`: 1.7.5, WAYLAND option [227345](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227345)
- `games/dose-response`: [234269](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=234269)
- `games/vcmi`: open source reimplementation of Heroes of Might and Magic III! [221885](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=221885)
- `games/regoth`: [Gothic game engine reimplementation](https://github.com/REGoth-project/REGoth) (NOTE: [doesn't like mesa assertions which are ON in mesa-dev right now](https://bugs.archlinux.org/task/58218)) [227844](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227844)

### Desktop Apps

- `editors/libreoffice`: 6.1.2 [lwhsu/freebsd-ports-libreoffice](https://github.com/lwhsu/freebsd-ports-libreoffice), GTK3 by default
- `editors/abiword`: 3.0.2 [220975](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=220975)
- `graphics/inkscape`: git master version with GTK3, works on Wayland natively
- `graphics/rawtherapee`: disable mmap (to make performance over NFS not terrible), enable LTO
- `graphics/simple-scan`: GNOME scanning app (requires `libgusb`)
- `graphics/hdrmerge`: HDR merge tool (git master qt5)
- `mail/geary`: workaround for [Vala/gee array null termination bug](https://bugzilla.gnome.org/show_bug.cgi?id=794731)
- `audio/clementine-player`: git qt5 branch [234534](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=234534)
- `audio/sonata`: git master (GTK3)
- `security/gonepass`: 1Password vault reader [226706](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=226706)
- `math/nasc`: dual pane text calculator similar to Soulver
- `multimedia/gnome-twitch`: Twitch livestream player [224980](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=224980)
- `cad/solvespace`: git master (GTK3 HiDPI)
- `accessibility/redshift-wlr`: fork of redshift with wlr-gamma-control based Wayland backend
- `x11/kitty`: GPU accelerated terminal emulator (note: terminfo stuff)

### TODO

- `graphics/mypaint` and `graphics/libmypaint`: git master version, works on Wayland natively
- `graphics/gimp-app` (& `graphics/gegl3`, `x11/babl`): git gtk3-port-meson version, works on Wayland natively (opening pngs seems to crash the plugin but selecting Proceed in console works and the file gets loaded o_0) (gimp plugin ports are probably screwed!)
- `graphics/osg`: 3.6 [230442](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=230442)

## Other FreeBSD desktop resources

- [kb/FreeBSDDesktop](https://unrelenting.technology/kb/FreeBSDDesktop)
- [My dotfiles](https://github.com/myfreeweb/dotfiles) (mostly the `x11` folder)
- [A FreeBSD 11 Desktop How-to](https://cooltrainer.org/a-freebsd-desktop-howto/), not up to date with modern GPU stuff but very good for general desktop setup (printing, networking, etc.)
- [FreeBSD on the ThinkPad X240](https://unrelenting.technology/articles/freebsd-on-the-thinkpad-x240), my post that's mostly updated but still contains old stuff

## Other resources

- [1.5 Hour Spicy SUPER EUROBEAT Mix](https://www.youtube.com/watch?v=6ftCIfHwqtg)
