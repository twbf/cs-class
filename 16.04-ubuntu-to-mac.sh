#!/bin/sh
#1: Mac OS X Lion Theme, Icons and cursors:

sudo add-apt-repository ppa:noobslab/macbuntu

sudo apt-get update

sudo apt-get install macbuntu-os-icons-lts-v7

sudo apt-get install macbuntu-os-ithemes-lts-v7

#2: Slingscold (Alternative to Launchpad)

sudo add-apt-repository ppa:noobslab/macbuntu

sudo apt-get update

sudo apt-get install slingscold

#3: Replace 'Ubuntu Desktop' text with 'Mac' on the Panel:

cd && wget -O Mac.po http://drive.noobslab.com/data/Mac/ch...

cd /usr/share/locale/en/LC_MESSAGES; sudo msgfmt -o unity.mo ~/Mac.po;rm ~/Mac.po;cd

#4: Albert Spotlight (Alternative to Mac Spotlight)

sudo add-apt-repository ppa:noobslab/macbuntu

sudo apt-get update

sudo apt-get install albert

#5.Enter following commands to install Apple Logo:

wget -O launcher_bfb.png http://drive.noobslab.com/data/Mac/la... sudo mv launcher_bfb.png /usr/share/unity/icons/

gsettings set com.canonical.unity-greeter draw-grid false;exit

#6: Unity Tweak Tool to change Themes & Icons:

sudo apt-get install unity-tweak-tool

sudo apt-get install gnome-tweak-tool

#7: Install Monochrome icons for Libreoffice:

sudo apt-get install libreoffice-style-sifr

#8 dock

sudo apt-get install plank
sudo add-apt-repository ppa:noobslab/macbuntu
sudo apt-get update
sudo apt-get install macbuntu-os-plank-theme-lts-v7

#final

sudo apt-get install compizconfig-settings-manager
sudo apt-get install compiz-plugins compiz-plugins-extra
sudo apt-get install gconf-editor
