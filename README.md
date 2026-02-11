# <img src="./misc/dwm-repo.png" width="24"/> My build of [dwm](https://dwm.suckless.org) - Dynamic Window Manager
![screenshot](./misc/dwm.png)  
dwm 6.8

### Patches applied
1. [sticky](https://dwm.suckless.org/patches/sticky)
2. [movestack](https://dwm.suckless.org/patches/movestack)
3. [shiftview](https://lists.suckless.org/dev/att-7590/shiftview.c)
4. [tagshift](https://dwm.suckless.org/patches/tagshift)
5. [pertag](https://dwm.suckless.org/patches/pertag)
6. [bottomstack](https://dwm.suckless.org/patches/bottomstack)
7. [alwayscenter](https://dwm.suckless.org/patches/alwayscenter)
8. [fullgaps](https://dwm.suckless.org/patches/fullgaps)
9. [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen)
10. [focusmaster-return](https://dwm.suckless.org/patches/focusmaster)
11. [bar-less-padding](./patches/dwm-bar-less-padding.diff)
12. [bar-non-focus-status](./patches/dwm-bar-non-focus-status.diff)
13. [savefloats](./patches/dwm-savefloats-20181212-b69c870.diff)
14. [deck](https://dwm.suckless.org/patches/deck)
15. [sickyindicator](https://dwm.suckless.org/patches/stickyindicator)
16. [sickyindicator-bottom-solidbox](./patches/dwm-stickyindicator-bottom-solidbox-6.8.diff)
17. [focusonclick](https://dwm.suckless.org/patches/focusonclick)

---

## usage
Run `startx` with my [xinitrc](https://codeberg.org/unixchad/dotfiles/src/branch/master/.xinitrc).

## Software I Use in dwm
| | |
|:---|:---|
| scripting shell | dash |
| login shell | zsh |
| terminal multiplexer| [abduco](https://codeberg.org/unixchad/abduco) · [dvtm](https://codeberg.org/unixchad/dvtm) |
| terminal emulator | [st](https://codeberg.org/unixchad/st) |
| compositor | picom |
| status generator | [damblocks](https://codeberg.org/unixchad/damblocks) |
| output management | xrandr · autorandr |
| menu | [dmenu](https://codeberg.org/unixchad/dmenu) |
| notification | dunst |
| editor | neovim · vim |
| email | neomutt · isync |
| file manager | lf |
| music player | mpd · ncmpcpp |
| video player | mpv |
| image viewer | [nsxiv](https://codeberg.org/unixchad/nsxiv) |
| ebook reader | zathura |
| rss feeder | newsboat |
| calender & todo | calcurse · taskwarrior |
| virtualization | qemu · libvirt · virtmanager |
| security | cryptsetup · sbctl · gpg · firejail |
| browser | w3m · qutebrowser |
| download | curl · wget · transmission-cli · yt-dlp · httrack |
| file sharing | rsync · samba · android-file-transfer · qrtool |
| dotfiles manager | git · stow |
| clipboard | clipmenu |
| input method | fcitx5 |

## My Personal Scripts (supporting Wayland and Xorg)
| | |
|:---|:---|
| status bar | [damblocks](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/damblocks) |
| weather report | [wttr](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/wttr) |
| screenshot | [shoot](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/shoot) |
| screen capture | [capture](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/capture) |
| webcam | [camera](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/camera) |
| voice recorder | [record](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/record) |
| brightness | [bright](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/bright) |
| audio volume | [audio](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/audio) |
| audio sink | [speaker](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/speaker) |
| bookmark | [address](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/address) |
| clipboard | [clip](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/clip) |
| file opener | [rifle](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/rifle) · [gpg-rifle](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/gpg-rifle) · [url-rifle](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/url-rifle) |
| file previewer | [scope](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/scope) |
| mounting | [saddle](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/saddle) · [phone](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/phone) |
| gpg | [seal](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/seal) |
| mutt_oauth2 | [muttauth](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/muttauth) |
| shortcuts generator | [teleport-genesis](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/teleport-genesis) |
| qutebrowser | [userscripts](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/qutebrowser/) |
| xwayland-satellite | [xwl](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/xwl) |
| reload other scripts | [reload](https://codeberg.org/unixchad/dotfiles/src/branch/master/.local/bin/reload) |

# Software I use to create videos on X
| | |
|:---|:---|
| screen capture | ffmpeg |
| voice recording | pw-record · noise-suppression-for-voice |
| video editing | ffmpeg · mpv-cut · kdenlive |
| screenshots | maim · slop |
| thumbnails | imagemagick · gimp |
