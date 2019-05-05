#! /bin/bash

echo "CPU information"
lscpu
echo
echo "Total Amount of free space"
free
echo
echo "Diagnostics Steps"
cat /proc/meminfo
echo
echo "Version"
cat /proc/version
echo
echo "USB information"
lsusb
echo
echo "PCI buses and devices in the system"
lspci
echo
echo "LSB information"
lsb_release -a
echo
echo "Block information"
lsblk
echo
echo "IP Address"
hostname -I # IP Address
echo
echo "MAC Address"
ifconfig
echo 
echo
echo "Files in last 30 minutes" 
find . -type f -amin -30
echo "recent"
ls -Art | tail -n 1
#recent files
echo
echo "Maximum size file"
find . -maxdepth 1 -type f -exec du -h {} + | sort --human-numeric-sort --reverse
#size of files
echo
echo "files having main and not malloc"
grep -lr 'main'* | xargs grep -L 'malloc'
