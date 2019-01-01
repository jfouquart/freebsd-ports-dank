# freebsd-ports-dank

![dank meme pic](https://unrelentingtech.s3.dualstack.eu-west-1.amazonaws.com/dankbsd.jpg?1)

Welcome!

This fork of the FreeBSD Ports Collection adds more bleeding edge desktop-related patches.

**NOTE**: this is the new `lite`/`lite-gnome` branch, which is constantly rebased on top of `master`/`gnome-*`.

## Usage

- Make sure you have an up-to-date FreeBSD 13-CURRENT kernel and base
- Clone this repo into `/usr/ports` (if it's already managed by git, add this repo as a remote, fetch and checkout/merge)
- Build any ports you want :)

## Current status

- `devel/consolekit2`: drm/evdev support [D18754](https://reviews.freebsd.org/D18754)

### Graphics Stack

- `graphics/mesa-dev`: alternative mesa port! Development version ([little fork](https://github.com/myfreeweb/mesa) with my BSD patches), everything built together, using Meson! Always includes GL, GLES, Vulkan (RADV, ANV), Gallium Nine, OpenCL (Clover), VDPAU, VAAPI.
	- to install and keep pkg happy without rebuilding everything, just `pkg add -f` over existing `mesa-libs/dri`
	- but if you want to do it properly, define `MESA_DRI_PORT=graphics/mesa-dev` and `MESA_LIBS_PORT=graphics/mesa-dev` in `make.conf` and rebuild dependent ports
		- [synth](https://github.com/jrmarino/synth) is the recommended port upgrade tool, it does try to fetch binary packages when a rebuild is not necessary
	- `multimedia/libva` has the glx part split off into `multimedia/libva-glx` to avoid circular dependency with mesa
- `graphics/colord`: build vapi [227134](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227134)
- `graphics/cairo`: 1.16 [D18412](https://reviews.freebsd.org/D18412)

NOTE: ANV (Intel Vulkan) requires running the apps as root and might not work for complex applications.
RADV (Radeon Vulkan) with the `amdgpu` KMS/DRM driver works very well!
Tested on an AMD Polaris (RX 480) GPU.

### Input Stack

- `x11/libinput`:
  - fix [touchpad dropping out](https://blog.grem.de/pages/t470s.html)
- `devel/evemu`: update
- `devel/libudev-devd`: my patches applied: [connector hotplug](https://github.com/FreeBSDDesktop/libudev-devd/pull/7) and [device enumeration w/o `/dev/input/*` access rights](https://github.com/FreeBSDDesktop/libudev-devd/pull/8)
  - the former requires a drm-kmod patch: [#119](https://github.com/FreeBSDDesktop/kms-drm/pull/119)
  - the latter requires a kernel patch: [D18694](https://reviews.freebsd.org/D18694)

### Audio Stack

- `audio/jack`: jack2 [jack2/pull/400](https://github.com/jackaudio/jack2/pull/400)
- `audio/libcanberra-gtk3`: backport patch that prevents crashes on Wayland [235465](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=235465)

### Devtools & Languages

- `lang/luajit`: 2.1.0-beta3 (works on arm64) [225342](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225342)
- `devel/mull`: mutation test framework
- `devel/include-what-you-use`: 0.11 [234429](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=234429)
- `devel/glslang`: opt mode
- `devel/llvm[78]0`: clang-doc fix [D19068](https://reviews.freebsd.org/D19068)

### Misc Libraries

- `devel/libgusb`: GObject libusb wrapper (w/ [PR #10](https://github.com/hughsie/libgusb/pull/10))
- `textproc/libucl`: 0.8.1 [233383](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=233383)
- `sysutils/libcpuid`: git master
- `graphics/librsvg2-rust`: used everywhere
- `multimedia/gstreamer1-plugins`: backport xdg-shell support (prevents GL sink crash on Wayland compositors w/o wl-shell, i.e. prevents Pitivi crash on wlroots based compositors)

### Games, Emulators & Related Stuff

- `emulators/mesen`: a NES emulator [227351](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227351)
- `emulators/yuzu`: a Switch emulator [228487](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=228487)
- `games/retroarch`: 1.7.5, WAYLAND option [227345](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227345)
- `games/dose-response`: [234269](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=234269)
- `games/vcmi`: open source reimplementation of Heroes of Might and Magic III! [221885](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=221885)
- `games/regoth`: [Gothic game engine reimplementation](https://github.com/REGoth-project/REGoth) (NOTE: [doesn't like mesa assertions which are ON in mesa-dev right now](https://bugs.archlinux.org/task/58218)) [227844](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227844)

### Desktop Apps & Other Stuff

- `editors/libreoffice`: 6.1.2 [lwhsu/freebsd-ports-libreoffice](https://github.com/lwhsu/freebsd-ports-libreoffice), GTK3 by default
- `editors/abiword`: 3.0.2 [220975](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=220975)
- `graphics/inkscape`: git master version with GTK3, works on Wayland natively
- `graphics/rawtherapee`: disable mmap (to make performance over NFS not terrible), enable LTO
- `graphics/simple-scan`: GNOME scanning app (requires `libgusb`)
- `graphics/hdrmerge`: HDR merge tool (git master qt5)
- `mail/geary`: workaround for [Vala/gee array null termination bug](https://bugzilla.gnome.org/show_bug.cgi?id=794731)
- `audio/sonata`: git master (GTK3)
- `math/nasc`: dual pane text calculator similar to Soulver
- `cad/solvespace`: git master (GTK3 HiDPI)
- `accessibility/redshift-wlr`: fork of redshift with wlr-gamma-control based Wayland backend
- `x11/kitty`: GPU accelerated terminal emulator (note: terminfo stuff)
- `graphics/gifup`: gif maker
- `x11-im/fractal`: 4.0.0 (needs cairo upd and libhandy // use lite-gnome branch!)
- `graphics/mypaint`: 2.0.0-alpha.8 [235805](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=235805)

### TODO

- `graphics/mypaint` and `graphics/libmypaint`: git master version, works on Wayland natively
- `graphics/gimp-app` (& `graphics/gegl3`, `x11/babl`): git gtk3-port-meson version, works on Wayland natively (opening pngs seems to crash the plugin but selecting Proceed in console works and the file gets loaded o_0) (gimp plugin ports are probably screwed!)
- `graphics/osg`: 3.6 [230442](https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=230442)

## Other FreeBSD desktop resources

- [kb/FirefoxSettings](https://unrelenting.technology/kb/FirefoxSettings)
- [kb/FreeBSDDesktop](https://unrelenting.technology/kb/FreeBSDDesktop)
- [My dotfiles](https://github.com/myfreeweb/dotfiles) (mostly the `x11` folder)
- [A FreeBSD 11 Desktop How-to](https://cooltrainer.org/a-freebsd-desktop-howto/), not up to date with modern GPU stuff but very good for general desktop setup (printing, networking, etc.)
- [FreeBSD on the ThinkPad X240](https://unrelenting.technology/articles/freebsd-on-the-thinkpad-x240), my post that's mostly updated but still contains old stuff

## Other resources

- [1.5 Hour Spicy SUPER EUROBEAT Mix](https://www.youtube.com/watch?v=6ftCIfHwqtg)
